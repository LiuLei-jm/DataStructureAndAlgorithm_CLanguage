#include <stdio.h>
#include <stdlib.h>
#include "List.c"

int main()
{
    Polynomial Poly1;
    Polynomial Poly2;
    Polynomial PolySum;
    Polynomial PolyProd;
    Poly1 = ZeroPolynomial(Poly1);
    Poly2 = ZeroPolynomial(Poly2);
    Poly1->CoeffArray[0] = 2;
    Poly1->CoeffArray[1] = 2;
    Poly1->HighPower = 2;
    Poly2->CoeffArray[0] = 3;
    Poly2->CoeffArray[1] = 4;
    Poly2->CoeffArray[2] = 5;
    Poly2->HighPower = 3;
    AddPolynomial(Poly1, Poly2, &PolySum);
    PrintPolynomial(PolySum);
    MultPolynomial(Poly1, Poly2, &PolyProd);
    PrintPolynomial(PolyProd);

    DeletePolynomial(Poly1);
    DeletePolynomial(Poly2);
    DeletePolynomial(PolySum);
     system("Pause");
    return 0;
}