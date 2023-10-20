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

int main()
{
    int lenTot = 0;
    int i = 0;
    boolean lanjut = true;
    START();
    IgnoreBlanks();
    while (currentChar != MARK & !EndWord) {
        currentWord.TabWord[i] = currentChar;
        currentWord.Length++;
        ADV();
        i++;
    }
    printWord(currentWord);
    printf("\n%d\n", i);
    return 0;
}
