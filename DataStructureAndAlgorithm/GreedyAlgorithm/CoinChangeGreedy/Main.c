#include <stdio.h>
#include <stdlib.h>

int coinChangeGreedy(int *coins, int size, int amt);

int main()
{
    int coins[6] = {1,5,10,20,50,100};
    int amt = 186;
    int res = coinChangeGreedy(coins, 6, amt);
    printf("coins = ");
    for(int i = 0 ; i < 6; i++){
        printf("%d ", coins[i]);
    }
    putchar('\n');
    printf("amt = %d\n",amt);
    printf("凑到%d所需的最少硬币数量为%d\n",amt,res);
    
    int coins1[3] = {1,20,50};
    int amt1 = 60;
    int res1 = coinChangeGreedy(coins1, 3, amt1);
    printf("coins = ");
    for(int i = 0 ; i < 3; i++){
        printf("%d ", coins1[i]);
    }
    putchar('\n');
    printf("amt = %d\n",amt1);
    printf("凑到%d所需的最少硬币数量为%d\n",amt1,res1);
    
    printf("实际上需要的最少数量为3,即20+20+20\n");

    return 0;
}

int coinChangeGreedy(int *coins, int size, int amt)
{
    int i = size - 1;
    int count = 0;
    while (amt > 0)
    {
        while (i > 0 && coins[i] > amt)
        {
            i--;
        }
        count++;
        amt -= coins[i];
    }
    return amt == 0 ? count : -1;
}