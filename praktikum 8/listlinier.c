#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType val) {
    Address res = (Address)malloc(sizeof(Node));
    if (res != NULL) {
        INFO(res) = val; 
        NEXT(res) = NULL; 
    } 
    return res;
}

void CreateList(List *l) {
    FIRST(*l) = NULL;
}

boolean isEmpty(List l) {
    return FIRST(l) == NULL;
}

ElType getElmt(List l, int idx) {
    while (idx != 0) {
        FIRST(l) = NEXT(l);
        idx--;
    }
    return INFO(l);
}

void setElmt(List *l, int idx, ElType val) {
    while (idx != 0) {
        FIRST(*l) = NEXT(*l);
        idx--;
    }
    INFO(*l);
}

int indexOf(List l, ElType val) {
    boolean found = false;
    int idxCOunter = 0;
    while (l != NULL && !found) {
        if (INFO(l) == val) {
            found = true;
        } else {
            FIRST(l) = NEXT(l);
            idxCOunter++;
        }
    }
    if (found) return idxCOunter;
    return IDX_UNDEF;
}

void insertFirst(List *l, ElType val) {
    Address nodeBaru = newNode(val);
    if (nodeBaru != NULL) {
        // jadiin *l sebagai NEXT nya nodeBaru
        NEXT(nodeBaru) = *l;
        // jadiin nodeBaru sebagai awalan list.
        *l = nodeBaru;
    }
}

void insertLast(List *l, ElType val) {
    if (isEmpty(*l)) {
        insertFirst(l, val);
    } else {
        Address nodeBaru = newNode(val);
        if(nodeBaru!=NULL){
            Address last = *l;
            while(NEXT(last) != NULL){
                last = NEXT(last);
            }
            NEXT(last)=nodeBaru;
        }
    }
}

void insertAt(List *l, ElType val, int idx) {
    if (idx == 0) {
        insertFirst;
    } else {
        Address nodeBaru = newNode(val);
        if (nodeBaru != NULL) {
            Address lokasi = *l;
            while(idx != 0) {
                lokasi = NEXT(lokasi);
                idx--;
            }
            NEXT(nodeBaru) = NEXT(lokasi);
            NEXT(lokasi) = nodeBaru;
        }
    }
}

void deleteFirst(List *l, ElType *val);


void deleteLast(List *l, ElType *val);


void deleteAt(List *l, int idx, ElType *val);


void displayList(List l);


int length(List l);


List concat(List l1, List l2) ;

