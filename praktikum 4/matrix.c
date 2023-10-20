#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include <math.h>
#include "matrix.h"

void createMatrix(int nRows, int nCols, Matrix *m) {
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

boolean isMatrixIdxValid(int i, int j){
    return (0 <= i && i < ROW_CAP ) && (0 <= j && j < COL_CAP);
}

IdxType getLastIdxRow(Matrix m) {
    return ROW_EFF(m) - 1;
}

IdxType getLastIdxCol(Matrix m) {
    return COL_EFF(m) - 1;
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j) {
    return (0 <= i && i < ROW_EFF(m) ) && (0 <= j && j < COL_EFF(m));
}

ElType getElmtDiagonal(Matrix m, IdxType i) {
    return ELMT(m, i, i);
}

void copyMatrix(Matrix mIn, Matrix *mOut) {
    int i, j;
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);

    for (i = 0; i < ROW_EFF(mIn); i++) {
        for (j = 0; j < COL_EFF(mIn); j++) {
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
}

void readMatrix(Matrix *m, int nRow, int nCol){
    /*KAMUS*/
    int i, j;
    /*ALGORITMA*/
    createMatrix(ROW_EFF(*m), COL_EFF(*m), m);
    for (i = 0; i < ROW_EFF(*m); i++) {
        for (j = 0; j < COL_EFF(*m); j++) {
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}

void displayMatrix(Matrix m) {
    /*KAMUS*/
    int i, j;
    /*ALGORITMA*/
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            printf("%d", ELMT(m, i, j));
            if (j != COL_EFF(m) - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

Matrix addMatrix(Matrix m1, Matrix m2) {
    /*KAMUS*/
    int i,j;
    Matrix newM;
    /*ALGORITMA*/
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &newM);
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            ELMT(newM, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return newM;
}

Matrix subtractMatrix(Matrix m1, Matrix m2){
    /*KAMUS*/
    int i,j;
    Matrix newM;
    /*ALGORITMA*/
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &newM);
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            ELMT(newM, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return newM;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2) {
    /*KAMUS*/
    int i,j, k;
    Matrix newM;
    /*ALGORITMA*/
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &newM);
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            ELMT(newM, i, j) = 0;
        }
    }

    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            for (k = 0; k < ROW_EFF(m1); k++) {
                ELMT(newM, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
        }
    }
    return newM;
}

Matrix multiplyMatrixWithMod(Matrix m1,Matrix m2,int mod){
    /*KAMUS*/
    int i,j, k;
    Matrix newM;
    /*ALGORITMA*/
    newM = multiplyMatrix(m1, m2);
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            ELMT(newM, i, j) %= mod;
        }
    }

    return newM;
}

Matrix multiplyByConst(Matrix m, ElType x) {
    /*KAMUS*/
    int i,j;
    Matrix newM;
    /*ALGORITMA*/
    createMatrix(ROW_EFF(m), COL_EFF(m), &newM);
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            ELMT(newM, i, j) = ELMT(m, i, j) * x;
        }
    }
    return newM;
}

void pMultiplyByConst(Matrix *m, ElType k) {
    /*KAMUS*/
    int i,j;
    /*ALGORITMA*/
    for (i = 0; i < ROW_EFF(*m); i++) {
        for (j = 0; j < COL_EFF(*m); j++) {
            ELMT(*m, i, j) = ELMT(*m, i, j) * k;
        }
    }
}

boolean isMatrixEqual(Matrix m1, Matrix m2){
    /*KAMUS*/
    int i,j;
    boolean result = true;
    /*ALGORITMA*/
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            if (ELMT(m1, i, j) != ELMT(m2, i, j)) {
                result = false;
            }
        }
    }
    return result;
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2) {
    return !(isMatrixEqual(m1, m2));
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2) {
    return (ROW_EFF(m1) == ROW_EFF(m2)) && (COL_EFF(m1) == COL_EFF(m2));
}

int countElmt(Matrix m) {
    /*KAMUS*/
    /*ALGORITMA*/
    return ROW_EFF(m) * COL_EFF(m);
}

