#include "listlinier.h"
#include "boolean.h"
#include <stdio.h>

boolean findX (List l, int X) {
    /*KAMUS LOKAL*/
    Address p;
    /*ALGORITMA*/
    p = l;
    while (p != NULL) {
        if (INFO(p) == X) {
            return true;
        }
        p = NEXT(p);
    }
    return false;
}

int main(int argc, char const *argv[])
{
 
    /* KAMUS */
    List l;
    int Q, iter, ukuranCache, maksCache, val, idxVal, hit, miss, buang;
    /* ALGORITMA */

    // inisiasi nilai
    CreateList(&l);
    scanf("%d", &maksCache);
    scanf("%d", &Q);
    ukuranCache = 0;
    hit = 0; miss = 0;

    for (iter = 0; iter < Q; iter++) {
        scanf("%d", &val);
        if (findX(l, val)) { // kalo nilainya ada di cache
            idxVal = indexOf(l, val); // cari indexnya
            deleteAt(&l, idxVal, &buang); // hapus dari cache
            insertFirst(&l, val); // masukin lagi di awal

            printf("hit ");
            hit++;
            displayList(l);
            printf("\n");

        } else { // kalo gaada di cache
            if (ukuranCache < maksCache) {
                insertFirst(&l, val);
                ukuranCache++;
            } else {
                if (ukuranCache != 0) {
                    deleteLast(&l, &buang);
                    insertFirst(&l, val);
                }
            }
            printf("miss ");
            miss++;
            displayList(l);
            printf("\n");
        }
    }

    if (hit+miss != 0) {
        printf("hit ratio: %.2f\n", (float) hit / (hit+miss));
    } else {
        printf("hit ratio: 0.00\n");
    }

    return 0;
}
