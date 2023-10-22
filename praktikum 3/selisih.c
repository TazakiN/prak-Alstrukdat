#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdin.h"

int main()
{
    /*KAMUS*/
    ListDin list;
    IdxType idxMax;
    int max, min;
    /*ALGORITMA*/
    CreateListDin(&list, 100);
    readList(&list);
    
    extremeValues(list, &max, &min);

    idxMax = indexOf(list, max);
    ELMT(list, idxMax) += 1;
    extremeValues(list, &max, &min);
    printf("%d\n", max - min);
    return 0;
}
