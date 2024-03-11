#include <stdio.h>
#include "List.c"


int main(){
    Position P;
    List L;
    int i;
    InitializeCursorSpace();
    
    L = MakeEmpty(L);
    P = L;
    for(i = 0; i < 10; i++){
        Insert(i, L, P);
        P = Advance(P);
    }
    PrintCursorLinkedList(L);

    for(i = 0; i < 10; i+=2){
        Delete(i, L);
    }
    PrintCursorLinkedList(L);

    system("Pause");
    return 0;
}