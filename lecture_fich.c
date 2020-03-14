#include <stdio.h>
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

void lecture(FILE *f, grid_ptr dosun_grille){
    int grid_dim;
    int nb_black_cell;
    int nb_group;
    int group_count = 1;
    int x,y;

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
    for(; group_count <= nb_group; group_count++){
        // Lecture des coordonnees des cases du meme group
        fscanf(f,"%d %d", &x, &y);
        // Mis a jour des cases
        dosun_grille->grille[x][y].ligne = x;
        dosun_grille->grille[x][y].colonne = y;
        dosun_grille->grille[x][y].case_type = C_NOIRE;
        dosun_grille->grille[x][y].groupe = group_count;
    }
}