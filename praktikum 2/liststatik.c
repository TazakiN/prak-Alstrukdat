#include "liststatik.h"
#include "boolean.h"
#include <stdio.h>

void CreateListStatik(ListStatik *l) {
    /*ALGORITMA*/
    for(IdxType i = IDX_MIN; i < CAPACITY; i++) {
        ELMT(*l, i) = MARK;
    }
}

int listLength(ListStatik l) {
    /*KAMUS*/
    int result = 0;
    /*ALGORITMA*/
    while (ELMT(l, result) != MARK) {
        result++;
    }
    return result;
}

IdxType getFirstIdx(ListStatik l) {
    /*KAMUS*/
    /*ALGORITMA*/
    return IDX_MIN;
}

IdxType getLastIdx(ListStatik l) {
    /*KAMUS*/
    IdxType result = getFirstIdx(l);
    /*ALGORITMA*/
    while (ELMT(l, result) != MARK) {
        return result++;
    }
    return result-1;
}

boolean isIdxValid(ListStatik l, IdxType i){
    /*ALGORITMA*/
    return (IDX_MIN <= i && i < CAPACITY); 
}

boolean isIdxEff(ListStatik l, IdxType i){
    /*ALGORITMA*/
    return (IDX_MIN <= i && i < listLength(l));
}

boolean isEmpty(ListStatik l){
    /*KAMUS*/
    int i;
    /*ALGORITMA*/
    for(i=0;i<CAPACITY;i++) {
        if (ELMT(l,i) != MARK) {
            return false;
        }
    }
    return true;
}

boolean isFull(ListStatik l){
    /*KAMUS*/
    int i;
    /*ALGORITMA*/
    for(i=0;i<CAPACITY;i++) {
        if (ELMT(l,i) == MARK) {
            return false;
        }
    }
    return true;
}

void readList(ListStatik *l){
    /*KAMUS*/
    int banyakElemen = IDX_UNDEF;
    IdxType i;
    ElType elemen;
    /*ALGORITMA*/
    CreateListStatik(l);
    while (banyakElemen < 0 || banyakElemen > CAPACITY) {
        scanf("%d", &banyakElemen);
    }
    for (i = 0; i < banyakElemen; i++) {
        scanf("%d", &elemen);
        ELMT(*l,i) = elemen; 
    }
}

void printList(ListStatik l) {
    /*KAMUS*/
    IdxType i; 
    /*ALGORITMA*/
    if (listLength(l) == 0) {
        printf("[]");
    }else {
        printf("[");
        for (i = 0; i<listLength(l); i++) {     
            printf("%d", ELMT(l,i));
            if (i != listLength(l)-1) {
                printf(",");
            }
        }
        printf("]");
    }
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
    /*KAMUS*/
    ListStatik newList;
    IdxType i;
    /*ALGORITMA*/
    CreateListStatik(&newList);
    if (plus) {
        for (i=0; i < listLength(l1); i++) {
            ELMT(newList, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    } else {
        for (i=0; i < listLength(l1); i++) {
            ELMT(newList, i) = ELMT(l1, i) - ELMT(l2, i);
        } 
    }
    return newList;
}

boolean isListEqual(ListStatik l1, ListStatik l2){
    /*KAMUS*/
    IdxType i;
    /*ALGORITMA*/
    for (i = 0; i < listLength(l1); i++) {
        if (ELMT(l1, i) != ELMT(l2, i)) {
            return false;
        }
    }
    return true;
}

int indexOf(ListStatik l, ElType val){
    /*KAMUS*/
    IdxType i;
    /*ALGORITMA*/
    for (i=0; i<listLength(l); i++) {
        if (ELMT(l, i) == val) {
            return i;
        }
    }
    return IDX_UNDEF;
}

void extremeValues(ListStatik l, ElType *max, ElType *min){
    /*KAMUS*/
    ElType tempMax = ELMT(l, 0);
    ElType tempMin = ELMT(l, 0);
    IdxType i;
    /*ALGORITMA*/
    //mencari nilai maks
    for (i=0; i<listLength(l); i++) {
        if (ELMT(l,i) > tempMax) {
            tempMax = ELMT(l,i);
        }
    }
    *max = tempMax;
    //mencari nilai min
    for (i=0; i<listLength(l); i++) {
        if (ELMT(l,i) < tempMin) {
            tempMax = ELMT(l,i);
        }
    }
    *min = tempMin;
}

void insertFirst(ListStatik *l, ElType val){
    /*KAMUS*/
    IdxType i;
    ElType temp1, temp2;
    /*ALGORITMA*/
    for (i=listLength(*l); i>0; i--) {
        ELMT(*l, i) = ELMT(*l, i-1);
    }
    ELMT(*l, 0) = val;
}

void insertAt(ListStatik *l, ElType val, IdxType idx){
    /*KAMUS*/
    IdxType i;
    ElType temp1, temp2;
    /*ALGORITMA*/
    for (i=idx; i<listLength(*l) + 1; i++) {
        if (i == idx) {
            temp1 = ELMT(*l, i);
            ELMT(*l, i) = val;  
        } else {
            temp2 = ELMT(*l, i);
            ELMT(*l, i) = temp1;
            temp1 = temp2; 
        }
    }
}

void insertLast(ListStatik *l, ElType val) {
    /*KAMUS*/
    /*ALGORITMA*/
    ELMT(*l, listLength(*l)) = val;
}

void deleteFirst(ListStatik *l, ElType *val){
    /*KAMUS*/
    IdxType i;
    /*ALGORITMA*/
    *val = ELMT(*l, 0);
    for (i = 1; i<listLength(*l)+1; i++) {
        ELMT(*l, i-1) = ELMT(*l, i);
    }
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx){
    /*KAMUS*/
    IdxType i;
    /*ALGORITMA*/
    *val = ELMT(*l, idx);
    for (i = idx; i<listLength(*l)+1; i++) {
        ELMT(*l, i) = ELMT(*l, i+1);
    }
    ELMT(*l, CAPACITY-1) = MARK;
}

void deleteLast(ListStatik *l, ElType *val){
    /*KAMUS*/
    /*ALGORITMA*/
    *val = ELMT(*l, listLength(*l) - 1);
    ELMT(*l, listLength(*l) - 1) = MARK;
}

void sortList(ListStatik *l, boolean asc){
    /*KAMUS*/
    IdxType i, j;
    ElType temp;
    /*ALGORITMA*/
    //sorting menggunakan algoritma bubble sort
    if (asc) {
        for (i = 0; i<listLength(*l); i++) {
            for (j = i+1; j<listLength(*l); j++) {
                if (ELMT(*l, i) > ELMT(*l, j)) {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            }
        }
    } else {
        for (i = 0; i<listLength(*l); i++) {
            for (j = i+1; j<listLength(*l); j++) {
                if (ELMT(*l, i) < ELMT(*l, j)) {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            }
        }
    }
}