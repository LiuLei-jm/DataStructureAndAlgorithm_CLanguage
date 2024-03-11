#include <stdio.h>
#include <stdlib.h>
#include "Stack.c"


int main(){
    Stack S = CreateStack();
    Push(1, S);
    Push(2, S);
    Push(3, S);
    Push(4,S);
    PrintStack(S);
    Pop(S);
    PrintStack(S);
    DisposeStack(S);

    system("Pause");
    return 0;
}