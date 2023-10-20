#include "queue.h"
#include <stdio.h>

void CreateQueue(Queue *q) {
    /*KAMUS*/
    /*ALGORITMA*/
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q) {
    /*KAMUS*/
    /*ALGORITMA*/
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q) {
    /*KAMUS*/
    /*ALGORITMA*/
    return (IDX_TAIL(q) + 1 == IDX_HEAD(q)) || (IDX_HEAD(q) == 0 && IDX_TAIL(q) == CAPACITY-1);
}

int length(Queue q) {
    /*KAMUS*/
    /*ALGORITMA*/
    if (isEmpty(q)) {
        return 0;
    }else if (IDX_TAIL(q) >= IDX_HEAD(q)) {
        return IDX_TAIL(q) - IDX_HEAD(q) + 1; 
    } else {
        return CAPACITY - IDX_HEAD(q) + IDX_TAIL(q) + 1;
    }
}

void enqueue(Queue *q, ElType val) {
    /*KAMUS*/
    /*ALGORITMA*/
    if (IDX_TAIL(*q) == IDX_UNDEF) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }else if (IDX_TAIL(*q) != CAPACITY-1) {
        IDX_TAIL(*q)++;
    } else {
        IDX_TAIL(*q) = 0;
    }
    TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val) {
    /*KAMUS*/
    /*ALGORITMA*/
    *val = HEAD(*q);
    if (IDX_TAIL(*q) == 0 && IDX_HEAD(*q) == 0) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }else if (IDX_HEAD(*q) != CAPACITY - 1) {
        IDX_HEAD(*q)++;
    } else {
        IDX_HEAD(*q) = 0;
    } 
}

void displayQueue(Queue q) {
    /*KAMUS*/
    int i;
    /*ALGORITMA*/
    printf("[");
    if (length(q) != 0) {
        for (i = 0; i < length(q); i++) {
            if (i != length(q)-1) {
                if (!(i + IDX_HEAD(q) > CAPACITY - 1)) {
                    printf("%d,", q.buffer[i+IDX_HEAD(q)]);
                } else {
                    printf("%d,", q.buffer[i + IDX_HEAD(q) - (CAPACITY)]);
                }
            } else {
                printf("%d", TAIL(q));
            }
        }
    }
    printf("]\n");
}
