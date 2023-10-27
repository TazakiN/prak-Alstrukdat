#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

Address newNode(ElType val){
    Address p = (Address)malloc(sizeof(Node));
    if(p!=NULL){
        INFO(p)=val;
        NEXT(p)=NULL;
    }
    return p;
}

void CreateList(List *l){
    FIRST(*l)=NULL;
}

boolean isEmpty(List l){
    return FIRST(l)==NULL;
}

ElType getElmt(List l, int idx){
    while(idx--){
        FIRST(l)=NEXT(l);
    } return INFO(l);
}

void setElmt(List*l,int idx,ElType val){
    List p=*l;
    while(idx--){
        FIRST(p)=NEXT(p);
    }
    INFO(p)=val;
}

int indexOf(List l, ElType val){
    boolean found=false;int idx=0;
    while(l!=NULL && !found){
        if(INFO(l)==val){
            found=true;
        } else {
            idx++;
            FIRST(l)=NEXT(l);
        }
    }
    if(found) return idx;
    return IDX_UNDEF;
}

void insertFirst(List *l, ElType val){
    Address p = newNode(val);
    if(p!=NULL){
        NEXT(p)=*l;
        *l=p;
    }
}

void insertLast(List *l, ElType val){
    if(isEmpty(*l)){
        insertFirst(l,val);
    } else {
        Address p = newNode(val);
        if(p!=NULL){
            Address last = *l;
            while(NEXT(last)!=NULL){
                last = NEXT(last);
            }
            NEXT(last)=p;
        }
    }
}

void insertAt(List *l, ElType val, int idx){
    if(idx==0){
        insertFirst(l,val);
    } else {
        Address p = newNode(val);
        if(p!=NULL){
            int ctr=0;Address loc=*l;
            while(ctr<idx-1){
                ctr++;
                loc=NEXT(loc);
            }
            NEXT(p)=NEXT(loc);
            NEXT(loc)=p;
        }
    }
}

void deleteFirst(List *l, ElType *val){
    Address p = *l;
    *val = INFO(p);
    *l=NEXT(p);
    free(p);
}

void deleteLast(List *l, ElType *val){
    Address p = *l, loc = NULL;
    while(NEXT(p)!=NULL){
        loc = p;
        p = NEXT(p);
    }
    if(loc==NULL){
        *l=NULL;
    } else {
        NEXT(loc)=NULL;
    }
    *val = INFO(p);
    free(p);
}

void deleteAt(List *l, int idx, ElType *val){
    if(idx==0){
        deleteFirst(l,val);
    } else {
        int ctr=0;Address loc=*l;
        while(ctr<idx-1){
            ctr++;
            loc=NEXT(loc);
        }
        Address p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc)=NEXT(p);
        free(p);
    }
}

void displayList(List l){
    printf("[");
    while(!isEmpty(l)){
        printf("%d",INFO(l));
        if(NEXT(l)!=NULL){
            printf(",");
        }
        l=NEXT(l);
    }
    printf("]\n");
}

int length(List l){
    int cnt=0;
    while(l!=NULL){
        cnt++;
        l=NEXT(l);
    } return cnt;
}

List concat(List l1, List l2){
    List l3;CreateList(&l3);
    Address p = l1;
    while(p!=NULL){
        insertLast(&l3,INFO(p));
        p=NEXT(p);
    }
    p=l2;
    while(p!=NULL){
        insertLast(&l3,INFO(p));
        p=NEXT(p);
    }
    return l3;
}

boolean fSearch(List L, Address P) {
    Address p = L;
    while (p != NULL) {
        if (p == P) {
            return true;
        }
        p = NEXT(p);
    }
    return false;
}

Address searchPrec(List L, ElType X) {
    Address p = L;
    // cek yang pertama
    if (INFO(p) == X) {
        return NULL;
    }
    // cek selain yang pertama
    while (NEXT(p) != NULL) {
        if (INFO(NEXT(p)) == X) {
            return p;
        }
        p = NEXT(p);
    }
    return NULL;
}

ElType maxValue(List l) {
    Address p = l;
    ElType max = INFO(p);
    while (p != NULL) {
        if (INFO(p) > max) {
            max = INFO(p);
        }
        p = NEXT(p);
    }
    return max;
}

Address adrMax(List l) {
    ElType maxVal = maxValue(l);
    Address p = l;
    while (INFO(p) != maxVal) {
        p = NEXT(p);
    } // INFO(p) == maxVal
    return p;
}

ElType minValue(List l) {
    Address p = l;
    ElType min = INFO(p);
    while (p != NULL) {
        if (INFO(p) < min) {
            min = INFO(p);
        }
        p = NEXT(p);
    }
    return min;
}

Address adrMin(List l) {
    ElType minVal = minValue(l);
    Address p = l;
    while (INFO(p) != minVal) {
        p = NEXT(p);
    } // INFO(p) == minVal
    return p;
}

float average(List L) {
    int count = 0, sum = 0; 
    Address p = L;
    while (p != NULL) {
        sum += INFO(p);
        count++;
        p = NEXT(p);
    }
    return (float) sum / count;
}

void deleteAll(List *l) {
    ElType buang;
    while (length(*l) != 0) {
        deleteFirst(l, &buang);
    }
}

void copyList(List *l1, List *l2) {
    *l2 = *l1;
}

void inverseList(List *l) {
    int len = length(*l), i, idxInsert = 0;
    ElType val;
    for (i = 0; i < len; i++) {
        deleteLast(l, &val);
        insertAt(l, val, idxInsert);
        idxInsert++;
    }
}