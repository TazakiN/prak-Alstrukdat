#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*KAMUS*/
    int N, i, max1, max2;
    /*ALGORITMA*/
    scanf("%d", &N);
    int * bil;
    bil = (int*) malloc (N * sizeof(int));

    for (i = 0; i<N; i++) {
        int num;
        scanf("%d", &num);
        bil[i] = num;
    }

    /*cari maks pertama*/
    max1 = bil[0];
    for (i = 0; i<N; i++) {
        if (bil[i] > max1) {
            max1 = bil[i];
        }
    }

    /*cari maks kedua*/
    if (bil[0] == max1) {
        max2 = bil[1];
    } else {
        max2 = bil[0];
    }
    for (i = 0; i<N; i++) {
        if (bil[i] > max2 && bil[i] != max1) {
            max2 = bil[i];
        }
    }
    printf("%d\n", max2);
    free(bil);
    return 0;
}
