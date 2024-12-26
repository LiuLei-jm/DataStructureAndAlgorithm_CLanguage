#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void dequeue()
{
    struct node *temp;
    temp = front;
    if ((front == NULL) && (rear == NULL))
    {
        printf("\nQueue is empty");
    }
    else if (front == rear)
    {
        front = rear = NULL;
        free(temp);
    }
    else
    {
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

int peek()
{
    if ((front == NULL) && (rear == NULL))
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nThe front element is %d", front->data);
    }
}

void display()
{
    struct node *temp;
    temp = front;
    printf("\nThe element in a queue are:");
    if ((front == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
    }
    else
    {
        while (temp->next != front)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}

int main()
{
    int choice = 1, x;

    while (choice != 5)
    {
        printf("\nPress 1:Insert an element");
        printf("\nPress 2:Delete an element");
        printf("\nPress 3:Peek the element");
        printf("\nPress 4:Display the element");
        printf("\nPress 5:Exit");
        printf("\nEnter your choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element witch is to be inserted");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nEnter a valid choice\n");
        }
    }
    return 0;
}