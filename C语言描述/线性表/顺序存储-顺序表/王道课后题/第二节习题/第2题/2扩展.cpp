#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
bool Del_min_3 (LinkList &L){
    if(L==NULL) return false;
    LNode *p = L->next;
    LNode *q,*minp = p;
    while(p != NULL){
        if(p->data < minp->data){
            minp = p;
        }
        p = p->next;
    }
    L->data = minp->data;
    q = L->next;
    L->next = q->next;
    free(q);
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

    Del_min_3(L);

    printf("删除后：");
    for (LNode *p = L->next; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
    printf("\n");

    return 0;
}