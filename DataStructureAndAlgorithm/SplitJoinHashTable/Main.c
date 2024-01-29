#include <stdio.h>
#include <stdlib.h>
#include "HashSep.c"

int main(){
    HashTable H = NULL;
    H = InitializeTable(10);
    Insert(0, H);
    Insert(1, H);
    Insert(81, H);
    Insert(4, H);
    Insert(64, H);
    Insert(25, H);
    Insert(16, H);
    Insert(36, H);
    Insert(9, H);
    Insert(49, H);
    PrintHashTable(H);
    DestroyTable(H);
    system("Pause");
    return 0;
} 