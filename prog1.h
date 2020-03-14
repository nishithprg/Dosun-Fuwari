#ifndef __PROG_1__
#define __PROG_1__

typedef enum {VIDE, C_NOIRE, B_BLANC, B_NOIRE} type_case;

#define L_MAX 250

typedef struct {
    int ligne;
    int colonne;
    type_case case_type;
    int groupe;
} dosun;

typedef struct {
    dosun grille[L_MAX][L_MAX];
} grid;

typedef grid* grid_ptr;

typedef struct {
    int ligne;
    int colonne;
} case_coordinate;

typedef struct {
    case_coordinate tab[L_MAX];
    int longueur;
 } Pile;
#endif
