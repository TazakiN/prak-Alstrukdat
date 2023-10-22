#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdin.h"

int main()
{
    /*KAMUS*/
    ListDin list;
    IdxType idxMin;
    ElType max, min;
    int Q, i, j, tipe, C;
    /*ALGORITMA*/
    scanf("%d", &C);
    CreateListDin(&list, C);

    scanf("%d", &Q);
    for (i = 0; i < Q; i++) {
        scanf("%d",&tipe);
        if(tipe==1){
            int x;
            scanf("%d",&x);
            insertLast(&list, x);
            extremeValues(list, &max, &min);
            if (min < x) {
                do {
                    idxMin = indexOf(list, min);
                    for (j = idxMin; j<NEFF(list) - 1; j++) {
                        ELMT(list, j) = ELMT(list, j+1);
                    }
                    NEFF(list) -= 1;
                    extremeValues(list, &max, &min);
                } while (min < x);
            }
        }else{
            printf("%d\n", NEFF(list));
            printList(list);
            printf("\n");
        }
    }
}
