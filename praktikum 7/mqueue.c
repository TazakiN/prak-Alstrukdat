#include <stdio.h>
#include "queue.h"

int main() {
    Queue q;
    ElType val;

    CreateQueue(&q);

    // Mengisi Queue sampai penuh
    for (int i = 0; i < CAPACITY; i++) {
        enqueue(&q, i);
    }

    // Mencoba menghapus elemen saat Queue penuh
    printf("Mencoba menghapus elemen...\n");
    dequeue(&q, &val); // Coba menghapus elemen
    printf("Elemen yang dihapus: %d\n", val);

    // Menguji panjang Queue setelah dequeue
    int len = length(q);
    printf("Panjang Queue setelah dequeue: %d\n", len);

    printf("index head: %d\n", IDX_HEAD(q));
    printf("index tail: %d\n", IDX_TAIL(q));

    enqueue(&q, 74);

    if (isFull(q)) {
        printf("penuh bro");
    }
    // Menguji displayQueue() setelah dequeue
    printf("Isi Queue setelah dequeue: ");
    displayQueue(q);
    printf("\n");

    return 0;
}
