#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "HashSep.h"

#define MinTableSize (5)

struct ListNode
{
    ElementType Element;
    Position Next;
};

typedef Position List;

struct HashTbl
{
    int TableSize;
    List *TheLists;
};

HashTable InitializeTable(int TableSize)
{
    HashTable H;
    int i;

    if (TableSize < MinTableSize)
    {
        Error("Table size too small");
        return NULL;
    }

    H = malloc(sizeof(struct HashTbl));
    if (H == NULL)
        FatalError("Out of space!!!");
    H->TableSize = NextPrime(TableSize);
    H->TheLists = malloc(sizeof(List) * H->TableSize);
    if (H->TheLists == NULL)
        FatalError("Out of space!!!");
    for (i = 0; i < H->TableSize; i++)
    {
        H->TheLists[i] = malloc(sizeof(struct ListNode));
        if (H->TheLists[i] == NULL)
            FatalError("Out of space!!!");
        else
            H->TheLists[i]->Next = NULL;
    }
    return H;
}

void DestroyTable(HashTable H)
{
    for (int i = 0; i < H->TableSize; i++)
        free(H->TheLists[i]);
    free(H->TheLists);
    free(H);
}

Position Find(ElementType Key, HashTable H)
{
    Position P;
    List L;

    L = H->TheLists[Hash(Key, H->TableSize)];
    P = L->Next;
    while (P != NULL && P->Element != Key)
        P = P->Next;
    return P;
}

void Insert(ElementType Key, HashTable H)
{
    Position Pos, NewCell;
    List L;

    Pos = Find(Key, H);
    if (Pos == NULL)
    {
        NewCell = malloc(sizeof(struct ListNode));
        if (NewCell == NULL)
            FatalError("Out of space!!!");
        else
        {
            L = H->TheLists[Hash(Key, H->TableSize)];
            NewCell->Next = L->Next;
            NewCell->Element = Key;
            L->Next = NewCell;
        }
    }
}

ElementType Retrieve(Position P)
{
    return P->Element;
}

void Error(char *S)
{
    fprintf(stderr, "%s\n", S);
}

void FatalError(char *S)
{
    fputs(S, stderr);
    exit(EXIT_FAILURE);
}

int NextPrime(int num)
{
    int flag = 0;
    int i;
    while (flag == 0)
    {
        num++;
        for (i = 2; i < num; i++)
        {
            if (num % i == 0)
                break;
        }
        if (i == num)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        return i;
}

Index Hash(const int Key, int TableSize)
{
    unsigned int HashVal = Key;

    return HashVal % TableSize;
}

void PrintHashTable(HashTable H){
    Position TmpCell;
    for(int i = 0; i < H->TableSize; i++){
        printf("%d.", i);
        TmpCell = H->TheLists[i]->Next;
        while(TmpCell != NULL){
            printf("%d ", TmpCell->Element);
            TmpCell = TmpCell->Next;
        }
        putchar('\n');
    }
}