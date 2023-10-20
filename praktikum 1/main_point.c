#include <stdio.h>
#include "point.h"

int main() {
    POINT P1, P2, P3;

    printf("Masukkan koordinat P1:\n");
    BacaPOINT(&P1);
    printf("Koordinat P1: ");
    TulisPOINT(P1);
    printf("\n");

    printf("Masukkan koordinat P2:\n");
    BacaPOINT(&P2);
    printf("Koordinat P2: ");
    TulisPOINT(P2);
    printf("\n");

    // Pengujian operasi relasional
    if (EQ(P1, P2)) {
        printf("P1 sama dengan P2\n");
    } else {
        printf("P1 tidak sama dengan P2\n");
    }

    // Pengujian operasi penentuan posisi
    if (IsOrigin(P1)) {
        printf("P1 adalah titik origin\n");
    } else {
        printf("P1 bukan titik origin\n");
    }

    if (IsOnSbX(P1)) {
        printf("P1 terletak pada sumbu X\n");
    } else {
        printf("P1 tidak terletak pada sumbu X\n");
    }

    if (IsOnSbY(P1)) {
        printf("P1 terletak pada sumbu Y\n");
    } else {
        printf("P1 tidak terletak pada sumbu Y\n");
    }

    printf("Kuadran P1: %d\n", Kuadran(P1));

    // Pengujian operasi terhadap POINT
    P3 = NextX(P1);
    printf("NextX dari P1: ");
    TulisPOINT(P3);
    printf("\n");

    P3 = NextY(P1);
    printf("NextY dari P1: ");
    TulisPOINT(P3);
    printf("\n");

    P3 = PlusDelta(P1, 2.0, 3.0);
    printf("P1 + Delta(2.0, 3.0): ");
    TulisPOINT(P3);
    printf("\n");

    P3 = MirrorOf(P1, 1); // Cerminkan terhadap sumbu X
    printf("Cerminkan P1 terhadap sumbu X: ");
    TulisPOINT(P3);
    printf("\n");

    printf("Jarak P1 ke origin: %.2f\n", Jarak0(P1));
    printf("Panjang garis P1 dan P2: %.2f\n", Panjang(P1, P2));

    // Pengujian perubahan terhadap POINT
    Geser(&P1, 1.0, -1.0);
    printf("Geser P1 sebesar (1.0, -1.0): ");
    TulisPOINT(P1);
    printf("\n");

    GeserKeSbX(&P2);
    printf("Geser P2 ke sumbu X: ");
    TulisPOINT(P2);
    printf("\n");

    GeserKeSbY(&P1);
    printf("Geser P1 ke sumbu Y: ");
    TulisPOINT(P1);
    printf("\n");

    Mirror(&P2, 0); // Cerminkan terhadap sumbu Y
    printf("Cerminkan P2 terhadap sumbu Y: ");
    TulisPOINT(P2);
    printf("\n");

    Putar(&P1, 90.0);
    printf("Putar P1 sebesar 90 derajat: ");
    TulisPOINT(P1);
    printf("\n");

    PersamaanLinearDuaVariabel(P1, P2);

    return 0;
}
