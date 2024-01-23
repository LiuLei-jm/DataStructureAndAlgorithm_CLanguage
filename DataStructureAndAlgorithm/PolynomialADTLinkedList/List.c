#include <stdio.h>
#include <stdlib.h>
#include "List.h"

struct Node
{
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};

Polynomial MakeEmpty(Polynomial P)
{
    P = malloc(sizeof(struct Node));
    P->Coefficient = 0;
    P->Exponent = 0;
    P->Next = NULL;
}

void Attach(int c, int e, Polynomial *pRear)
{
    Polynomial P = malloc(sizeof(struct Node));
    if (P == NULL)
    {
        FatalError("Out of space!");
    }
    P->Coefficient = c;
    P->Exponent = e;
    P->Next = NULL;
    (*pRear)->Next = P;
    *pRear = P;
}

int Compare(int a, int b)
{
    return a > b ? 1 : a < b ? -1
                             : 0;
}

Polynomial PolyAdd(Polynomial P1, Polynomial P2)
{
    Polynomial front, rear, P1Pos, P2Pos;
    front = MakeEmpty(front);
    rear = front;
    P1Pos = P1->Next;
    P2Pos = P2->Next;
    int sum;
    while (P1Pos && P2Pos)
    {
        switch (Compare(P1Pos->Exponent, P2Pos->Exponent))
        {
        case 1:
            Attach(P1Pos->Coefficient, P1Pos->Exponent, &rear);
            P1Pos = P1Pos->Next;
            break;
        case -1:
            Attach(P2Pos->Coefficient, P2Pos->Exponent, &rear);
            P2Pos = P2Pos->Next;
            break;
        case 0:
            sum = P1Pos->Coefficient + P2Pos->Coefficient;
            if (sum)
            {
                Attach(sum, P1Pos->Exponent, &rear);
            }
            P1Pos = P1Pos->Next;
            P2Pos = P2Pos->Next;
            break;
        default:
            break;
        }
    }
    while (P1Pos)
    {
        Attach(P1Pos->Coefficient, P1Pos->Exponent, &rear);
        P1Pos = P1Pos->Next;
    }
    while (P2Pos)
    {
        Attach(P2Pos->Coefficient, P2Pos->Exponent, &rear);
        P2Pos = P2Pos->Next;
    }
    return front;
}

Polynomial PolyMult(Polynomial P1, Polynomial P2)
{
    Polynomial front, rear, P1Pos, P2Pos, Tmp;
    front = MakeEmpty(front);
    rear = front;
    P1Pos = P1->Next;
    P2Pos = P2->Next;
    int TmpC, TmpE;
    while (P2Pos)
    {
        Attach(P1Pos->Coefficient * P2Pos->Coefficient, P1Pos->Exponent + P2Pos->Exponent, &rear);
        P2Pos = P2Pos->Next;
    }
    P1Pos = P1Pos->Next;
    while (P1Pos)
    {
        P2Pos = P2->Next;
        rear = front;
        while (P2Pos)
        {
            TmpC = P1Pos->Coefficient * P2Pos->Coefficient;
            TmpE = P1Pos->Exponent + P2Pos->Exponent;
            while (rear->Next != NULL && rear->Next->Exponent > TmpE)
            {
                rear = rear->Next;
            }
            if (rear->Next != NULL && rear->Next->Exponent == TmpE)
            {
                if (rear->Next->Coefficient + TmpC)
                    rear->Next->Coefficient += TmpC;
                else
                {
                    Tmp = rear->Next;
                    rear->Next = Tmp->Next;
                    free(Tmp);
                }
            }
            else
            {
                Tmp = malloc(sizeof(struct Node));
                Tmp->Coefficient = TmpC;
                Tmp->Exponent = TmpE;
                Tmp->Next = rear->Next;
                rear->Next = Tmp;
                rear = rear->Next;
            }
            P2Pos = P2Pos->Next;
        }
        P1Pos = P1Pos->Next;
    }
    return front;
}

void DeletePolynomial(Polynomial P)
{
    Polynomial Tmp;
    while (P)
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

void PrintPolynomial(Polynomial P)
{
    Polynomial current = P->Next;
    while (current)
    {
        printf("{%d,%d} ", current->Coefficient, current->Exponent);
        current = current->Next;
    }
    putchar('\n');
}

void FatalError(char *S)
{
    fputs(S, stderr);
    exit(EXIT_FAILURE);
}