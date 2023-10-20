#include <stdio.h>
#include "boolean.h"
#include "matrix.h"

int main(int argc, char const *argv[])
{
    /*KAMUS*/
    Matrix mat;
    int i, j;
    int resultHitam = 0;
    int resultPutih = 0;
    /*ALGORITMA*/
    createMatrix(8, 8, &mat);
    readMatrix(&mat, 8, 8);
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (ELMT(mat, i, j) == 1) {
                if ((i + j)%2 == 0) {
                    resultHitam += 1;
                } else {
                    resultPutih += 1;
                }
            }
        }
    }
    printf ("%d %d\n", resultHitam, resultPutih);
    return 0;
}
