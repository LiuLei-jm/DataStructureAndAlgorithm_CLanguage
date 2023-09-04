#include <stdio.h>
#include <stdlib.h>

#define BUCKETS 1000
#define N 12
#define TIMES 3
#define ElementType int

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode VariantList;
typedef PtrToNode Position;
struct Node{
    ElementType Element;
    PtrToNode Next;
};

int arr[N] = {
    678912345,234567891,123456789,567891234,678912345,234567891,123456789,567891234,678912345,234567891,123456789,567891234
};

VariantList createVariantList(){
    VariantList list = (VariantList)malloc(sizeof(struct Node));
    if(list == NULL){
        printf("out of space!\n");
        exit(-1);
    }
    return list;
}

VariantList MakeEmpty(VariantList L){
    L->Element = -1;
    L->Next = NULL;
    return L;
}

void InsertBack(int n, VariantList l){
    Position pCurrent, TmpCell;
    TmpCell = (Position)malloc(sizeof(struct Node));
    pCurrent = l;
    if(TmpCell == NULL){
        printf("out of space!\n");
        exit(-1);
    }
    TmpCell->Element = n;
    while(pCurrent->Next != NULL){
        pCurrent = pCurrent->Next;
    }
    TmpCell->Next = pCurrent->Next;
    pCurrent->Next = TmpCell;
}

Position First(VariantList l){
    return l->Next;
}

Position Advance(VariantList l){
    return l->Next;
}

ElementType Retrieve(VariantList l){
    return l->Element;
}

void DeleteVariantList(VariantList l){
    Position pCurrent, Tmp;

    pCurrent = l;
    while(pCurrent != NULL){
        Tmp = pCurrent->Next;
        free(pCurrent);
        pCurrent = Tmp;
    }
}

void printArr(){
    for(int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int div1000(int num, int n){
    for( int i = 0; i < n; i++){
        num /= 1000;
    }
    return num;
}

void radixSort(){
    VariantList buckets[BUCKETS];

    for(int i = 0; i < BUCKETS; i++)
    buckets[i] = createVariantList();

    for(int i = 0; i < BUCKETS; i++){
        for(int i = 0; i < BUCKETS; i++){
            MakeEmpty(buckets[i]);
        }
        for(int j = 0; j < N; j++){
            InsertBack(arr[j], buckets[div1000(arr[j],i) % 1000]);
        }
        
        int k = 0;
        for(int j = 0; j < BUCKETS; j++){
            Position p = First(buckets[j]);
            while(p!=NULL){
                arr[k++] = Retrieve(p);
                p = Advance(p);
            }
        }
    }
    
    for(int i = 0; i < BUCKETS; i++){
        DeleteVariantList(buckets[i]);
    }
}

int main(){
    printArr();
    radixSort();
    printArr();
    system("Pause");
    return 0;
}