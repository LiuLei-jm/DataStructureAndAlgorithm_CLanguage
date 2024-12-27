#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create();

void main()
{
    struct node *root;
    root = create();
}

struct node *create()
{
    struct node *temp;
    int choice = 0;
    int data;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nPress 0 to exit");
    printf("\nPress 1 gor new node");
    printf("\nEnter your choice:");
    scanf("%d", &choice);
    if (choice == 0)
    {
        return 0;
    }
    else
    {
        printf("\nEnter the data:");
        scanf("%d", &data);
        temp->data = data;
        printf("\nEnter the left child of %d", data);
        temp->left = create();
        printf("\nEnter the right child of %d", data);
        temp->right = create();
        return temp;
    }
}
