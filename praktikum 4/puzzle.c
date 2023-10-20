#include "matrix.h"
#include "boolean.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    /*KAMUS*/
    Matrix pazel, potongan;
    int rowPazel, colPazel;
    int rowPotongan, colPotongan;
    int i, K, m, n, p, q;
    boolean result = true;
    /*ALGORITMA*/
    scanf("%d %d", &rowPazel, &colPazel);
    readMatrix(&pazel, rowPazel, colPazel);
    scanf("%d", &K);
    for (i = 0; i < K; i++) {
        scanf("%d %d", &rowPotongan, &colPotongan);
        readMatrix(&potongan, rowPotongan, colPotongan);
        for (m = 0; m < rowPazel; m++) {
            for (n = 0; n < colPazel; n++) {
                if (ELMT(pazel, m, n) == ELMT(potongan, 0, 0)) {
                    for (p = 0; p < rowPotongan; p++) {
                        for (q = 0; q < colPotongan; q++) {
                            if (ELMT(pazel, m +p, n +q) != ELMT(potongan, p , q)) {
                                result = false;
                            }
                        }
                    }
                }
            }
        }
    }
    if (result) {
        printf("Puzzle dapat diselesaikan.\n");
    } else {
        printf("Puzzle tidak dapat diselesaikan.\n");
    }
    return 0;
}
