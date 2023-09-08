/*
给你一个链表L和另一个链表P，它们包含以升序排列的整数。操作PrintLots(L,P)将打印L中那些由P所指定的位置上的元素。
*/
#include <stdio.h>
#include <stdlib.h>

#define ElementType int

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node{
    ElementType Element;
    PtrToNode Next;
};

List MakeEmpty(List L){
    L = (PtrToNode)malloc(sizeof(struct Node));
    L->Element = -1;
    L->Next = NULL;
    return L;
}

void TailInsert(ElementType X, List L){
    PtrToNode tmp = (PtrToNode)malloc(sizeof(struct Node));
    if(tmp == NULL) {
        printf("获取内存失败!\n");
        return;
    }
    PtrToNode cur = L;
    while(cur->Next!= NULL){
        cur = cur->Next;
    }
    tmp->Element = X;
    tmp->Next = cur->Next;
    cur->Next = tmp;
}

void printList(List L){
    PtrToNode cur = L->Next;
    while(cur->Next != NULL){
        printf("%d ", cur->Element);
        cur = cur->Next;
    }
    printf("%d\n", cur->Element);
}

Position First(List L){
    if(L-> Next != NULL)
    return L->Next;
}
 
void printLots(List L, List P){
    int count = 1;
    Position lPos,pPos;
    lPos = First(L);
    pPos = First(P);
    while(lPos != NULL && pPos != NULL){
        if(pPos->Element == count++){
            printf("%d ", lPos->Element);
            pPos=pPos->Next;
        }
        lPos = lPos->Next;
    }
    putchar('\n');
}

int main(){
    List L, P;
    L = MakeEmpty(L);
    P = MakeEmpty(P);
    TailInsert(1,L);
    TailInsert(2,L);
    TailInsert(3,L);
    TailInsert(4,L);
    TailInsert(5,L);
    TailInsert(6,L);
    TailInsert(7,L);
    TailInsert(8,L);
    TailInsert(1,P);
    TailInsert(3,P);
    TailInsert(4,P);
    TailInsert(6,P);
    // printList(L);
    // printList(P);
    printLots(L, P);
    system("pause");
    return 0;
}