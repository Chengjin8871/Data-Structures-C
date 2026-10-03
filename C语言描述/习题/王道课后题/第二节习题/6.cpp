#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
LinkList discreat(LinkList &A){
    LinkList B = (LinkList)malloc(sizeof(LNode));
    B->next = NULL;
    LNode *p = A->next, *q, *ra = A;
    while(p != NULL){
        ra->next = p;
        ra = p;
        p = p->next;
        if(p != NULL){
            q = p->next;
            p->next = B->next;
            B->next = p;
            p = q;
        }     
    }
        ra->next = NULL;
        return B; 
}
int main(){
    LinkList A = (LinkList)malloc(sizeof(LNode));
    A->next = NULL;
    LNode *a = (LNode*)malloc(sizeof(LNode));
    LNode *b = (LNode*)malloc(sizeof(LNode));
    LNode *c = (LNode*)malloc(sizeof(LNode));
    LNode *d = (LNode*)malloc(sizeof(LNode));
    a->data = 1; a->next = b;
    b->data = 2; b->next = c;
    c->data = 3; c->next = d;
    d->data = 4; d->next = NULL;
    A->next = a;
    printf("A链表：");
    for(LNode *p=A->next;p!=NULL;p=p->next){
        printf("%d ",p->data);
    }
    printf("\n");
    LinkList B = discreat(A);
    printf("A链表：");
    for(LNode *p=A->next;p!=NULL;p=p->next){
        printf("%d ",p->data);
    }
    printf("\n");
    printf("B链表：");
    for(LNode *p=B->next;p!=NULL;p=p->next){
        printf("%d ",p->data);
    }
    printf("\n");
}