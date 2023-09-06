#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElementType;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
struct Node
{
    ElementType Element;
    PtrToNode Next;
};

typedef struct queue
{
    ElementType *Array;
    int Capacity;
    int Front;
    int Rear;
    int Size;
} *Queue;

int IsEmptyQueue(Queue Q);
int IsFullQueue(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmptyQueue(Queue Q);
int Succ(int Value, Queue Q);
void EnQueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void DeQueue(Queue Q);
ElementType FrontAndDeQueue(Queue Q);

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void PrintMakeEmpty(Stack S, char *newStr, int *n);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
void FataError(char *s);
void Error(char *s);
int IsOperator(char c);
void PostfixExpression(char *str, Stack S, char *newStr);
void InfixExpression(char *str, Stack S, char *newStr);

int main()
{
    char str[50] = "4 * (12 + 3) - 5.4 / 3";
    Stack S = CreateStack();
    char newStr[50];
    char newStr1[50];

    PostfixExpression(str, S, newStr);
    printf("%s\n", newStr);

    InfixExpression(newStr, S, newStr1);
    printf("%s\n", newStr1);

    DisposeStack(S);
    system("Pause");
    return 0;
}

void InfixExpression(char *str, Stack S, char *newStr)
{
    int i = 0, j = 0, flag = 0, isBracketed = 0;
    Queue Q = CreateQueue(20);

    while (str[i] != '\0')
    {
        if (!IsOperator(str[i]) && flag == 1 && str[i] != ' ')
        {
            while (!IsEmptyQueue(Q) || !IsEmpty(S))
            {
                while (Front(Q) != ' ')
                {
                    newStr[j++] = FrontAndDeQueue(Q);
                }
                newStr[j++] = FrontAndDeQueue(Q);
                while (Front(Q) == ' ')
                {
                    DeQueue(Q);
                }
                if (!IsEmpty(S))
                {
                    newStr[j++] = Top(S);
                    Pop(S);
                    newStr[j++] = ' ';
                    if ((Top(S) == '+' || Top(S) == '-') && (newStr[j - 2] == '*' || newStr[j - 2] == '/'))
                    {
                        newStr[j++] = '(';
                        isBracketed = 1;
                    }
                }
            }
            if (isBracketed == 1)
            {
                newStr[--j] = ')';
                newStr[++j] = ' ';
                j++;
                isBracketed = 0;
            }
            flag = 0;
        }
        if (!IsOperator(str[i]))
        {
            EnQueue(str[i], Q);
        }
        else
        {
            Push(str[i], S);
            flag = 1;
        }
        i++;
    }
    while (!IsEmptyQueue(Q) || !IsEmpty(S))
    {
        if (!IsEmpty(S))
        {
            newStr[j++] = Top(S);
            Pop(S);
            newStr[j++] = ' ';
            if ((Top(S) == '+' || Top(S) == '-') && (newStr[j - 2] == '*' || newStr[j - 2] == '/'))
            {
                newStr[j++] = '(';
                isBracketed = 1;
            }
        }
        while (Front(Q) != ' ')
        {
            newStr[j++] = FrontAndDeQueue(Q);
        }
        newStr[j++] = FrontAndDeQueue(Q);
        while (Front(Q) == ' ')
        {
            DeQueue(Q);
        }
    }
    if (isBracketed == 1)
    {
        newStr[--j] = ')';
        newStr[++j] = ' ';
        j++;
        isBracketed = 0;
    }
    newStr[--j] = '\0';
}

void PostfixExpression(char *str, Stack S, char *newStr)
{
    int i = 0, j = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            switch (str[i])
            {
            case ')':
                PrintMakeEmpty(S, newStr, &j);
                break;
            case '(':
            case '*':
            case '/':
                Push(str[i], S);
                break;
            case '+':
            case '-':
                if (Top(S) == '*' || Top(S) == '/')
                {
                    PrintMakeEmpty(S, newStr, &j);
                }
                Push(str[i], S);
                break;
            default:
                while (str[i] != ' ' && !IsOperator(str[i]) && str[i] != '\0')
                {
                    // printf("%c", str[i]);
                    newStr[j] = str[i];
                    i++;
                    j++;
                }
                // printf(" ");
                newStr[j++] = ' ';
                continue;
                break;
            }
        }
        i++;
    }
    PrintMakeEmpty(S, newStr, &j);
    // printf("\n");
    newStr[--j] = '\0';
}

