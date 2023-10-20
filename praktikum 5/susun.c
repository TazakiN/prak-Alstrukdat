#include <stdio.h>
#include "boolean.h"
#include "wordmachine.h"
#include "charmachine.h"

// Returns string length
int stringLength(char *s) {
   int result =  0;
   int i = 0;
   while (s[i] != '\0') {
      ++result;
      ++i;
   }
   return result;
}

// Prints word from Mesin Kata
void printWord(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {
      printf("%c", word.TabWord[i]);
   }
}


Word arWord[NMax];

boolean compareWord(Word kata1, Word kata2) {
    int m, n;
    int len = kata1.Length;
    boolean hasil = true, hasilHuruf = true;

    for (m = 0; m < len; m++) {
        for (n = 0; n < len; n++) {
            if (kata1.TabWord[m] == kata2.TabWord[n]) {
                break;
            }
            return false;
        }
    }
    return hasil;
}

int main()
{
    int indexArWord = 0;
    int i, j, result = 0;
    boolean lanjut = true;

    STARTWORD(); //cercaesoterica
    while (!EndWord & currentChar!= MARK) {
        arWord[indexArWord] = currentWord;
        indexArWord++;
        ADVWORD();
    }

    printf("%d\n",indexArWord);
    return 0;
}
