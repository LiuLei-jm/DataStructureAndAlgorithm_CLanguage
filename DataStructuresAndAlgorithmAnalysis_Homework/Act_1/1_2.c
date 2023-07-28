/*
* 输入是由一些字母和单词构成的二维数组，目标是找出字谜中的单词，这些单词可以是水平、垂直或沿对角线以任何方向放置
* 方向由8种：
    1.从左到右
    2.从右到左
    3.从上到下
    4.从下到上
    5.从左上到右下
    6.从右下到左上
    7.从左下到右上
    8.从右上到左下
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char puzzle[4][4] = {
    {'t', 'h', 'i', 's'},
    {'w', 'a', 't', 's'},
    {'o', 'a', 'h', 'g'},
    {'f', 'g', 'g', 't'}};

static char *
    dict[4] = {"this", "two", "fat", "that"};

int wordExsit(int x, int y, int dir, int strLen, char *word, int position[][2])
{
    for (int i = 0; i < 4; i++)
    {
        position[i][0] = -1;
        position[i][1] = -1;
    }

    char sword[5];
    int i = 0, j;
    while (i < strLen)
    {
        position[i][0] = x;
        position[i][1] = y;
        sword[i++] = puzzle[x][y];
        sword[i] = '\0';
        for (j = 0; j < 4; j++)
        {
            if (strcmp(sword, dict[j]) == 0)
            {
                strcpy(word, dict[j]);
                return 1;
            }
        }
        switch (dir)
        {
        case 0:
            y++;
            break;
        case 1:
            y--;
            break;
        case 2:
            x++;
            break;
        case 3:
            x--;
            break;
        case 4:
            x++;
            y++;
            break;
        case 5:
            x--;
            y--;
            break;
        case 6:
            x++;
            y--;
            break;
        case 7:
            x--;
            y++;
            break;
        default:
            puts("Direction error.");
            return 0;
        }

        if (x < 0 || y < 0)
            return 0;
    }
    return 0;
}

int main()
{
    char word[5];
    int position[4][2];
    int x, y, dir, strLen;

    for (x = 0; x < 4; x++)
    {
        for (y = 0; y < 4; y++)
        {
            for (dir = 0; dir < 8; dir++)
            {
                for (strLen = 2; strLen < 5; strLen++)
                {
                    if (wordExsit(x, y, dir, strLen, word, position) == 1)
                    {
                        printf("Word: %s\n", word);
                        printf("Position: ");
                        for (int i = 0; i < 4; ++i)
                        {
                            printf("%d,%d ", position[i][0], position[i][1]);
                        }
                        putchar('\n');
                        break;
                    }
                }
            }
        }
    }

    system("pause");
    return 0;
}