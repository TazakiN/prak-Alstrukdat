/*
NIM     : 13522032
NAMA    : Tazkia Nizami
TANGGAL : 8 September 2023
FILE    : garbage.c
*/

#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"

int main()
{
    /*KAMUS*/
    ListStatik rumah, perjalanan;
    int result, jenisSampah, i;

    /*ALGORITMA*/
    CreateListStatik(&rumah);
    CreateListStatik(&perjalanan);
    readList(&rumah);
    readList(&perjalanan);

    result = 0;
    for (jenisSampah = 1; jenisSampah<=3; jenisSampah++) {
        int akhir = -1;
        for (i=listLength(rumah)-1; i >= 0; i--) {
            if (ELMT(rumah, i) == jenisSampah) {
                akhir = i;
                break;
            }
        }

        if (akhir == -1) {
            continue;
        }

        for (i = 0; i <= akhir; i++) {
            if (ELMT(rumah, i) == jenisSampah) {
                result++;
            }
            if (i != akhir) {
                result += 2*ELMT(perjalanan,i);
            }    
        }
    }

    printf("%d\n", result);
    return 0;
}
