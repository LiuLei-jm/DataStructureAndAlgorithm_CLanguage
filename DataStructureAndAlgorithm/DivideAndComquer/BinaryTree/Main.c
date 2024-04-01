#include <stdio.h>
#include <stdlib.h>
#include "Tree.c"

#define MAX_SIZE 50

TreeNode dfs(int *preorder, int *inorderMap, int i, int l, int r, int size);
TreeNode BuildTree(int *preorder, int preorderSize, int *inorder, int inorderSize);

int main()
{
    int preorder[5] = {3, 9, 2, 1, 7};
    int inorder[5] = {9, 3, 1, 2, 7};

    TreeNode T = BuildTree(preorder, 5, inorder, 5);
    LevelOrderTraverse(T);

    system("Pause");
    return 0;
}

TreeNode dfs(int *preorder, int *inorderMap, int i, int l, int r, int size)
{
    if (r - l < 0)
        return NULL;
    TreeNode root = malloc(sizeof(struct treeNode));
    root->val = preorder[i];
    root->left = NULL;
    root->right = NULL;
    int m = inorderMap[preorder[i]];
    root->left = dfs(preorder, inorderMap, i + 1, l, m - 1, size);
    root->right = dfs(preorder, inorderMap, i + 1 + m - l, m + 1, r, size);
    return root;
}

TreeNode BuildTree(int *preorder, int preorderSize, int *inorder, int inorderSize)
{
    int *inorderMap = (int *)malloc(sizeof(int) * MAX_SIZE);
    for (int i = 0; i < inorderSize; i++)
    {
        inorderMap[inorder[i]] = i;
    }
    TreeNode root = dfs(preorder, inorderMap, 0, 0, inorderSize - 1, inorderSize);
    return root;
}