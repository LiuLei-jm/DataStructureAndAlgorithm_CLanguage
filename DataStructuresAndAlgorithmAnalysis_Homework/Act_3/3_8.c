#include <stdio.h>
#include <stdlib.h>

struct PolyNode
{
    int coef;
    int expon;
    struct PolyNode *link;
};
typedef struct PolyNode *Polynomial;

Polynomial MakeEmpty(Polynomial P)
{
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    if (P == NULL)
    {
        printf("out of space!\n");
        return NULL;
    }
    P->link = NULL;
    return P;
}

void Attach(int c, int e, Polynomial *pRear)
{
    Polynomial TmpCell;
    TmpCell = (Polynomial)malloc(sizeof(struct PolyNode));
    if (TmpCell == NULL)
    {
        printf("out of space!\n");
        return;
    }
    TmpCell->coef = c;
    TmpCell->expon = e;
    TmpCell->link = NULL;
    (*pRear)->link = TmpCell;
    *pRear = TmpCell;
}

void PrintPolynomial(Polynomial P)
{
    Polynomial current;
    current = P->link;
    while (current)
    {
        printf("{%d, %d} ", current->coef, current->expon);
        current = current->link;
    }
    putchar('\n');
}

void DeletePolynomial(Polynomial P)
{
    Polynomial next;
    while (P)
    {
        next = P->link;
        free(P);
        P = next;
    }
}

Polynomial Mult(Polynomial P1, Polynomial P2)
{
    Polynomial P1pos, P2pos, result, resRear, temp;
    int c, e;
    P1pos = P1->link;
    P2pos = P2->link;
    result = MakeEmpty(result);
    resRear = result;
    while (P2pos)
    {
        Attach(P1pos->coef * P2pos->coef, P1pos->expon + P2pos->expon, &resRear);
        P2pos = P2pos->link;
    }
    P1pos = P1pos->link;
    while (P1pos)
    {
        P2pos = P2->link;
        resRear = result;
        while (P2pos)
        {
            c = P1pos->coef * P2pos->coef;
            e = P1pos->expon + P2pos->expon;
            while(resRear->link != NULL && resRear->link->expon > e){
                resRear = resRear->link;
            }
            if(resRear->link != NULL && resRear->link->expon == e){
                if(resRear->link->expon + c)
                 resRear->link->expon += c;
                else{
                    temp = resRear->link;
                    resRear->link = temp->link;
                    free(temp);
                }
            }
            else{
                temp = (Polynomial)malloc(sizeof(struct PolyNode));
                temp ->coef = c;
                temp->expon = e;
                temp ->link = resRear->link;
                resRear->link = temp;
                resRear = resRear->link;
            }
            P2pos = P2pos->link;
        }
        P1pos = P1pos->link;
    }
    return result;
}

int IsEven(unsigned int N){
    return N % 2 == 0;
}

Polynomial Pow(Polynomial P, unsigned int N){
    if(N == 0){
        return P;
    }
    if(N == 1){
        return P;
    }
    if(IsEven(N)){
        return Pow(Mult(P,P), N /2);
    }
    else{
        return Mult(Pow(Mult(P,P), N / 2),P);
    }
}

int main()
{
    Polynomial list1, L1Rear;
    list1 = MakeEmpty(list1);
    L1Rear = list1;
    Attach(3, 4, &L1Rear);
    Attach(-5, 2, &L1Rear);
    Attach(6, 1, &L1Rear);
    Attach(-2, 0, &L1Rear);
    PrintPolynomial(list1);

    Polynomial result;
    result = MakeEmpty(result);
    result = Pow(list1, 3);
    PrintPolynomial(result);

    DeletePolynomial(list1);
    DeletePolynomial(result);
    
    system("Pause");
    return 0;
}