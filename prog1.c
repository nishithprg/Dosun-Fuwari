#include <stdio.h>
#include <stdlib.h>
#include "prog1.h"
#include "lecture_fich.h"

int main(int argc, char * argv[]){
    FILE *f;
    grid dosun_grid;
    grid_sup groupes;
    grid_sup W_ball;
    grid_sup B_ball;
    f = fopen(argv[1], "r");
    lecture(f, &dosun_grid, &groupes, &W_ball, &B_ball);
    fclose(f);
    return 0;
}
