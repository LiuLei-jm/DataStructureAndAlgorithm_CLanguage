#include <stdio.h>
#include <stdlib.h>

struct PolyNode
{
    int coef;  // 系数
    int expon; // 指数
    struct PolyNode *link;
};
typedef struct PolyNode *Polynomial;

Polynomial MakeEmpty(Polynomial P)
{
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = 0;
    P->expon = 0;
    P->link = NULL;
    return P;
}

void Attach(int c, int e, Polynomial *pRear)
{
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    if(P == NULL) {
        printf("out of space!\n");
        return;
    }
    P->coef = c;
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P;
    *pRear = P;
}

void PrintPolynomial(Polynomial P)
{
    Polynomial current;
    current = P->link;
    while (current != NULL)
    {
        printf("{%d, %d} ", current->coef, current->expon);
        current = current->link;
    }
    putchar('\n');
}

int Compare(int a, int b){
    return a > b ? 1 : a < b ? -1 : 0;
}

Polynomial PolyAdd(Polynomial P1, Polynomial P2)
{
    Polynomial front, rear, P1pos, P2pos;
    int sum;
    front = MakeEmpty(front);
    rear = front;    
    P1pos = P1->link;
    P2pos = P2->link;
    while (P1pos && P2pos)
    {
        switch(Compare(P1pos->expon, P2pos->expon))
        {
        case 1:
            Attach(P1pos->coef, P1pos->expon, &rear);
            P1pos = P1pos->link;
            break;
        case -1:
            Attach(P2pos->coef, P2pos->expon, &rear);
            P2pos = P2pos->link;
            break;
        case 0:
            sum = P1pos->coef + P2pos->coef;
            if (sum)
                Attach(sum, P1pos->expon, &rear);
            P1pos = P1pos->link;
            P2pos = P2pos->link;
            break;
        }
    }
    while (P1pos)
    {
        Attach(P1pos->coef, P1pos->expon, &rear);
        P1pos = P1pos->link;
    }
    while (P2pos)
    {
        Attach(P2pos->coef, P2pos->expon, &rear);
        P2pos = P2pos->link;
    }
    return front;
}

void DeletePolynomial(Polynomial P)
{
    Polynomial temp;
    while (P)
    {
        temp = P->link;
        free(P);
        P = temp;
    }
}

int main()
{
    Polynomial P1, P2, P1Rear, P2Rear, result;
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

    PrintPolynomial(result);
    DeletePolynomial(P1);
    DeletePolynomial(P2);
    DeletePolynomial(result);
    system("Pause");
    return 0;
}