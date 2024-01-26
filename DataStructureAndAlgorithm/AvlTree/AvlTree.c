#include <stdio.h>
#include <stdlib.h>
#include "AvlTree.h"

struct AvlNode{
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};