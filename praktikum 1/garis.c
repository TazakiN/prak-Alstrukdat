#include <stdio.h>
#include "garis.h"

void CreateGaris (GARIS * L, POINT P1, POINT P2){
    PAwal(*L)=P1;
    PAkhir(*L)=P2;
}

void BacaGARIS (GARIS * L){
    POINT p1,p2;
    do{
        BacaPOINT(&p1);BacaPOINT(&p2);
        if(EQ(p1,p2))printf("Garis tidak valid\n");
    }while(EQ(p1,p2));
    CreateGaris(L,p1,p2);
}

void TulisGARIS (GARIS L){
    printf("(");TulisPOINT(PAwal(L));
    printf(",");TulisPOINT(PAkhir(L));
    printf(")");
}

float PanjangGARIS (GARIS L){
    return Panjang(PAwal(L),PAkhir(L));
}

float Gradien (GARIS L){
    return ((Ordinat(PAkhir(L))-Ordinat(PAwal(L)))/(Absis(PAkhir(L))-Absis(PAwal(L))));
}

void GeserGARIS (GARIS * L, float deltaX, float deltaY){
    Geser(&PAkhir(*L),deltaX,deltaY);
    Geser(&PAwal(*L),deltaX,deltaY);
}

boolean IsTegakLurus (GARIS L1, GARIS L2){
    return (Gradien(L1)*Gradien(L2)==-1);
}

boolean IsSejajar (GARIS L1, GARIS L2){
    return (Gradien(L1)==Gradien(L2));
}

float JarakGARIS (GARIS L, POINT P) {
    /*KAMUS*/
    float a, b, c, x, y;
    a = (Ordinat(PAwal(L)) - Ordinat(PAkhir(L)));
    b = -(Absis(PAwal(L)) - Absis(PAkhir(L)));
    c = ((Absis(PAwal(L)) - Absis(PAkhir(L))) * Ordinat(PAkhir(L))) - ((Ordinat(PAwal(L)) - Ordinat(PAkhir(L))) * Absis(PAkhir(L)));
    x = Absis(P);
    y = Ordinat(P);
    /*ALGORITMA*/
    return fabs(a * x + b * y + c) / sqrtf(a*a + b*b);
}

boolean IsPointMemenuhiGaris (GARIS L, POINT P) {
    /*KAMUS*/
    float a, b, c, x, y;
    a = (Ordinat(PAwal(L)) - Ordinat(PAkhir(L)));
    b = -(Absis(PAwal(L)) - Absis(PAkhir(L)));
    c = ((Absis(PAwal(L)) - Absis(PAkhir(L))) * Ordinat(PAkhir(L))) - ((Ordinat(PAwal(L)) - Ordinat(PAkhir(L))) * Absis(PAkhir(L)));
    x = Absis(P);
    y = Ordinat(P);
    /*ALGORITMA*/
    return a*x + b*y + c == 0;
}