/*
NIM     : 13522032
NAMA    : Tazkia Nizami
TANGGAL : 8 September 2023
FILE    : mjumlah.c
*/

#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"

int main()
{
    /*KAMUS*/
    ListStatik l1, l2, lHasil;
    int i, eks1, eks2, desimalList1, desimalList2, hasil, moder, tempHasil;

    /*ALGORITMA*/
    CreateListStatik(&l1);
    CreateListStatik(&l2);
    CreateListStatik(&lHasil);
    
    readList(&l1);
    readList(&l2);

    eks1 = 1;
    desimalList1 = 0; 
    desimalList2 = 0;
    for (i=listLength(l1)-1; i >= 0; i--) {
        desimalList1 += ELMT(l1, i)*eks1;
        eks1 *= 10;
    }
    eks2 = 1;
    for (i=listLength(l2)-1; i >= 0; i--) {
        desimalList2 += ELMT(l2, i)*eks2;
        eks2 *= 10;
    }
    
    hasil = desimalList1 + desimalList2;
    moder = 1;
    tempHasil = hasil;
    i = 0;
    while(tempHasil != 0) {
        moder *= 10;
        tempHasil/=10;
    }
    moder /= 10;
    while (moder != 0) {
        ELMT(lHasil, i) = hasil / moder %10;
        moder /= 10;
        i++;
    }

    printList(lHasil);
    printf("\n");
    return 0;
}
