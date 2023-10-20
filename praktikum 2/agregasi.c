/*
NIM     : 13522032
NAMA    : Tazkia Nizami
TANGGAL : 8 September 2023
FILE    : agregasi.c
*/

#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"

int main()
{
    /*KAMUS*/
    ListStatik l;
    int x, i, max, min;
    float mean = 0.00;
    
    /*ALGORITMA*/
    CreateListStatik(&l);
    readList(&l);
    scanf("%d", &x);
    
    sortList(&l, 1);
    printList(l); printf("\n");

    for (i = 0; i < listLength(l); i++) {
        mean += ELMT(l, i);
    }
    mean /= listLength(l);
    printf("Average: %.2f\n", mean);

    int posisi = indexOf(l, x);
    if (posisi != IDX_UNDEF) {
        printf("%d\n", posisi);
    } else {
        printf ("%d tidak ada\n", x);
    }
    
    extremeValues(l, &max, &min);
    if (max == x) {
        printf("X maksimum\n");
    }
    if (min == x) {
        printf("X minimum\n");
    }
    if (listLength(l)%2 == 0) {
        if (x == ELMT(l, listLength(l)/2 - 1)) {
            printf("X median\n");
        }       
    } else {
        if (x == ELMT(l, listLength(l)/2)) {
            printf("X median\n");
        }
    }
    return 0;
}
