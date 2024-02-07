#include <stdio.h>
#include <stdlib.h>
#include "DisjSet.c"

int main()
{
    DisjSet S;
    Initialize(S);
    S[2] = 1;
    S[3] = 1;
    S[4] = 3;

    S[6] = 5;
    S[7] = 5;
    S[8] = 7;

    SetUnion(S, 1, 5);
    Find(8, S);

    system("Pause");
    return 0;
}