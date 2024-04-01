#ifndef _Tree_H

typedef int ElementType;

struct treeNode;
typedef struct treeNode* TreeNode;

TreeNode MakeEmpty(ElementType E);
ElementType Retrieve(TreeNode T);
void FatalError(char* S);

#endif