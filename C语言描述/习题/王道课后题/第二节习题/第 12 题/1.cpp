#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;
LinkList link(89)