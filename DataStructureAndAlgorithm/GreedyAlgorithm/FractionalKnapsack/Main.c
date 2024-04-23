#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-6

typedef struct
{
    int w;
    int v;
} Item;

float fractionalKnapsack(int wgt[], int val[], int itemCount, int cap);
int sortByValueDensity(const void* a, const void* b);

int main()
{
    int wgt[5] = {10, 20, 30, 40, 50};
    int val[5] = {50, 120, 150, 210, 240};
    float res = fractionalKnapsack(wgt, val, 5, 50);
    printf("不超过背包容量的最大物品价值为%.2f。\n", res);

    return 0;
}

int sortByValueDensity(const void* a, const void* b){
    float res = (float)((Item*)a)->v/((Item*)a)->w - (float)((Item*)b)->v/((Item*)b)->w;
    if(fabs(res) <= EPS) return 0;
    else if(res > 0.0) return -1;
    else return 1;
}

float fractionalKnapsack(int wgt[], int val[], int itemCount, int cap)
{
    Item *items = malloc(sizeof(Item) * itemCount);
    for (int i = 0; i < itemCount; i++)
    {
        items[i] = (Item){.w = wgt[i], .v = val[i]};
    }
    qsort(items, (size_t)itemCount, sizeof(Item), sortByValueDensity);
    float res = 0.0;
    for (int i = 0; i < itemCount; i++)
    {
        if (items[i].w <= cap)
        {
            res += items[i].v;
            cap -= items[i].w;
        }
        else
        {
            res += (float)cap / items[i].w * items[i].v;
            cap = 0;
            break;
        }
    }
    free(items);
    return res;
}
