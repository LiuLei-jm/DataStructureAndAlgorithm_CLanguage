#include <stdio.h>
#define size 5

int deque[size];
int front = -1;
int rear = -1;

void insert_front(int x)
{
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        printf("Overflow");
    }
    else if ((front == -1) && (rear == -1))
    {
        front = rear = 0;
        deque[front] = x;
    }
    else if (front == 0)
    {
        front = size - 1;
        deque[front] = x;
    }
    else
    {
        front = front - 1;
        deque[front] = x;
    }
}

void insert_rear(int x)
{
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        printf("Overflow");
    }
    else if ((front == -1) && (rear == -1))
    {
        front = rear = 0;
        deque[rear] = x;
    }
    else if (rear == size - 1)
    {
        rear = 0;
        deque[rear] = x;
    }
    else
    {
        rear++;
        deque[rear] = x;
    }
}

void display()
{
    int i = front;
    printf("\nElement in a deque are: ");
    while (i != rear)
    {
        printf("%d ", deque[i]);
        i = (i + 1) % size;
    }
    printf("%d\n", deque[rear]);
}

void getfront()
{
    if ((front == -1) && (rear == -1))
    {
        printf("Deque is empty");
    }
    else
    {
        printf("\nThe value of the element at front is: %d", deque[front]);
    }
}

void getrear()
{
    if ((front == -1) && (rear == -1))
    {
        printf("Deque is empty");
    }
    else
    {
        printf("\nThe value of the element at rear is %d", deque[rear]);
    }
}

void delete_front()
{
    if ((front == -1) && (rear == -1))
    {
        printf("Deque is empty");
    }
    else if (front == rear)
    {
        printf("\nThe deleted element is %d", deque[front]);
        front = -1;
        rear = -1;
    }
    else if (front == (size - 1))
    {
        printf("\nThe deleted element is %d", deque[front]);
        front = 0;
    }
    else
    {
        printf("\nThe deleted element is %d", deque[front]);
        front = front + 1;
    }
}

void delete_rear(){
    if((front == -1) && (rear == -1)){
        printf("Deque is empty");
    }
    else if(front == rear){
        printf("\nThe deleted element is %d",deque[rear]);
        front = -1;
        rear = -1;
    }
    else if(rear == 0){
        printf("\nThe deleted element is %d", deque[rear]);
        rear = size -1;
    }
    else{
        printf("\nThe deleted element is %d", deque[rear]);
        rear = rear - 1;
    }
}

int main(){
    insert_front(20);
    insert_front(10);
    insert_rear(30);
    insert_rear(50);
    insert_rear(80);
    display();
    getfront();
    getrear();
    delete_front();
    delete_rear();
    display();
    return 0;
}