#ifndef __LEC_FCH__
#define __LEC_FCH__

// Initialisation de la grille, exclus attribution de groupe
void creer_grille(grid_ptr dosun_grille, int grid_dim);

// Lecture du fichier format grille et mis a jour de la grille

void lecture(FILE *f,grid_ptr dosun_grille);

#endif