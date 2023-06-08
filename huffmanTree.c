#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int weight;
    int parent;
    int lChild;
    int rChild;
} TreeNode;

typedef struct HFTree
{
    TreeNode *data;
    int length;
} HFTree;

HFTree *initTree(int *weight, int length)
{
    HFTree *T = (HFTree *)malloc(sizeof(HFTree));
    T->data = (TreeNode *)malloc(sizeof(TreeNode) * (2 * length - 1));
    T->length = length;
    for (int i = 0; i < length; i++)
    {
        T->data[i].weight = weight[i];
        T->data[i].parent = 0;
        T->data[i].lChild = -1;
        T->data[i].rChild = -1;
    }
    return T;
}

int *selectMin(HFTree *T)
{
    int min = 10000;
    int secondMin = 10000;
    int minIndex;
    int secondIndex;
    for (int i = 0; i < T->length; i++)
    {
        if (T->data[i].parent == 0)
        {
            if (T->data[i].weight < min)
            {
                min = T->data[i].weight;
                minIndex = i;
            }
        }
    }
    for (int i = 0; i < T->length; i++)
    {
        if (T->data[i].parent == 0 && i != minIndex)
        {
            if (T->data[i].weight < secondMin)
            {
                secondMin = T->data[i].weight;
                secondIndex = i;
            }
        }
    }
    int *res = (int *)malloc(sizeof(int) * 2);
    res[0] = minIndex;
    res[1] = secondIndex;
    return res;
}

void createHFTree(HFTree *T)
{
    int *res;
    int min;
    int secondMin;
    int length = T->length * 2 - 1;
    for (int i = T->length; i < length; i++)
    {
        res = selectMin(T);
        min = res[0];
        secondMin = res[1];
        T->data[i].weight = T->data[min].weight + T->data[secondMin].weight;
        T->data[i].lChild = min;
        T->data[i].rChild = secondMin;
        T->data[i].parent = 0;
        T->data[min].parent = i;
        T->data[secondMin].parent = i;
        T->length++;
    }
}

void preOrder(HFTree *T, int index)
{
    if (index != -1)
    {
        printf("%d ", T->data[index].weight);
        preOrder(T, T->data[index].lChild);
        preOrder(T, T->data[index].rChild);
    }
}

int main()
{
    int weight[7] = {5, 1, 3, 6, 11, 2, 4};
    HFTree *T = initTree(weight, 7);
    createHFTree(T);
    preOrder(T, T->length - 1);
    system("pause");
    return 0;
}