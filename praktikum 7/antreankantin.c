#include "queue.h"
#include <stdio.h>

int main()
{
    /*KAMUS*/
    Queue q;
    int operasi, val, dilayani = 0;
    float avg;
    boolean running;
    /*ALGORITMA*/
    CreateQueue(&q);
    running = true;
    while (running) {
        scanf("%d", &operasi);
        if (operasi == 1) {
            scanf("%d", &val);
            if (isFull(q)) {
                printf("Queue penuh\n");
            } else {
                //enqqueue
                enqueue(&q, val);
            }
        } else if (operasi == 2) {
            if (isEmpty(q)) {
                printf("Queue kosong\n");
            } else {
                //dequeue
                dequeue(&q, &val);
                dilayani++;
                avg += val;
            }
        } else { 
            running = false;
        }
    }

    //output hasil
    printf("%d\n", dilayani);
    if (dilayani != 0) {
        printf("%.2f\n", (float) avg / dilayani);
    } else {
        printf("Tidak bisa dihitung\n");
    }
    return 0;
}
