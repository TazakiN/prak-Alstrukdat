#include <stdio.h>
#include "listdin.h"

int main() {
    ListDin l1, l2;
    int capacity = 10;

    // Membuat list l1 dengan kapasitas 10
    CreateListDin(&l1, capacity);

    // Mengisi list l1 dengan nilai 1, 2, 3
    for (int i = 1; i <= 3; i++) {
        insertLast(&l1, i);
    }

    printf("List l1:\n");
    printList(l1);

    // Menggunakan beberapa fungsi lainnya
    printf("\nBanyaknya elemen di l1: %d\n", listLength(l1));
    printf("Indeks elemen pertama di l1: %d\n", getFirstIdx(l1));
    printf("Indeks elemen terakhir di l1: %d\n", getLastIdx(l1));
    printf("Apakah l1 kosong? %s\n", isEmpty(l1) ? "Ya" : "Tidak");
    printf("Apakah l1 penuh? %s\n", isFull(l1) ? "Ya" : "Tidak");

    // Mencari indeks elemen dengan nilai 2 di l1
    int index = indexOf(l1, 2);
    if (index != IDX_UNDEF) {
        printf("Indeks elemen dengan nilai 2 di l1: %d\n", index);
    } else {
        printf("Elemen dengan nilai 2 tidak ditemukan di l1.\n");
    }

    // Menambahkan nilai 4 ke l1
    insertLast(&l1, 4);
    printf("\nList l1 setelah menambahkan nilai 4:\n");
    printList(l1);

    // Menghapus elemen terakhir dari l1
    int deletedValue;
    deleteLast(&l1, &deletedValue);
    printf("\nElemen terakhir yang dihapus dari l1: %d\n", deletedValue);
    printf("List l1 setelah menghapus elemen terakhir:\n");
    printList(l1);

    // Mencari nilai maksimum dan minimum di l1
    ElType max, min;
    extremeValues(l1, &max, &min);
    printf("\nNilai maksimum di l1: %d\n", max);
    printf("Nilai minimum di l1: %d\n", min);

    // Meng-copy l1 ke l2
    copyList(l1, &l2);
    printf("\nList l2 setelah dicopy dari l1:\n");
    printList(l2);

    // Menjumlahkan semua elemen di l2
    ElType sum = sumList(l2);
    printf("\nHasil penjumlahan semua elemen di l2: %d\n", sum);

    // Mengurutkan l2 secara mengecil (descending)
    sort(&l2, false);
    printf("\nList l2 setelah diurutkan secara mengecil:\n");
    printList(l2);

    // Mengubah kapasitas l2
    expandList(&l2, 5);
    printf("\nList l2 setelah kapasitasnya diperluas:\n");
    printList(l2);

    // Mengurangi kapasitas l2
    shrinkList(&l2, 3);
    printf("\nList l2 setelah kapasitasnya dikurangi:\n");
    printList(l2);

    // Mengubah kapasitas l2 menjadi sama dengan jumlah elemennya
    compressList(&l2);
    printf("\nList l2 setelah kapasitasnya disesuaikan dengan jumlah elemen:\n");
    printList(l2);

    // Menguji kasus ketika list kosong
    ListDin emptyList;
    CreateListDin(&emptyList, capacity);

    printf("\nList kosong:\n");
    printList(emptyList);
    printf("Banyaknya elemen di list kosong: %d\n", listLength(emptyList));
    printf("Apakah list kosong? %s\n", isEmpty(emptyList) ? "Ya" : "Tidak");

    dealocateList(&l1);
    dealocateList(&l2);
    dealocateList(&emptyList);

    return 0;
}
