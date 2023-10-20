#include <stdio.h>

int main()
{
    /*KAMUS*/
    int awal, akhir, i, digit, now;
    int result = 0;
    /*ALGORITMA*/
    scanf("%d", &awal);
    scanf("%d", &akhir);
    for (i = awal; i<=akhir; i++) {
        now = i;
        digit = now%10;
        while (now != 0) {
            now/=10;
            if (now%10 == digit) {
                continue;
            } else {
                break;
            }
        }
        if (now == 0) {
            result++;
        } else {
            continue;
        }
    }
    printf("%d\n", result);
    return 0;
}
