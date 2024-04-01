#include <stdio.h>
#include <stdlib.h>

void TowerOfHanoi(int n, char from_rod, char to_rod, char aux_rod);

int main()
{
    TowerOfHanoi(5, 'A', 'B', 'C');

    system("Pause");
    return 0;
}

void TowerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    TowerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    TowerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}