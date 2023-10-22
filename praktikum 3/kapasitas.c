#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdin.h"
#include "math.h"

int main()
{
    /*KAMUS*/
    ListDin list;
    IdxType idxMax;
    ElType terdelete;
    int Q, i, tipe;
    /*ALGORITMA*/
    CreateListDin(&list, 0);
    scanf("%d", &Q);
    for (i = 0; i < Q; i++) {
        scanf("%d",&tipe);
        if(tipe==1){
            int x;
            scanf("%d",&x);
            if (CAPACITY(list) == 0) {
                expandList(&list, 1);
            }

            if (CAPACITY(list) > NEFF(list) ) {
                insertLast(&list, x);
            } else {
                expandList(&list, CAPACITY(list));
                insertLast(&list, x);
            }
        }else if(tipe==2){
            deleteLast(&list, &terdelete);
            if (CAPACITY(list) == 1) {
                shrinkList(&list, 1);
            }
            if (NEFF(list) <= round(CAPACITY(list)/2)) {
                shrinkList(&list, round(CAPACITY(list)/2));
            }
        } else {
            printf("%d ", CAPACITY(list));
            printList(list);
            printf("\n");
        }
    }
    return 0;
}
