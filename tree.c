#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;

void createTree(TreeNode** T, char* data, int* index){
    char ch;
    ch = data[*index];
    *index += 1;
    if(ch == '#'){
        *T = NULL;
    }
    else{
        *T = (TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        createTree(&(*T)->lchild, data, index);
        createTree(&(*T)->rchild, data, index);
    }
}

void preOrder(TreeNode* T){
    if(T == NULL){
        return ;
    }
    else{
        printf("%c ",T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

void inOrder(TreeNode* T){
    if(T == NULL){
        return ;
    }
    else{
        inOrder(T->lchild);
        printf("%c ", T->data);
        inOrder(T->rchild);
    }
}

void postOrder(TreeNode* T){
    if(T == NULL){
        return ;
    }
    else{
        postOrder(T->lchild);
        postOrder(T->rchild);
        printf("%c ", T->data);
    }
}

int main(){
    TreeNode* T = (TreeNode*)malloc(sizeof(TreeNode));
    int index = 0;
    createTree(&T, "AB#D##CE###", &index);
    
    printf("preOrder:\t");
    preOrder(T);
    putchar('\n');
    printf("inOrder:\t");
    inOrder(T);
    putchar('\n');
    printf("postOrder:\t");
    postOrder(T);
    putchar('\n');
    system("pause");
    return 0;
}