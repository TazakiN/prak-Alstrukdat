#include "listrec.h"

#define dieu printf("didieu anying\n");

int main()
{
    /* KAMUS */
    int banyak, val, i, kali, nEl, j;
    List lis = NIL, liskanan = NIL, liskiri = NIL;
    /* ALGORITMA */
    scanf("%d", &banyak);
    for (i = 0; i < banyak; i++)
    {
        scanf("%d", &val);
        lis = konsb(lis, val);
    }

    scanf("%d", &kali);
    for (i = 0; i < kali; i++)
    {
        liskanan = NIL, liskiri = NIL;
        scanf("%d", &nEl);
        for (j = 0; j < nEl; j++)
        {
            liskiri = konso(liskiri, head(lis));
            lis = tail(lis);
        }
        while (!isEmpty(lis))
        {
            liskanan = konso(liskanan, head(lis));
            lis = tail(lis);
        }
        lis = concat(liskiri, liskanan);
        displayList(lis);
    }
    return 0;
}
