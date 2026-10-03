#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

bool Del_min_2(LinkList &L) {
    if (L == NULL || L->next == NULL) return false;

    LNode *pre = L;
    LNode *p = L->next;
    LNode *minp = p;
    LNode *minpre = pre;

    while (p != NULL) {
        if (p->data < minp->data) {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }

    minpre->next = minp->next;
    free(minp);
    return true;
}

int main() {
    LinkList L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;

    LNode *a = (LNode *)malloc(sizeof(LNode));
    LNode *b = (LNode *)malloc(sizeof(LNode));
    LNode *c = (LNode *)malloc(sizeof(LNode));

    a->data = 5; a->next = b;
    b->data = 2; b->next = c;
    c->data = 7; c->next = NULL;

    L->next = a;

    printf("删除前：");
    for (LNode *p = L->next; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
    printf("\n");

    Del_min_2(L);

    printf("删除后：");
    for (LNode *p = L->next; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
    printf("\n");

    return 0;
}