#include <stdio.h>
#include <stdlib.h>

int heap[40];
int size = -1;

int parent(int i)
{
    return (i - 1) / 2;
}

int left_child(int i)
{
    return i + 1;
}

int right_child(int i)
{
    return i + 2;
}

int get_max()
{
    return heap[0];
}

int get_min()
{
    return heap[size];
}

void moveup(int i)
{
    while (i > 1)
    {
        if (heap[parent(i)] < heap[i])
        {
            int temp;
            temp = heap[parent(i)];
            heap[parent(i)] = heap[i];
            heap[i] = temp;
        }
        if (heap[left_child(parent(i))] < heap[i])
        {
            int temp;
            temp = heap[left_child(parent(i))];
            heap[left_child(parent(i))] = heap[i];
            heap[i] = temp;
        }
        if (heap[right_child(parent(i))] < heap[i])
        {
            int temp;
            temp = heap[right_child(parent(i))];
            heap[right_child(parent(i))] = heap[i];
            heap[i] = temp;
        }
        i = i / 2;
    }
}

void movedown(int k)
{
    int index = k;
    int left = left_child(k);
    if (left <= size && heap[left] > heap[index])
    {
        index = left;
    }

    int right = right_child(k);
    if (right <= size && heap[right] > heap[index])
    {
        index = right;
    }

    if (k != index)
    {
        int temp;
        temp = heap[index];
        heap[index] = heap[k];
        heap[k] = temp;
        movedown(index);
    }
}

void removemax()
{
    int r = heap[0];
    heap[0] = heap[size];
    size = size - 1;
    movedown(0);
}

void show()
{
    for (int i = 0; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n%d\n", size);
}

void insert(int p)
{
    size = size + 1;
    heap[size] = p;
    moveup(size);
    show();
}

void delete(int i)
{
    heap[i] = heap[0] + 1;
    moveup(i);
    removemax();
}

int main()
{
    insert(20);
    insert(19);
    insert(21);
    insert(18);
    insert(12);
    insert(17);
    insert(15);
    insert(16);
    insert(14);
    insert(13);
    insert(11);
    insert(10);

    printf("Elements in a priority queue are: ");
    show();

    delete (2);
    show();

    int max = get_max();
    printf("\nThe element which is having the highest priority is: %d ", max);

    int min = get_min();
    printf("\nThe element which is having the minimum priority is: %d", min);

    return 0;
}
