#ifndef _HashQuad_H

typedef char ElementType;

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl* HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P, HashTable H);
HashTable Rehash(HashTable H);
void Error(char* S);
void FatalError(char* S);
Index NextPrime(int num);
Index Hash(const char* Key, int TableSize);
void PrintHashTable(HashTable H);

#endif 