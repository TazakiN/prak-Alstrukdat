/*
NIM         : 13522032
NAMA        : Tazkia Nizami
Praktikum   : 3 
FILE        : listdin.c 
*/

#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
#include "listdin.h"

void CreateListDin(ListDin *l, int capacity) {
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
    BUFFER(*l) = (ElType*) malloc (capacity * sizeof(ElType)); 
}

void dealocateList(ListDin *l) {
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
    free(BUFFER(*l));
}

int listLength(ListDin l) {
    return NEFF(l);
}

IdxType getFirstIdx(ListDin l) {
    return IDX_MIN;
}

IdxType getLastIdx(ListDin l) {
    return NEFF(l)-1;
}

boolean isIdxValid(ListDin l, IdxType i) {
    return (i >= IDX_MIN && i < CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i) {
    return (i >= IDX_MIN && i < NEFF(l));
}

boolean isEmpty(ListDin l) {
    return NEFF(l) == 0;
}

boolean isFull(ListDin l) {
    return NEFF(l) == CAPACITY(l);
}

void readList(ListDin *l) {
    /*KAMUS*/
    ElType temp;
    int i, N;
    /*ALGORITMA*/
    do {
        scanf("%d", &N);
    } while (N < 0 || N > CAPACITY(*l));

    NEFF(*l) = N;

    for (i = 0; i <= CAPACITY(*l); i++) {
        scanf("%d", &temp);
        ELMT(*l, i) = temp;
    }
}

void printList(ListDin l) {
    /*KAMUS*/
    IdxType i;
    /*ALGORITMA*/
    printf("[");
    if (NEFF(l) != 0) {
        printf("%d", ELMT(l, 0));
        for (i = 1; i < NEFF(l); i++) {
            printf(",%d", ELMT(l, i));
        }
    }
    printf("]");
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
    /*KAMUS*/
    ListDin newList;
    int i; 
    /*ALGORITMA*/
    CreateListDin(&newList, NEFF(l1));
    NEFF(newList) = NEFF(l1);

    if (plus) {
        for (i = 0; i < NEFF(newList); i++) {
            ELMT(newList, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    } else {
        for (i = 0; i < NEFF(newList); i++) {
            ELMT(newList, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }

    return newList;
}

boolean isListEqual(ListDin l1, ListDin l2) {
    /*KAMUS*/
    boolean result = true;
    IdxType i ;
    /*ALGORITMA*/
    if (NEFF(l1) == NEFF(l2)) {
        for (i = 0; i < NEFF(l1); i++) {
            if (ELMT(l1,i) != ELMT(l2,i)) {
                result = false;
            }
        }
        return result;
    } else {
        return false;
    }
}

IdxType indexOf(ListDin l, ElType val) {
    /*KAMUS*/
    IdxType result, i; 

    /*ALGORITMA*/
    result = IDX_UNDEF;
    for (i = 0; i < NEFF(l); i++) {
        if (ELMT(l,i) == val) {
            return i;
        }
    }
    return result;
}

void extremeValues(ListDin l, ElType *max, ElType *min) {
    /*KAMUS*/
    IdxType i;
    /*ALGORITMA*/
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);

    for (i=1; i < NEFF(l); i++) {
        if (ELMT(l, i) > *max) {
            *max = ELMT(l,i);
        }
        if (ELMT(l, i) < *min) {
            *min = ELMT(l,i);
        }
    }
}

void copyList(ListDin lIn, ListDin *lOut) {
    /*KAMUS*/
    IdxType i;
    /*ALGORITMA*/
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);

    for (i = 0; i < NEFF(*lOut); i++) {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

ElType sumList(ListDin l) {
    /*KAMUS*/
    ElType result = 0;
    IdxType i;
    /*ALGORITMA*/
    for (i = 0; i < NEFF(l); i++) {
        result += ELMT(l,i);
    }
    return result;
}

int countVal(ListDin l, ElType val) {
    /*KAMUS*/
    int result = 0;
    IdxType i;
    /*ALGORITMA*/
    for (i = 0; i < NEFF(l); i++) {
        if (ELMT(l, i) == val) {
            result++;
        }
    }
    return result;
}

void sort(ListDin *l, boolean asc) {
    /*KAMUS*/
    IdxType i, j;
    ElType temp;
    /*ALGORITMA*/
    if (asc) {
        for (i = 0; i < NEFF(*l); i++) {
            for (j = i+1; j < NEFF(*l); j++) {
                if (ELMT(*l, i) > ELMT(*l, j)) {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            }
        }
    } else {
        for (i = 0; i < NEFF(*l); i++) {
            for (j = i+1; j < NEFF(*l); j++) {
                if (ELMT(*l, i) < ELMT(*l, j)) {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            }
        }
    }
}

void insertLast(ListDin *l, ElType val) {
    /*KAMUS*/
    /*ALGORITMA*/
    ELMT(*l, NEFF(*l)) = val;
    NEFF(*l) += 1; 
}

void deleteLast(ListDin *l, ElType *val) {
    /*KAMUS*/
    /*ALGORITMA*/
    *val = ELMT(*l, NEFF(*l)-1);
    NEFF(*l) -= 1;
}

void expandList(ListDin *l, int num) {
    /*KAMUS*/
    ListDin tempList;
    IdxType i;
    /*ALGORITMA*/
    CreateListDin(&tempList, CAPACITY(*l) + num);
    NEFF(tempList) = NEFF(*l);

    for (i = 0; i < NEFF(tempList); i++) {
        ELMT(tempList, i) = ELMT(*l, i);
    }
    dealocateList(l);
    BUFFER(*l) = BUFFER(tempList);
    CAPACITY(*l) = CAPACITY(tempList);
    NEFF(*l) = NEFF(tempList);    
}

void shrinkList(ListDin *l, int num) {
    /*KAMUS*/
    ListDin tempList;
    IdxType i;
    /*ALGORITMA*/
    CreateListDin(&tempList, CAPACITY(*l) - num);
    NEFF(tempList) = NEFF(*l);

    for (i = 0; i < NEFF(tempList); i++) {
        ELMT(tempList, i) = ELMT(*l, i);
    }
    dealocateList(l);
    BUFFER(*l) = BUFFER(tempList);
    CAPACITY(*l) = CAPACITY(tempList);
    NEFF(*l) = NEFF(tempList); 
}

void compressList(ListDin *l) {
     /*KAMUS*/
    ListDin tempList;
    IdxType i;
    /*ALGORITMA*/
    CreateListDin(&tempList, NEFF(*l));
    NEFF(tempList) = NEFF(*l);

    for (i = 0; i < NEFF(tempList); i++) {
        ELMT(tempList, i) = ELMT(*l, i);
    }
    dealocateList(l);
    BUFFER(*l) = BUFFER(tempList);
    CAPACITY(*l) = CAPACITY(tempList);
    NEFF(*l) = NEFF(tempList); 
}