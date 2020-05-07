#include <stdio.h>
#include <stdlib.h>
#include "prog1.h"
#include "lecture_fich.h"

void creer_grille(grid_ptr dosun_grille, int grid_dim){
    for(int i = 0; i < grid_dim; i++){
        for(int j = 0; j < grid_dim; j++){
            dosun_grille->grille[i][j].ligne = i;
            dosun_grille->grille[i][j].colonne = j;
            dosun_grille->grille[i][j].case_type = VIDE;
            // dosun_grille->grille[x][y].groupe = 0;
        }
    }
};

void init_array(grid_sup* array, int nb_groupes){
    array->longeur = nb_groupes;
    for(int i = 0; i < nb_groupes; i++){
        array->grille[i][0].longeur = 0;
    }
};

type_case init_case(int val){
    switch (val){
    case -1:
        return B_NOIRE;
    case 0:
        return VIDE;
    case 1:
        return B_BLANC;
    case 2:
        return B_DOUBLE;
    default:
        printf("Erreur de valeur de case. Valeur possible :\n -1 - bille noir,\n 0 - vide,\n 1 - ballon blanc,\n 2 - noir et blanc possible\n");
        exit(0);
    }
}

void ajouter_groupe(grid_sup* groupes, int x, int y, int num_ln){
    groupes->grille[num_ln][0].longeur++;
    for(int i = 1; i <= groupes->grille[num_ln][0].longeur; i++){
        if(i == groupes->grille[num_ln][i-1].longeur){
            groupes->grille[num_ln][i].ligne = x;
            groupes->grille[num_ln][i].colonne = y;
            groupes->grille[num_ln][i].longeur = groupes->grille[num_ln][i-1].longeur;    
        } else {
            groupes->grille[num_ln][i].longeur++;
        }
    };
};

void ajouter_blanc(grid_sup* W_ball, int x, int y, int num_ln){
    W_ball->grille[num_ln][0].longeur++;
    for(int i = 1; i <= W_ball->grille[num_ln][0].longeur; i++){
        if(i == W_ball->grille[num_ln][i-1].longeur){
            W_ball->grille[num_ln][i].ligne = x;
            W_ball->grille[num_ln][i].colonne = y;
            W_ball->grille[num_ln][i].longeur = W_ball->grille[num_ln][i-1].longeur;    
        } else {
            W_ball->grille[num_ln][i].longeur++;
        }
    };
};

void ajouter_noir(grid_sup* B_ball, int x, int y, int num_ln){
    B_ball->grille[num_ln][0].longeur++;
    for(int i = 1; i <= B_ball->grille[num_ln][0].longeur; i++){
        if(i == B_ball->grille[num_ln][i-1].longeur){
            B_ball->grille[num_ln][i].ligne = x;
            B_ball->grille[num_ln][i].colonne = y;
            B_ball->grille[num_ln][i].longeur = B_ball->grille[num_ln][i-1].longeur;    
        } else {
            B_ball->grille[num_ln][i].longeur++;
        }
    };
};

void add_bille(grid_sup* W_ball, grid_sup* B_ball,int x, int y, int num_ln, type_case bille){
    if(bille == B_BLANC){
        ajouter_blanc(W_ball,x,y,num_ln);
    } else if(bille == B_NOIRE){
        ajouter_blanc(B_ball,x,y,num_ln);
    }
};

void lecture(FILE *f,grid_ptr dosun_grille, grid_sup* groupes, grid_sup* W_ball, grid_sup* B_ball){
    int grid_dim;
    int nb_black_cell;
    int nb_group;
    int group_count = 1;
    int x,y,val;
    type_case valeur;
    char input_ligne[30];

    // Lecture dimension grille
    fscanf(f,"%d", &grid_dim);
    creer_grille(dosun_grille, grid_dim);

    // Lecture nombre de carre noir
    fscanf(f,"%d", &nb_black_cell);
    for(int i = 0; i < nb_black_cell; i++){
        // Lecture des coordonnees d'un carre noir
        fscanf(f,"%d %d", &x, &y);
        // Mis a jour des cases
        dosun_grille->grille[x][y].ligne = x;
        dosun_grille->grille[x][y].colonne = y;
        dosun_grille->grille[x][y].case_type = C_NOIRE;
        // dosun_grille->grille[x][y].groupe = 0;
    };

    // Lecture nombre de group
    fscanf(f,"%d", &nb_group);
    groupes->longeur = nb_group;
    for(; group_count <= nb_group; group_count++){
        fscanf(f, "%[^\n]", input_ligne);
        // Lecture des coordonnees des cases du meme group
        while(sscanf(input_ligne,"%d %d %d", &x, &y, &val) != EOF){
            valeur = init_case(val);

            // Mis a jour des cases de dosun_grille
            dosun_grille->grille[x][y].ligne = x;
            dosun_grille->grille[x][y].colonne = y;
            dosun_grille->grille[x][y].case_type = valeur;
            dosun_grille->grille[x][y].groupe = group_count;
            
            // Mis a jour des cases de groupes
            ajouter_groupe(groupes,x,y,group_count);
            // Mis a jour des cases des billes
            add_bille(W_ball,B_ball,x,y,group_count,valeur);
        }
    }
}