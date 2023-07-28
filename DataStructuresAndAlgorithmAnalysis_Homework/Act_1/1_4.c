/*
  编写一个程序，使它读入被include语句修饰的一个文件并且输出这个文件
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 105

void process_line(const char *filename, char (*opened)[MAXN]);

int main(int argc, char **argv)
{
    char opened[MAXN][MAXN];
    process_line("string.h", opened);
    int i = 0;
    while (strstr(opened[i], ".h") != NULL)
    {
        printf("%d: %s\n", i + 1, opened[i]);
        i++;
    }
}

void process_line(const char *filename, char (*opened)[MAXN])
{
    static int cnt = 0;
    char filePath[MAXN];
    FILE *fin;
    char line[MAXN];
    char *newfile;
    for (int i = 0; i < cnt; i++)
    {
        if (strcmp(opened[i], filename) == 0)
            return;
    }

    strcpy(filePath, "C:\\msys64\\mingw64\\include\\");
    strcat(filePath, filename);
    fin = fopen(filePath, "r");

    if (fin == NULL)
        return;

    strcpy(opened[cnt], filename);
    cnt++;

    while (fgets(line, MAXN, fin))
    {
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0';
        if (newfile = strstr(line, "#include"))
        {
            char *start = strchr(line, '<');
            if (start == NULL)
            {
                start = strchr(line, '"');
            }
            char temp[MAXN];
            strcpy(temp, start + 1);
            temp[strlen(temp) - 1] = '\0';

            process_line(temp, opened);
        }
    }
}