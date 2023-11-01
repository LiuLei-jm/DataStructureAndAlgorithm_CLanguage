#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MinTableSize 5
#define N 10000

typedef int ElementType;

#ifndef _HashQuad_H
#define _HashQuad_H

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position FindLinearDetection(ElementType Key, HashTable H);
Position FindSquareDetection(ElementType Key, HashTable H);
Position FindDoubleHashing(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H, int type);
ElementType Retrieve(Position P, HashTable H);
HashTable Rehash(HashTable H, int type);
void Error(char *S);
void FatalError(char *S);
static int NextPrime(int num);
static int IsPrime(int num);
Position Hash(ElementType Key, int TabSize);
Position Hash2(ElementType Key, int TabSize);

#endif

enum KindOfEntry
{
    Legitimate,
    Empty,
    Deleted
};

struct HashEntry
{
    ElementType Element;
    enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl
{
    int TableSize;
    Cell *TheCells;
};

int collisionNum;

int main()
{
    srand((unsigned)time(NULL));
    int ranintArr[N];
    for (int i = 0; i < N; i++)
        ranintArr[i] = rand();

    HashTable H;

    H = InitializeTable(N);
    collisionNum = 0;
    for (int i = 0; i < N; i++)
    {
        Insert(ranintArr[i], H, 1);
    }
    printf("TableSize: %d,LinearDetection: %d\n", H->TableSize, collisionNum);
    DestroyTable(H);

    H = InitializeTable(N);
    collisionNum = 0;
    for (int i = 0; i < N; i++)
    {
        Insert(ranintArr[i], H, 2);
    }
    printf("TableSize: %d,SquareDetection: %d\n", H->TableSize, collisionNum);
    DestroyTable(H);

    H = InitializeTable(N);
    collisionNum = 0;
    for (int i = 0; i < N; i++)
    {
        Insert(ranintArr[i], H, 2);
    }
    printf("TableSize: %d,DoubleHashing: %d\n", H->TableSize, collisionNum);
    DestroyTable(H);

    system("Pause");
    return 0;
}

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

    H->TheCells = malloc(sizeof(Cell) * H->TableSize);
    if (H->TheCells == NULL)
    {
        FatalError("Out of space!!!");
    }

    for (i = 0; i < H->TableSize; i++)
    {
        H->TheCells[i].Info = Empty;
    }
    return H;
}

void DestroyTable(HashTable H)
{
    free(H->TheCells);
    free(H);
}

Position FindLinearDetection(ElementType Key, HashTable H)
{
    Position CurrentPos = Hash(Key, H->TableSize);

    while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)
    {
        CurrentPos = (CurrentPos + 1) % H->TableSize;
        collisionNum++;
    }
    return CurrentPos;
}

Position FindSquareDetection(ElementType Key, HashTable H)
{
    Position CurrentPos = Hash(Key, H->TableSize);
    while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)
    {
        CurrentPos = (CurrentPos + collisionNum * 2 - 1) % H->TableSize;
        collisionNum++;
    }
    return CurrentPos;
}

Position FindDoubleHashing(ElementType Key, HashTable H)
{
    Position CurrentPos = Hash(Key, H->TableSize);
    int i = 0;
    while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)
    {
        CurrentPos += (++i * Hash2(Key, H->TableSize));
        CurrentPos = CurrentPos % H->TableSize;
        ++collisionNum;
    }
    return CurrentPos;
}

void Insert(ElementType Key, HashTable H, int type)
{
    Position Pos;

    switch (type)
    {
    case 1:
        Pos = FindLinearDetection(Key, H);
        break;
    case 2:
        Pos = FindSquareDetection(Key, H);
        break;
    case 3:
        Pos = FindDoubleHashing(Key, H);
        break;
    default:
        break;
    }
    if (H->TheCells[Pos].Info != Legitimate)
    {
        H->TheCells[Pos].Info = Legitimate;
        H->TheCells[Pos].Element = Key;
    }
}

ElementType Retrieve(Position P, HashTable H)
{
    return H->TheCells[P].Element;
}

HashTable Rehash(HashTable H, int type)
{
    int i, OldSize;
    Cell *OldCells;

    OldCells = H->TheCells;
    OldSize = H->TableSize;

    H = InitializeTable(2 * OldSize);

    for (i = 0; i < OldSize; i++)
        if (OldCells[i].Info == Legitimate)
            Insert(OldCells[i].Element, H, type);
    free(OldCells);

    return H;
}

void Error(char *S)
{
    fputs(S, stderr);
}

void FatalError(char *S)
{
    fputs(S, stderr);
    exit(EXIT_FAILURE);
}

static int NextPrime(int num)
{
    int i = num;
    while (!IsPrime(i))
        i++;
    return i;
}

static int IsPrime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

Position Hash(ElementType Key, int TabSize)
{
    return (Position)(Key % TabSize);
}

Position Hash2(ElementType Key, int TabSize)
{
    return 7 - (Key % 7);
}