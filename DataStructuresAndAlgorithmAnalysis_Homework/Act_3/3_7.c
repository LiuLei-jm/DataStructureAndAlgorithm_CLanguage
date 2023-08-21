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
        return;
    }
    P->link = NULL;
    return P;
}

void Attach(int c, int e, Polynomial *pRear)
{
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    if (P == NULL)
    {
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
    Polynomial current = P->link;
    while (current != NULL)
    {
        printf("{%d, %d} ", current->coef, current->expon);
        current = current->link;
    }
    putchar('\n');
}

void DeletePolynomial(Polynomial P)
{
    Polynomial temp;
    while (P != NULL)
    {
        temp = P->link;
        free(P);
        P = temp;
    }
}

Polynomial Mult(Polynomial P1, Polynomial P2)
{
    Polynomial P1pos, P2pos, result, resRear, temp;
    int c, e, sum;
    result = MakeEmpty(result);
    resRear = result;
    P1pos = P1->link;
    P2pos = P2->link;
    while(P2pos){
        Attach(P1pos->coef * P2pos->coef, P1pos->expon + P2pos->expon, &resRear);
        P2pos = P2pos->link;
    }
    P1pos = P1pos->link;
    while(P1pos){
        P2pos = P2->link;
        resRear = result;
        while(P2pos){
            c = P1pos->coef * P2pos->coef;
            e = P1pos->expon + P2pos->expon;
            while(resRear->link != NULL && resRear->link->expon > e){
                resRear = resRear->link;
            }             
            if(resRear->link != NULL && resRear->link->expon == e){
                if(resRear->link->coef + c)
                resRear->link->coef += c;
                else{
                    temp = resRear->link;
                    resRear->link = temp->link;
                    free(temp);
                }
            }
            else{
                temp = (Polynomial)malloc(sizeof(struct PolyNode));
                temp->coef = c;
                temp->expon = e;
                temp->link = resRear->link;
                resRear->link = temp;
                resRear = resRear->link;
            }
            P2pos = P2pos->link;
        }
        P1pos = P1pos->link;
    }
    return result;
}

int main()
{
    Polynomial list1, L1Rear, list2, L2Rear;
    list1 = MakeEmpty(list1);
    L1Rear = list1;
    Attach(3, 4, &L1Rear);
    Attach(-5, 2, &L1Rear);
    Attach(6, 1, &L1Rear);
    Attach(-2, 0, &L1Rear);
    PrintPolynomial(list1);
    list2 = MakeEmpty(list2);
    L2Rear = list2;
    Attach(5, 20, &L2Rear);
    Attach(-7, 4, &L2Rear);
    Attach(3, 1, &L2Rear);
    PrintPolynomial(list2);

    Polynomial result;
    result = MakeEmpty(result);
    result = Mult(list1, list2);
    PrintPolynomial(result);

    DeletePolynomial(list1);
    DeletePolynomial(list2);
    DeletePolynomial(result);
    system("Pause");
    return 0;
}