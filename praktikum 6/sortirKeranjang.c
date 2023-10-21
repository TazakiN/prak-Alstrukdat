#include "stack.h"
#include <stdio.h>

void SortirKeranjang (Stack * S1, Stack * S2)
/* Menyortir keranjang S1 menggunakan bantuan S2 */
/* I.S. S1 tidak terurut dan S2 kosong */
/* F.S. S1 kosong dan S2 terurut */
/* Contoh: */
/* TOP */
/* I.S. S1 = [23, 92, 98, 31, 3, 34]; S2 = [] */
/* TOP */
/* I.S. S1 = []; S2 = [3, 23, 31, 34, 92, 98] */
{
    /* KAMUS */
    infotype a, b, temp;
    int Tab[MaxEl];
    int i = 0;

    /* ALGORITMA */
    // Mengecek jika S1 kosong
    if (IsEmpty(*S1)) {
        return;
    }

    // Mengisi Tab dan menghitung panjang Tab
    while (!IsEmpty(*S1)) {
        Pop(S1, &a);
        Tab[i] = a;
        i++;
    }

    // Sorting array Tab
    for (a = 0; a < i; a++) {
        for (b = a + 1; b < i; b++) {
            if (Tab[a] < Tab[b]) {
                temp = Tab[a];
                Tab[a] = Tab[b];
                Tab[b] = temp;
            }
        }
    }

    // Memasukkan elemen-elemen yang sudah diurutkan ke S2
    for (a = 0; a < i; a++) {
        Push(S2, Tab[a]);
    }
}