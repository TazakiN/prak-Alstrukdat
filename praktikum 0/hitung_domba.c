#include <stdio.h>

int main()
{
    /*KAMUS*/
    int M, N, i;
    /*ALGORITMA*/
    scanf("%d", &M);
    scanf("%d", &N);
    for (i = 1; i<=M; i++) {
        if (i%N == 0) {
            printf("happy\n");
        } else {
            printf("%d\n", i);
        }
    }

    return 0;
}
