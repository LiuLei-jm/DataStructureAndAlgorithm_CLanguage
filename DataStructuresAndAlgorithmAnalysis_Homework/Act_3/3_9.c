/*
编写任意精度整数运算包。要使用类似于多项式运算的方法。计算在2^4000内数字0到9的分布。
*/
#include <stdio.h>
#include <stdlib.h>

#define SCALE 1000000000
#define SIZE 10

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node
{
    unsigned long long int Element;
    PtrToNode Next;
};

List MakeEmpty()
{
    List list = (List)malloc(sizeof(struct Node));
    if (list == NULL)
    {
        printf("out of space!\n");
        exit(-1);
    }
    list->Next = NULL;
    return list;
}

char *BigNumberToString(List L)
{
    int size = SIZE + 1;
    char *temp = (char *)malloc(sizeof(char) * size);
    char *result = (char *)malloc(sizeof(char) * size);
    Position current, start, end;
    start = L->Next;
    end = NULL;
    while (end != start)
    {
        current = start;
        while (current->Next != end)
        {
            current = current->Next;
        }
        if (end == NULL)
        {
            sprintf(result, "%llu", current->Element);
        }
        else
        {
            size += SIZE;
            result = (char *)realloc(result, size);
            sprintf(temp, "%llu", current->Element);
            strcat(result, temp);
        }
        end = current;
    }
    free(temp);
    return result;
}

void ReversePrintList(List L)
{
    Position start, end, current;
    start = L->Next;
    end = NULL;
    while (end != start)
    {
        current = start;
        while (current->Next != end)
        {
            current = current->Next;
        }
        printf("%d", current->Element);
        end = current;
    }
    putchar('\n');
}

void DeleteList(List L)
{
    Position next;
    while (L)
    {
        next = L->Next;
        free(L);
        L = next;
    }
}

List BigNumber(int base, int exp)
{
    int carry;
    int tmpele;
    List L;
    Position P, Tmp;
    L = MakeEmpty();
    P = L;

    tmpele = base;
    while (tmpele > 0)
    {
        Tmp = (Position)malloc(sizeof(struct Node));
        if (Tmp == NULL)
        {
            printf("out of space!\n");
            exit(-1);
        }
        Tmp->Element = tmpele % SCALE;
        P->Next = Tmp;
        P = Tmp;
        P->Next = NULL;

        tmpele /= SCALE;
    }

    for (int i = 1; i < exp; i++)
    {
        carry = 0;
        for (P = L->Next; P != NULL; P = P->Next)
        {
            P->Element = P->Element * base + carry;
            carry = P->Element / SCALE;
            if (P->Element >= SCALE)
            {
                P->Element %= SCALE;
                tmpele = carry;
                if (P->Next == NULL)
                {
                    while (tmpele > 0)
                    {
                        Tmp = (Position)malloc(sizeof(struct Node));
                        if (Tmp == NULL)
                        {
                            printf("out of space!\n");
                            exit(-1);
                        }
                        Tmp->Element = tmpele % SCALE;
                        P->Next = Tmp;
                        P = Tmp;
                        P->Next = NULL;

                        tmpele /= SCALE;
                    }
                }
            }
        }
    }
    return L;
}

void CalculatorCount(char *str, int num[])
{
    char *ch = str;
    while (*ch != '\0')
    {
        switch (*ch)
        {
        case '0':
            num[0]++;
            break;
        case '1':
            num[1]++;
            break;
        case '2':
            num[2]++;
            break;
        case '3':
            num[3]++;
            break;
        case '4':
            num[4]++;
            break;
        case '5':
            num[5]++;
            break;
        case '6':
            num[6]++;
            break;
        case '7':
            num[7]++;
            break;
        case '8':
            num[8]++;
            break;
        case '9':
            num[9]++;
            break;
            default:
            break;
        }
        ch++;
    }
    for(int i = 0; i < 10; i++){
        printf("鏁板瓧%d鍏辨湁 %d 涓