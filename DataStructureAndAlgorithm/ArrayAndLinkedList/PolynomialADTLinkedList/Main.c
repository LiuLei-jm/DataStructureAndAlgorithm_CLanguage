#include <stdio.h>
#include <stdlib.h>
#include "list.c"

int main()
{
    Polynomial P1, P2, P1Rear, P2Rear, result, result1;

    P1 = MakeEmpty(P1);
    P1Rear = P1;
    Attach(3, 5, &P1Rear);
    Attach(4, 4, &P1Rear);
    Attach(-1, 3, &P1Rear);
    Attach(2, 1, &P1Rear);
    Attach(-1, 0, &P1Rear);
    PrintPolynomial(P1);

    P2 = MakeEmpty(P2);
    P2Rear = P2;
    Attach(2, 4, &P2Rear);
    Attach(1, 3, &P2Rear);
    Attach(-7, 2, &P2Rear);
    Attach(1, 1, &P2Rear);
    PrintPolynomial(P2);

    result = MakeEmpty(result);
    result = PolyAdd(P1, P2);

    printf("Polynomial Add:\n");
    PrintPolynomial(result);
    result1 = MakeEmpty(result1);
    result1 = PolyMult(P1, P2);
    printf("Polynomial Mult\n");
    PrintPolynomial(result1);

    DeletePolynomial(P1);
    DeletePolynomial(P2);
    DeletePolynomial(result);
    DeletePolynomial(result1);

    system("Pause");
    return 0;
}