void PrintMakeEmpty(Stack S, char *strNew, int *n)
{
    while (!IsEmpty(S))
    {
        if (Top(S) != '(')
        {
            // printf("%c ", Top(S));
            strNew[*n] = Top(S);
            (*n)++;
            strNew[*n] = ' ';
            (*n)++;
        }
        Pop(S);
    }
}

int IsOperator(char c)
{
    if (c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    else
        return 0;
}

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

Stack CreateStack(void)
{
    Stack S = (Stack)malloc(sizeof(struct Node));
    if (S == NULL)
    {
        FataError("out of space!");
    }
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

void DisposeStack(Stack S)
{
    MakeEmpty(S);
    free(S);
}

void MakeEmpty(Stack S)
{
    if (S == NULL)
    {
        Error("Must use CreateStack first.");
    }
    else
    {
        while (!IsEmpty(S))
            Pop(S);
    }
}

void Push(ElementType X, Stack S)
{
    // int strLength = strlen(X) + 1;
    Stack TmpCell = (Stack)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
    {
        FataError("out of space!");
    }
    // char *TmpCell->Element = (char *)malloc(sizeof(char) * strLength);
    // if (TmpCell->Element == NULL)
    // {
    //     FataError("out of space!");
    // }
    // strncpy(TmpCell->Element, X, strLength);
    TmpCell->Element = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}

ElementType Top(Stack S)
{
    if (!IsEmpty(S))
    {
        return S->Next->Element;
    }
    else
        return;
}

void Pop(Stack S)
{
    Stack TmpCell;
    if (!IsEmpty(S))
    {
        TmpCell = S->Next;
        S->Next = TmpCell->Next;
        // free(TmpCell->Element);
        free(TmpCell);
    }
}

int IsEmptyQueue(Queue Q)
{
    return Q->Size == 0;
}

int IsFullQueue(Queue Q)
{
    return Q->Size == Q->Capacity;
}

Queue CreateQueue(int MaxElements)
{
    Queue Q = (Queue)malloc(sizeof(struct queue));
    if (Q == NULL)
    {
        FataError("out of space!");
    }
    Q->Array = (char *)malloc(sizeof(char) * MaxElements);
    if (Q->Array == NULL)
    {
        FataError("out of space!");
    }
    MakeEmptyQueue(Q);
    Q->Capacity = MaxElements;
    Q->Array = (char *)malloc(sizeof(char) * Q->Capacity);
}

void DisposeQueue(Queue Q)
{
    free(Q->Array);
    free(Q);
}

void MakeEmptyQueue(Queue Q)
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

int Succ(int Value, Queue Q)
{
    if (++Value == Q->Capacity)
        Value = 0;
    return Value;
}

void EnQueue(ElementType X, Queue Q)
{
    if (IsFullQueue(Q))
        Error("Full queue");
    else
    {
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

ElementType Front(Queue Q)
{
    return Q->Array[Q->Front];
}

void DeQueue(Queue Q)
{
    if (IsEmptyQueue(Q))
        Error("Empty queue");
    else
    {
        Q->Size--;
        Q->Front = Succ(Q->Front, Q);
    }
}

ElementType FrontAndDeQueue(Queue Q)
{
    if (IsEmptyQueue(Q))
        Error("Empty queue");
    else
    {
        ElementType Tmp = Q->Array[Q->Front];
        DeQueue(Q);
        return Tmp;
    }
}

void FataError(char *s)
{
    fputs("s\n", stderr);
    exit(EXIT_FAILURE);
}

void Error(char *s)
{
    fputs("s\n", stderr);
}