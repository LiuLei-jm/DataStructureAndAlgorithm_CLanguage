#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "List.h"

Polynomial ZeroPolynomial(Polynomial P)
{
    int i;
    P = malloc(sizeof(struct polynomial));
    for (i = 0; i <= MaxDegree; i++)
        P->CoeffArray[i] = 0;
    P->HighPower = 0;
    return P;
}

void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial *PolySum)
{
    int i;

    *PolySum = ZeroPolynomial(*PolySum);
    (*PolySum)->HighPower = Max(Poly1->HighPower,
                             Poly2->HighPower);

    for (i = (*PolySum)->HighPower; i >= 0; i--)
        (*PolySum)->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
}

void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial *PolyProd)
{
    int i, j;

    *PolyProd = ZeroPolynomial(*PolyProd);
    (*PolyProd)->HighPower = Poly1->HighPower + Poly2->HighPower;

    if ((*PolyProd)->HighPower > MaxDegree)
        Error("Exceeded array size");
    else
        for (i = 0; i <= Poly1->HighPower; i++)
            for (j = 0; j <= Poly2->HighPower; j++)
                (*PolyProd)->CoeffArray[i + j] +=
                    Poly1->CoeffArray[i] *
                    Poly2->CoeffArray[j];
}

void DeletePolynomial(Polynomial P){
    free(P);
}

void Error(char *S){
    fputs(S, stderr);
}

void PrintPolynomial(Polynomial P){
    int i;
    for(i = 0; i< P->HighPower; i++){
        printf("%d ", P->CoeffArray[i]);
    }
    putchar('\n');
}

static int Max(int a, int b){
    return a > b ? a : b;
}