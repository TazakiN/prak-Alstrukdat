#include <stdio.h>
#include "datetime.h"

int main() {
    DATETIME datetime1, datetime2;
    
    // Membaca DATETIME dari input
    printf("Masukkan DATETIME 1 (DD MM YYYY hh mm ss): ");
    BacaDATETIME(&datetime1);

    // Membaca DATETIME dari input
    printf("Masukkan DATETIME 2 (DD MM YYYY hh mm ss): ");
    BacaDATETIME(&datetime2);

    // Menampilkan DATETIME 1
    printf("DATETIME 1: ");
    TulisDATETIME(datetime1);
    printf("\n");

    // Menampilkan DATETIME 2
    printf("DATETIME 2: ");
    TulisDATETIME(datetime2);
    printf("\n");

    // Operasi relasional
    if (DEQ(datetime1, datetime2)) {
        printf("DATETIME 1 sama dengan DATETIME 2\n");
    } else {
        printf("DATETIME 1 tidak sama dengan DATETIME 2\n");
    }

    if (DLT(datetime1, datetime2)) {
        printf("DATETIME 1 kurang dari DATETIME 2\n");
    } else {
        printf("DATETIME 1 tidak kurang dari DATETIME 2\n");
    }

    if (DGT(datetime1, datetime2)) {
        printf("DATETIME 1 lebih dari DATETIME 2\n");
    } else {
        printf("DATETIME 1 tidak lebih dari DATETIME 2\n");
    }

    // Menghitung durasi antara datetime1 dan datetime2
    long int duration = DATETIMEDurasi(datetime1, datetime2);
    printf("Durasi antara DATETIME 1 dan DATETIME 2 adalah %ld detik\n", duration);

    // Menambah dan mengurangi detik pada DATETIME
    int n;
    printf("Masukkan jumlah detik yang ingin ditambahkan ke DATETIME 1: ");
    scanf("%d", &n);

    DATETIME datetime3 = DATETIMENextNDetik(datetime1, n);
    printf("DATETIME 1 setelah ditambah %d detik: ", n);
    TulisDATETIME(datetime3);
    printf("\n");

    printf("Masukkan jumlah detik yang ingin dikurangkan dari DATETIME 2: ");
    scanf("%d", &n);

    DATETIME datetime4 = DATETIMEPrevNDetik(datetime2, n);
    printf("DATETIME 2 setelah dikurangkan %d detik: ", n);
    TulisDATETIME(datetime4);
    printf("\n");

    return 0;
}
