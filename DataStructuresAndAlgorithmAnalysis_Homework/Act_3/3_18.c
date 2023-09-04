#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef char ElementType;

struct Node;
typedef struct Node * PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

void CharDetect(char c, Stack S)
{
    switch (c)
    {
    case '{':
    case '(':
    case '[':
        Push(c, S);
        break;
    case '}':
        if (Top(S) == '{')
            ;
        Pop(S);
        break;
    case ')':
        if (Top(S) == '(')
            ;
        Pop(S);
        break;
    case ']':
        if (Top(S) == '[')
            ;
        Pop(S);
        break;
    case '/':
        if (Top(S) == '/')
            Pop(S);
        else
            Push(c, S);
        break;
    case '*':
        if (Top(S) == '/')
            Push(c, S);
        else if (Top(S) == '*')
            Pop(S);
        break;
    default:
        break;
    }
}

int main()
{
    Stack S = CreateStack();
    char *str = "/*while((c = getchar()) != '\n'){}*/";
    int i = 0;
    while (str[i] != '\0')
    {
        CharDetect(str[i], S);
        i++;
    }
    if (!IsEmpty(S))
    {
        printf("%c ummatch!\n", Top(S));
    }
    else
    {
        printf("Yes balance symbol!\n");
    }
    DisposeStack(S);
    system("Pause");
    return 0;
}

struct Node
{
    ElementType Element;
    PtrToNode Next;
};

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
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

ElementType Top(Stack S)
{
    if (!IsEmpty(S))
        return S->Next->Element;
    Error("Empty stack");
    return ;
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
        free(FirstCell);
    }
}