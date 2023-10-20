#include <stdio.h>
#include "matrix.h"

int main() {
    Matrix m1, m2, result;

    // Membuat matriks m1 dengan ukuran 3x3
    createMatrix(3, 3, &m1);
    printf("Matriks m1 (3x3):\n");
    readMatrix(&m1, 3, 3);
    displayMatrix(m1);

    // Membuat matriks m2 dengan ukuran 3x3
    createMatrix(3, 3, &m2);
    printf("\nMatriks m2 (3x3):\n");
    readMatrix(&m2, 3, 3);
    displayMatrix(m2);

    // Menggunakan beberapa fungsi lainnya
    printf("\nInformasi matriks m1:\n");
    printf("Jumlah elemen: %d\n", countElmt(m1));
    printf("Determinan m1: %f\n", determinant(m1));
    printf("Is Square m1: %s\n", isSquare(m1) ? "true" : "false");
    printf("Is Symmetric m1: %s\n", isSymmetric(m1) ? "true" : "false");
    printf("Is Identity m1: %s\n", isIdentity(m1) ? "true" : "false");
    printf("Is Sparse m1: %s\n", isSparse(m1) ? "true" : "false");

    // Menambahkan dan mengurangkan dua matriks
    result = addMatrix(m1, m2);
    printf("\nHasil penjumlahan m1 + m2:\n");
    displayMatrix(result);

    result = subtractMatrix(m1, m2);
    printf("\nHasil pengurangan m1 - m2:\n");
    displayMatrix(result);

    // Melakukan perkalian matriks
    result = multiplyMatrix(m1, m2);
    printf("\nHasil perkalian m1 * m2:\n");
    displayMatrix(result);

    // Melakukan perkalian matriks dengan mod
    result = multiplyMatrixWithMod(m1, m2, 10);
    printf("\nHasil perkalian m1 * m2 mod 10:\n");
    displayMatrix(result);

    // Melakukan perkalian matriks dengan konstanta
    ElType constant = 2;
    result = multiplyByConst(m1, constant);
    printf("\nHasil perkalian m1 dengan konstanta %d:\n", constant);
    displayMatrix(result);

    // Menghitung determinan matriks m1
    float det = determinant(m1);
    printf("\nDeterminan m1: %f\n", det);

    // Melakukan negasi matriks
    result = negation(m1);
    printf("\nNegasi m1:\n");
    displayMatrix(result);

    // Melakukan transpose matriks
    result = transpose(m1);
    printf("\nTranspose m1:\n");
    displayMatrix(result);

    return 0;
}