boolean isSquare(Matrix m){
    return ROW_EFF(m) == COL_EFF(m);
}

boolean isSymmetric(Matrix m) {
    /*KAMUS*/
    int i,j;
    boolean result = true;
    /*ALGORITMA*/
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            if (ELMT(m, i, j) != ELMT(m, j, i)) {
                result = false;
            }
        }
    }
    return isSquare(m) && result;
}

boolean isIdentity(Matrix m) {
    /*KAMUS*/
    int i,j;
    boolean result = true;
    /*ALGORITMA*/
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            if (i == j) {
                if (ELMT(m, i, j) != 1) {
                    result = false;
                }
            } else {
                if (ELMT(m, i, j) != 0) {
                    result = false;
                }
            }
        }
    }
    return isSquare(m) && result;
}

boolean isSparse(Matrix m){
    /*KAMUS*/
    int i,j;
    int result = 0;
    /*ALGORITMA*/
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            if (ELMT(m, i, j) != 0){
                result += 1;
            }
        }
    }
    
    if (result > 0.05 * countElmt(m)) {
        return false;
    } else {
        return true;
    }
}

Matrix negation(Matrix m) {
    /*KAMUS*/
    int i,j;
    Matrix newM;
    /*ALGORITMA*/
    createMatrix(ROW_EFF(m), COL_EFF(m), &newM);
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            ELMT(newM, i, j) = ELMT(m, i, j) * (-1);
        }
    }
    return newM;
}

void pNegation(Matrix *m) {
    /*KAMUS*/
    int i,j;
    /*ALGORITMA*/
    for (i = 0; i < ROW_EFF(*m); i++) {
        for (j = 0; j < COL_EFF(*m); j++) {
            ELMT(*m, i, j) = ELMT(*m, i, j) * (-1);
        }
    }
}

float determinant(Matrix m){
    /*KAMUS*/
    float result = 0.0;
    int sign = 1;
    int i, j, k;

    /*ALGORITMA*/
    if (ROW_EFF(m) == 1) {
        return ELMT(m, 0, 0);
    } else if (ROW_EFF(m) == 2){
        return ((ELMT(m, 0, 0) * ELMT(m, 1, 1)) - (ELMT(m, 0, 1) * ELMT(m, 1, 0)));
    } else {
        Matrix kofaktor;
        for (i = 0; i < COL_EFF(m); i++) {
            createMatrix(ROW_EFF(m)-1, COL_EFF(m)-1, &kofaktor);
            //isi elemen matrix kofaktor
            for (j = 1; j < ROW_EFF(m); j++) {
                for (k = 0; k < COL_EFF(m) - 1; k++) {
                    if (k == i) {
                        continue;
                    } else if (k > i) {
                        ELMT(kofaktor, j - 1, k - 1) = ELMT(m, j, k);
                    } else {
                        ELMT(kofaktor, j - 1, k) = ELMT(m, j, k);       
                    }
                }
            }
            result += sign * ELMT(m, 0, i) * determinant(kofaktor);
            sign = -sign;
        }
    }

    return result;
}

Matrix transpose(Matrix m) {
    /*KAMUS*/
    int i,j;
    Matrix newM;
    /*ALGORITMA*/
    createMatrix(ROW_EFF(m), COL_EFF(m), &newM);
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = i; j < COL_EFF(m); j++) {
            ELMT(newM, i, j) = ELMT(m, j, i);
            ELMT(newM, j, i) = ELMT(m, i, j);
        }
    }
    return newM; 
}

void pTranspose(Matrix *m) {
    /*KAMUS*/
    int i,j;
    ElType temp;
    /*ALGORITMA*/
    for (i = 0; i < ROW_EFF(*m); i++) {
        for (j = i; j < COL_EFF(*m); j++) {
            temp = ELMT(*m, i, j);
            ELMT(*m, i, j) = ELMT(*m, j, i);
            ELMT(*m, j, i) = temp;
        }
    }
}