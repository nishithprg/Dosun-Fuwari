#ifndef __LEC_FCH__
#define __LEC_FCH__

// Initialisation de la grille, exclus attribution de groupe
void creer_grille(grid_ptr dosun_grille, int grid_dim);

type_case init_case(int val);

// Lecture du fichier format grille et mis a jour de la grille
void lecture(FILE *f,grid_ptr dosun_grille, grid_sup* groupes, grid_sup* W_ball, grid_sup* B_ball);

#endif