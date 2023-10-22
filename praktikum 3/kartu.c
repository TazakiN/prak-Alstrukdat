#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdin.h"

int main()
{
    /*KAMUS*/
    ListDin tumpukanFinal, tumpukan1, tumpukan2;
    ElType kartu;
    IdxType idxkartu1, idxkartu2; 
    int M, N, i;

    /*ALGORITMA*/
    scanf("%d", &N);
    CreateListDin(&tumpukan1, N);
    for (i = 0; i < N; i++) {
        scanf("%d", &kartu);
        insertLast(&tumpukan1, kartu);
    }

    scanf("%d", &M);
    CreateListDin(&tumpukan2, M);
    for (i = 0; i < M; i++) {
        scanf("%d", &kartu);
        insertLast(&tumpukan2, kartu);
    }

    idxkartu1 = 0;
    idxkartu2 = 0;
    CreateListDin(&tumpukanFinal, M+N);
    while(idxkartu1 < NEFF(tumpukan1) || idxkartu2 < NEFF(tumpukan2)) {
        if (idxkartu1 == NEFF(tumpukan1)) {
            insertLast(&tumpukanFinal, ELMT(tumpukan2, idxkartu2));
            idxkartu2++;
        } else if (idxkartu2 == NEFF(tumpukan2)) {
            insertLast(&tumpukanFinal, ELMT(tumpukan1, idxkartu1));
            idxkartu1++;
        } else {
            if (ELMT(tumpukan1, idxkartu1) >= ELMT(tumpukan2, idxkartu2)) {
                insertLast(&tumpukanFinal, ELMT(tumpukan1, idxkartu1));
                idxkartu1++;
            } else {
                insertLast(&tumpukanFinal, ELMT(tumpukan2, idxkartu2));
                idxkartu2++;
            }
        }
    }
    
    printList(tumpukanFinal);
    printf("\n");
    return 0;
}
