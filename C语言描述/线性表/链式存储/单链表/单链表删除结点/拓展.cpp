// 题意：找到第 i-1 个结点，然后删除其后继结点（即删除第 i 个结点）
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

bool List_Delete(LinkList &L, int i) {
    if (L == NULL || i < 1 || L->next == NULL)
        return false;

    LNode *p = L;
    int j = 0;

    while (p->next != NULL && j < i - 1) {
        p = p->next;
        j++;
    }

    if (p->next == NULL)
        return false;

    LNode *q = p->next;
    p->next = q->next;
    free(q);
    return true;
}

int main() {
    LinkList L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;

    LNode *a = (LNode *)malloc(sizeof(LNode));
    LNode *b = (LNode *)malloc(sizeof(LNode));
    LNode *c = (LNode *)malloc(sizeof(LNode));
    LNode *d = (LNode *)malloc(sizeof(LNode));

    a->data = 1; a->next = b;
    b->data = 2; b->next = c;
    c->data = 3; c->next = d;
    d->data = 4; d->next = NULL;

    L->next = a;

    printf("删除前：");
    for (LNode *p = L->next; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
    printf("\n");

    List_Delete(L, 3);

    printf("删除后：");
    for (LNode *p = L->next; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
    printf("\n");

    return 0;
}