#include <stdio.h>
#include <stdlib.h>
#include "prog1.h"
#include "lecture_fich.h"

int main(int argc, char * argv[]){
    FILE *f;
    grid dosun_grid;
    f = fopen(argv[1], "r");
    lecture(f, &dosun_grid);
    fclose(f);
    return 0;
}
