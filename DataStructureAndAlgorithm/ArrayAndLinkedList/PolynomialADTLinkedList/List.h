#ifndef _List_H

#define ElementType int

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Polynomial;

Polynomial MakeEmpty(Polynomial P);
void Attach(int c, int e, Polynomial *pRear);
int Compare(int a, int b);
Polynomial PolyAdd(Polynomial P1, Polynomial P2);
Polynomial PolyMult(Polynomial P1, Polynomial P2);
void DeletePolynomial(Polynomial P);
void PrintPolynomial(Polynomial P);
void FatalError(char *S);

#endif