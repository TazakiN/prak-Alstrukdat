
#include <stdio.h>
#include "liststatik.h"
#include "boolean.h"

int main() {
    ListStatik l1, l2, l3;
    CreateListStatik(&l1);
    CreateListStatik(&l2);
    CreateListStatik(&l3);

    // Kasus 1: Mengisi, mencetak, dan menghitung jumlah elemen list
    printf("Kasus 1: Mengisi, mencetak, dan menghitung jumlah elemen list\n");
    insertLast(&l1, 10);
    insertLast(&l1, 20);
    insertLast(&l1, 30);
    printf("List l1:\n");
    printList(l1);
    int count1 = listLength(l1);
    printf("\nJumlah elemen l1: %d\n", count1);

    insertLast(&l2, 5);
    insertLast(&l2, 15);
    insertLast(&l2, 25);
    printf("\nList l2:\n");
    printList(l2);
    int count2 = listLength(l2);
    printf("\nJumlah elemen l2: %d\n", count2);

    // Kasus 2: Mengakses elemen pertama dan terakhir
    printf("\nKasus 2: Mengakses elemen pertama dan terakhir\n");
    IdxType firstIdx1 = getFirstIdx(l1);
    IdxType lastIdx2 = getLastIdx(l2);
    printf("Elemen pertama l1: %d\n", ELMT(l1, firstIdx1));
    printf("Elemen terakhir l2: %d\n", ELMT(l2, lastIdx2));

    // Kasus 3: Mencari indeks elemen dalam list
    printf("\nKasus 3: Mencari indeks elemen dalam list\n");
    int index1 = indexOf(l1, 20);
    int index2 = indexOf(l2, 15);
    printf("Indeks elemen 20 dalam l1: %d\n", index1);
    printf("Indeks elemen 15 dalam l2: %d\n", index2);

    // Kasus 4: Menambahkan dan menghapus elemen dari list
    printf("\nKasus 4: Menambahkan dan menghapus elemen dari list\n");
    insertFirst(&l1, 5);
    printf("List l1 setelah insertFirst(5):\n");
    printList(l1);

    insertAt(&l2, 35, 2);
    printf("\nList l2 setelah insertAt(35, 2):\n");
    printList(l2);

    insertLast(&l3, 50);
    printf("\nList l3 setelah insertLast(50):\n");
    printList(l3);

    ElType val1, val2, val3;
    deleteFirst(&l1, &val1);
    printf("\nList l1 setelah deleteFirst (elemen yang dihapus = %d):\n", val1);
    printList(l1);

    deleteAt(&l2, &val2, 1);
    printf("\nList l2 setelah deleteAt (elemen yang dihapus = %d) pada indeks 1:\n", val2);
    printList(l2);

    deleteLast(&l3, &val3);
    printf("\nList l3 setelah deleteLast (elemen yang dihapus = %d):\n", val3);
    printList(l3);

    // Kasus 5: Operasi aritmatika
    printf("\nKasus 5: Operasi aritmatika\n");
    ListStatik l4 = plusMinusList(l1, l2, true);
    printf("Hasil penjumlahan l1 dan l2:\n");
    printList(l4);

    ListStatik l5 = plusMinusList(l1, l2, false);
    printf("\nHasil pengurangan l1 dan l2:\n");
    printList(l5);

    // Kasus 6: Mengecek kesetaraan dua list
    printf("\nKasus 6: Mengecek kesetaraan dua list\n");
    boolean isEqual1 = isListEqual(l1, l2);
    printf("l1 sama dengan l2: %s\n", isEqual1 ? "true" : "false");

    boolean isEqual2 = isListEqual(l1, l4);
    printf("l1 sama dengan l4: %s\n", isEqual2 ? "true" : "false");

    // Kasus 7: Nilai maksimum dan minimum dalam list
    printf("\nKasus 7: Nilai maksimum dan minimum dalam list\n");
    ElType max1, min1, max2, min2;
    extremeValues(l1, &max1, &min1);
    extremeValues(l2, &max2, &min2);
    printf("Nilai maksimum l1: %d\n", max1);
    printf("Nilai minimum l1: %d\n", min1);
    printf("Nilai maksimum l2: %d\n", max2);
    printf("Nilai minimum l2: %d\n", min2);

    // Kasus 8: Pengujian fungsi sortList
    printf("\nKasus 8: Pengujian fungsi sortList\n");
    printf("List l1 sebelum diurutkan secara ascending:\n");
    printList(l1);
    sortList(&l1, true);
    printf("\nList l1 setelah diurutkan secara ascending:\n");
    printList(l1);

    printf("\nList l2 sebelum diurutkan secara descending:\n");
    printList(l2);
    sortList(&l2, false);
    printf("\nList l2 setelah diurutkan secara descending:\n");
    printList(l2);

    return 0;
}
