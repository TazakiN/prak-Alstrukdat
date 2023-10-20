#include <stdio.h>
#include "garis.h"
#include "point.h"

int main()
{
    /*KAMUS*/
    POINT tempBiri;
    GARIS serigala;
    int b, result, n, i;
    /*ALGORITMA*/
    scanf("%d", &b);
    BacaGARIS(&serigala);
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        BacaPOINT(&tempBiri);
        if (JarakGARIS(serigala, tempBiri) <= b) {
            result++;
        }
    }

    printf ("%d\n", result);
    return 0;
}
