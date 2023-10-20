#include <stdio.h>
#include "boolean.h"
#include "wordmachine.h"
#include "charmachine.h"

int main()
{
    int langkah;
    scanf("%d", &langkah);

    STARTWORD();
    if (currentWord.Length == 6) {
        printf("Moving %d square upwards\n", langkah);
    } else if (currentWord.Length == 8) {
        if (currentWord.TabWord[4] == 'L') {
            printf("Moving %d square leftwards\n", langkah);
        } else {
            printf("Moving %d square downwards\n", langkah);
        }
    } else if (currentWord.Length == 9) {
        printf("Moving %d square rightwards\n", langkah);
    } 

    return 0;
}
