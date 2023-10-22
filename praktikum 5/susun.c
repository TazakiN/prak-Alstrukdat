#include <stdio.h>
#include "boolean.h"
#include "wordmachine.h"
#include "charmachine.h"

// Prints word from Mesin Kata
void printWord(Word word) {
    int i;
    for (i = 0; i < word.Length; i++) {
        printf("%c", word.TabWord[i]);
    }
}

// bandingin kedua kata apakah kata1 lebih besar dari kata2 ato ngga
boolean compareWords(Word kata1, Word kata2) {
    int len1 = kata1.Length;
    int len2 = kata2.Length;
    int i = 0;
    
    while (i < len1 && i < len2) {
        if (kata1.TabWord[i] < kata2.TabWord[i]) {
            return false;
        } else if (kata1.TabWord[i] > kata2.TabWord[i]) {
            return true;
        }
        i++;
    }

    if (i < len1) return true;
    return 0;
}

int main() {
    int indexArWord = 0;
    int m, n;
    Word arWord[100], temp;

    STARTWORD();
    while (!EndWord && currentChar != MARK) {
        arWord[indexArWord] = currentWord;
        indexArWord++;
        ADVWORD();
    }
    arWord[indexArWord] = currentWord;
    indexArWord++;

    // Urut secara leksikal
    for (m = 0; m < indexArWord; m++) {
        for (n = m + 1; n < indexArWord; n++) {
            if (compareWords(arWord[m], arWord[n])) {
                temp = arWord[m];
                arWord[m] = arWord[n];
                arWord[n] = temp;
            }
        }
    }

    // Print urutan
    for (m = 0; m < indexArWord; m++) {
        printWord(arWord[m]);
        printf("\n");
    }

    return 0;
}
