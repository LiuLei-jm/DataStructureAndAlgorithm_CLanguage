#include <stdio.h>
#include <stdlib.h>

typedef char* ElementType ;

struct Node;
typedef struct Node * PtrToNode;
typedef PtrToNode Stack;

struct Node
{
    ElementType Element;
    PtrToNode Next;
};

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

void FataError(char *S)
{
    fputs("S\n", stderr);
    exit(EXIT_FAILURE);
}

void Error(char *S)
{
    fputs("S\n", stderr);
}

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

Stack CreateStack(void)
{
    Stack S;
    S = (Stack)malloc(sizeof(struct Node));
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
        Error("Must use CreateStack first.");
    else
    {
        while (!IsEmpty(S))
            Pop(S);
    }
}

void Push(ElementType X, Stack S)
{
    PtrToNode TmpCell;

    TmpCell = (PtrToNode)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
    {
        FataError("out of space");
    }
    else
    {
        TmpCell->Element = (char*)malloc(sizeof(char)*strlen(X)+1);
        strncpy(TmpCell->Element , X, strlen(X) + 1);
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

ElementType Top(Stack S)
{
    if (!IsEmpty(S))
        return S->Next->Element;
    Error("Empty stack");
    return NULL;
}

void Pop(Stack S)
{
    PtrToNode FirstCell;

    if (IsEmpty(S))
        Error("Empty stack");
    else
    {
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        free(FirstCell->Element);
        free(FirstCell);
    }
}
int Calculator(int x, int y, char o)
{
    switch (o)
    {
    case '+':
        return x + y;
        break;
    case '-':
        return x - y;
        break;
    case '*':
        return x * y;
        break;
    case '/':
        return x / y;
        break;
    default:
        break;
    }
}

int main()
{
    Stack S = CreateStack();
    char *str = "6 5 2 3 + 8 * + 3 + *";
    char num[10];
    int i = 0, j;
    int x, y, sum = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/')
            {
                j = 0;
                while (str[i] != ' ')
                {
                    num[j] = str[i];
                    i++;
                    j++;
                }
                num[j] = '\0';
                Push(num, S);
            }
            else
            {
                y = atoi(Top(S));
                Pop(S);
                x = atoi(Top(S));
                Pop(S);
                sum = Calculator(x, y, str[i]);
                sprintf(num, "%d", sum);
                Push(num, S);
            }
        }
        i++;
    }

    printf("sum = %d\n", sum);
    DisposeStack(S);

    system("Pause");
    return 0;
}