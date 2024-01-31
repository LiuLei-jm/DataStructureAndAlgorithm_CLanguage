#include <stdio.h>
#include <stdlib.h>
#include "HashQuad.c"

int main()
{
    char cList[10] = {'a', 'b', '*', '2', '5', 'J', 'G', '$', '(', 'I'};
    HashTable H = InitializeTable(11);
    for (int i = 0; i < 10; i++)
    {
        Insert(cList[i], H);
    }

    PrintHashTable(H);

    DestroyTable(H);
    system("Pause");
    return 0;
}