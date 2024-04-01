#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Tree.c"

void PreOrder(TreeNode root, int *res, int *resSize);
void PreOrder2(TreeNode root, int res[][10], int *resSize, int *path, int *pathSize);
void PreOrder3(TreeNode root, int res[][10], int *resSize, int *path, int *pathSize);
bool IsSolution(int *path, int *pathSize);
void RecordSolution(int res[][10], int *resSize, int *path, int *pathSize);
bool IsValid(TreeNode root);
void MakeChoice(TreeNode root, int *path, int *pathSize);
void UndoChoice(int *pathSize);
void Backtrack(TreeNode root, int res[][10], int *resSize, int *path, int *pathSize);

int main()
{
    int res[10];
    int resSize = 0;
    TreeNode t1 = MakeEmpty(1);
    TreeNode t2 = MakeEmpty(7);
    TreeNode t3 = MakeEmpty(3);
    TreeNode t4 = MakeEmpty(4);
    TreeNode t5 = MakeEmpty(5);
    TreeNode t6 = MakeEmpty(6);
    TreeNode t7 = MakeEmpty(7);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->left = t6;
    t3->right = t7;

    PreOrder(t1, res, &resSize);

    printf("Example Question 1:\n");
    for (int i = 0; i < resSize; i++)
    {
        printf("%d ", res[i]);
    }
    putchar('\n');

    int res2[10][10];
    int resSize2 = 0;
    int path[10];
    int pathSize = 0;
    PreOrder2(t1, res2, &resSize2, path, &pathSize);

    printf("Example Question 2:\n");
    for (int i = 0; i < resSize2; i++)
    {
        for (int j = 0; res2[i][j] != -1; j++)
        {
            printf("%d ", res2[i][j]);
        }
        putchar('\n');
    }

    int res3[10][10];
    int resSize3 = 0;
    int path2[10];
    int pathSize2 = 0;
    // PreOrder3(t1, res3, &resSize3, path2, &pathSize2);
    Backtrack(t1, res3, &resSize3, path2, &pathSize2);
    printf("Example Question 3:\n");
    for (int i = 0; i < resSize3; i++)
    {
        for (int j = 0; res3[i][j] != -1; j++)
        {
            printf("%d ", res3[i][j]);
        }
        putchar('\n');
    }

    system("Pause");
    return 0;
}

bool IsSolution(int *path, int *pathSize)
{
    return pathSize > 0 && path[(*pathSize) - 1] == 7;
}

void RecordSolution(int res[][10], int *resSize, int *path, int *pathSize)
{
    int i;
    for (i = 0; i < *pathSize; i++)
    {
        res[*resSize][i] = path[i];
    }
    res[*resSize][i] = -1;
    (*resSize)++;
}

bool IsValid(TreeNode root)
{
    return root != NULL && root->val != 3;
}

void MakeChoice(TreeNode root, int *path, int *pathSize)
{
    path[(*pathSize)++] = root->val;
}

void UndoChoice(int *pathSize)
{
    (*pathSize)--;
}

void Backtrack(TreeNode root, int res[][10], int *resSize, int *path, int *pathSize)
{
    if (IsSolution(path, pathSize))
    {
        RecordSolution(res, resSize, path, pathSize);
    }
    if (IsValid(root) == true)
    {
        MakeChoice(root, path, pathSize);
        Backtrack(root->left, res, resSize, path, pathSize);
        Backtrack(root->right, res, resSize, path, pathSize);
        UndoChoice(pathSize);
    }
}

void PreOrder3(TreeNode root, int res[][10], int *resSize, int *path, int *pathSize)
{
    if (root == NULL || root->val == 3)
        return;
    path[(*pathSize)++] = root->val;
    if (root->val == 7)
    {
        int i;
        for (i = 0; i < *pathSize; ++i)
        {
            res[*resSize][i] = path[i];
        }
        res[*resSize][i] = -1;
        (*resSize)++;
    }
    PreOrder3(root->left, res, resSize, path, pathSize);
    PreOrder3(root->right, res, resSize, path, pathSize);
    (*pathSize)--;
}

void PreOrder2(TreeNode root, int res[][10], int *resSize, int *path, int *pathSize)
{
    if (root == NULL)
        return;
    path[(*pathSize)++] = root->val;
    if (root->val == 7)
    {
        int i;
        for (i = 0; i < *pathSize; ++i)
        {
            res[*resSize][i] = path[i];
        }
        res[*resSize][i] = -1;
        (*resSize)++;
    }
    PreOrder2(root->left, res, resSize, path, pathSize);
    PreOrder2(root->right, res, resSize, path, pathSize);
    (*pathSize)--;
}

void PreOrder(TreeNode root, int *res, int *resSize)
{
    if (root == NULL)
    {
        return;
    }
    if (root->val == 7)
    {
        res[(*resSize)++] = root->val;
    }
    PreOrder(root->left, res, resSize);
    PreOrder(root->right, res, resSize);
}