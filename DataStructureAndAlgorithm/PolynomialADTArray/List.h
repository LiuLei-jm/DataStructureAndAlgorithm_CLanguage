#ifndef _List_H

#define ElementType int
#define MaxDegree 10

typedef struct polynomial
{
    ElementType CoeffArray[MaxDegree + 1];
    ElementType HighPower;
}*Polynomial;

Polynomial ZeroPolynomial(Polynomial P);
void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial* PolySum);
void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial *PolyProd);
void DeletePolynomial(Polynomial P);
void Error(char *S);
void PrintPolynomial(Polynomial P);
static int Max(int a, int b);

#endif