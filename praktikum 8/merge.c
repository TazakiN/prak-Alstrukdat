#include "merge.h"
#include <stdio.h>
#include "listlinier.h"
#include "boolean.h"

void splitList(List source, List* front, List* back) {
    int len = length(source), i, val;
    if (len%2 == 0) { // kalo anggotanya ada genap
        for (i = 0; i < len / 2; i++) {
            val = getElmt(source, i);
            insertLast(front, val);
        }

        for (i = (len/2); i < len; i++) {
            val = getElmt(source, i);
            insertLast(back, val);
        }
    } else { // kalo ganjil
        len = (len + 1);
        for (i = 0; i < len / 2; i++) {
            val = getElmt(source, i);
            insertLast(front, val);
        }

        for (i = (len/2); i < len - 1; i++) {
            val = getElmt(source, i);
            insertLast(back, val);
        }
    }
}

List merge(List a, List b) {
    if (a == NULL) {
        return b;
    }
    if (b == NULL) {
        return a;
    }

    List l3;
    Address p;
    ElType val;
    CreateList(&l3);

    // masukin a secara terurut
    int idx, idxA;
    for (idxA = 0; idxA < length(a); idxA++) {
        val =  getElmt(a, idxA);
        p = l3;
        for (idx = 0; idx < length(l3); idx++) {
            if (INFO(p) > val) {
                insertAt(&l3, val, idx);
                break;
            }
            p = NEXT(p);
        }
        if (idx == length(l3)) {
            insertLast(&l3, val);
        }
    }

    // masukin b secara terurut
    int idxB;
    for (idxB = 0; idxB < length(b); idxB++) {
        val =  getElmt(b, idxB);
        p = l3;
        for (idx = 0; idx < length(l3); idx++) {
            if (INFO(p) > val) {
                insertAt(&l3, val, idx);
                break;
            }
            p = NEXT(p);
        }
        if (idx == length(l3)) {
            insertLast(&l3, val);
        }
    }

    return l3;
}

void mergeSort(List* list) {
    List lFront, lBack;

    displayList(*list);
    printf("\n");
    CreateList(&lFront); CreateList(&lBack);

    splitList(*list, &lFront, &lBack);
    if (lFront == NULL || lBack == NULL) {
        return;
    } else {
        mergeSort(&lFront);
        mergeSort(&lBack);
        *list = merge(lFront, lBack);
    }
}
