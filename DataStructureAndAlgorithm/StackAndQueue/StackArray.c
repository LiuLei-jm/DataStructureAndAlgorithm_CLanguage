#include <stdio.h>

int stack[100], i, j, choice = 0, top = -1, n;

void push();
void pop();
void show();

void main()
{
    printf("Enter the number of element in the stack");
    scanf("%d", &n);
    printf("**************Stack operations using array***************");
    printf("\n=========================================\n");
    while (choice != 4)
    {
        printf("Choose one from the below options...\n");
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");
        printf("\nEnter your choice?\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
            printf("Exiting...");
            break;
        default:
            printf("Please Enter valid choice");
        }
    }
}

void push()
{
    int val;
    if (top == n)
    {
        printf("\nOverflow");
    }
    else
    {
        printf("Enter the value?");
        scanf("%d", &val);
        top = top + 1;
        stack[top] = val;
    }
}

void pop()
{
    if (top == -1)
        printf("\nUnderflow");
    else
        top = top - 1;
}

void show()
{
    printf("Stack values: ");
    for (i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    putchar('\n');
    if (top == -1)
    {
        printf("Stack is empty");
    }
}