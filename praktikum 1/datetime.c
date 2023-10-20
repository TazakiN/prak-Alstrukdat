#include "datetime.h"
#include "time.h"
#include <stdio.h>

int GetMaxDay(int M, int Y) {
    if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) {
        return 31;
    } else if (M == 2) {
        if (Y % 400 == 0 || (Y % 4 == 0 && Y % 100 != 0)) {
            return 29;
        } else {
            return 28;
        }
    } else {
        return 30;
    }
}


boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s) {
    if (D <= GetMaxDay(M, Y)) {
        if (IsTIMEValid(h, m, s)) {
            return true;
        }
    }
    return false;
}

void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss) {
    Day(*D) = DD;
    Month(*D) = MM;
    Year(*D) = YYYY;
    TIME TT;
    CreateTime(&TT, hh, mm, ss);
    Time(*D) = TT;
}

void BacaDATETIME(DATETIME *D) {
    int DD, MM, YYYY, hh, mm, ss;
    
    scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &hh, &mm, &ss);
    while (!IsDATETIMEValid(DD, MM, YYYY, hh, mm, ss)) {
        printf("DATETIME tidak valid");
        scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &hh, &mm, &ss);
    }

    CreateDATETIME(D, DD, MM, YYYY, hh, mm, ss);
}

void TulisDATETIME(DATETIME D) {
    printf("%d %d %d ", Day(D), Month(D), Year(D));
    TulisTIME(Time(D));
}

boolean DEQ(DATETIME D1, DATETIME D2) {
    return((Day(D1) == Day(D2)) && (Month(D1) == Month(D2)) && (Year(D1) == Year(D2)) && TEQ(Time(D1), Time(D2)));
}

boolean DNEQ(DATETIME D1, DATETIME D2){
    return !DEQ(D1, D2);
}

boolean DLT(DATETIME D1, DATETIME D2) {
    if (Year(D1) < Year(D2)) {
        return true;
    } else if (Year(D1) > Year(D2)) {
        return false;
    } else {
        if (Month(D1) < Month(D2)) {
            return true;
        } else if (Month(D1) > Month(D2)) {
            return false;
        } else {
            if (Day(D1) < Day(D2)) {
                return true;
            } else if (Day(D1) > Day(D2)) {
                return false;
            } else {
                if (TLT(Time(D1), Time(D2))) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
}

boolean DGT(DATETIME D1, DATETIME D2) {
    return (!DLT(D1, D2) && DNEQ(D1, D2));
}

DATETIME DATETIMENextNDetik(DATETIME D, int N) {
    Time(D) = NextNDetik(Time(D), N);
    return D; 
}

DATETIME DATETIMEPrevNDetik(DATETIME D, int N) {
    Time(D) = PrevNDetik(Time(D), N);
    return D;
}


long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh) {
    long int result = 0;
    result += ((Day(DAkh)-1)*86400L - (Day(DAw) - 1)*86400L);
    result += Durasi(Time(DAw), Time(DAkh));

    return(result);
}
