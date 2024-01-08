/*
编写一个打印单链表的所有元素的程序
*/
#include <stdio.h>
#include <stdlib.h>

#define ElementType int

typedef struct Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;
struct Node
{
    ElementType Element;
    Position Next;
};

void MakeList(List list)
{
    PtrToNode cur = list;
    int n;
    while ((scanf("%d", &n)) == 1)
    {
        while (getchar() != '\n')
            continue;
        PtrToNode tmp = (PtrToNode)malloc(sizeof(struct Node));
        tmp->Element = n;
        tmp->Next = cur->Next;
        cur->Next = tmp;
        cur = cur->Next;
    }
}

List MakeEmpty(List L)
{
    L = (PtrToNode)malloc(sizeof(struct Node));
    L->Next = NULL;
    L->Element = -1;
    return L;
}

void printList(List list)
{
    PtrToNode cur = list->Next;
    while (cur->Next != NULL)
    {
        printf("%d ", cur->Element);
        cur = cur->Next;
    }
    printf("%d\n", cur->Element);
}

int main()
{
    List list;
    list = MakeEmpty(list);
    MakeList(list);
    printList(list);
    system("pause");
    return 0;
}