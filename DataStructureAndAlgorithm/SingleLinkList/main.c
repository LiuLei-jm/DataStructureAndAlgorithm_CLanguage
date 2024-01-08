#include <stdio.h>
#include "List.c"

int main(){
    List list;
    list = MakeEmpty(list);
    Position Next = list;
    Insert(1, list, Next);
    Next = Advance(Next);
    Insert(2, list, Next);
    Next = Advance(Next);
    Insert(3, list, Next);
    Next = Advance(Next);
    Insert(4, list, Next);
    Next = Advance(Next);
    Delete(3, list);
    
    PrintList(list);

    DeleteList(list);

    system("Pause");
    return 0;
}