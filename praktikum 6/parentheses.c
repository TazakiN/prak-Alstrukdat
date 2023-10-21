#include "wordmachine.h"
#include "charmachine.h"
#include "stack.h"
#include <stdio.h>

void readWord(Word *input) {
    int i;
    START();
    IgnoreBlanks();

    (*input).Length = 0;
    i = 0;

    while ((currentChar != MARK) && (i < NMax)) {
        (*input).TabWord[i] = currentChar;
        ADV();
        i++;
    }

    (*input).Length = i;

    (*input).TabWord[i] = '\0';
}

int main()
{
    Stack stacknya;
    Word katanya;
    int i, kedalaman;
    char piceun;

    CreateEmpty(&stacknya);
    readWord(&katanya);

    int ukuranStack = 0;
    kedalaman = 0;
    i = 0;
    while(i != katanya.Length) {
        if (katanya.TabWord[i] == '(') {
            Push(&stacknya, '(');
            ukuranStack++;
        } else if (katanya.TabWord[i] == ')'){
            if (kedalaman < ukuranStack) {
                kedalaman = ukuranStack;
            }
            Pop(&stacknya, &piceun);
            ukuranStack--;
        }
        i++;
    }

    if (!IsEmpty(stacknya)) {
        printf("%d\n", (-1));
    } else {
        printf("%d\n" , kedalaman);
    }

    return 0;
}
