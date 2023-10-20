/*
NIM     : 13522032
NAMA    : Tazkia Nizami
TANGGAL : 8 September 2023
FILE    : merge.c
*/

#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"

int main()
{
    /*KAMUS*/
    ListStatik l1, l2, l3;
    int i;

    /*ALGORITMA*/
    CreateListStatik(&l1);
    CreateListStatik(&l2);
    CreateListStatik(&l3);

    readList(&l1); 
    readList(&l2); 

    for (i = 0; i<listLength(l1); i++) {
        ELMT(l3, i) = ELMT(l1, i);
    }
    for (i = listLength(l1); i < listLength(l1) + listLength(l2); i++) {
        ELMT(l3,i) = ELMT(l2, i - listLength(l1));
    }
    sortList(&l3, true);
    printList(l3);
    printf("\n");
    return 0;
}
