#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
LinkList Get_Common(LinkList &A, LinkList &B){
    LNode *r =B;
    LNode *p =A->next, *q = B->next;
    while(p != NULL && q != NULL){
        if(p->data != q->data){
            LNode *m  = q;
            q = q->next;
            r->next = q;
            free(m);
        }
        else{
            r->next = q;
            r = q;
            p = p->next;
            q = q->next;
        }
    }r->next = NULL;
    return B;
}
int main(){
    LinkList A = (LinkList)malloc(sizeof(LNode));
    LinkList B = (LinkList)malloc(sizeof(LNode));
    A->next = NULL;
    B->next = NULL;
    LNode *a = (LNode*)malloc(sizeof(LNode));
    LNode *b = (LNode*)malloc(sizeof(LNode));
    LNode *c = (LNode*)malloc(sizeof(LNode));
    LNode *d = (LNode*)malloc(sizeof(LNode));
    a->data = 1; a->next = b;
    b->data = 2; b->next = c;
    c->data = 3; c->next = d;
    d->data = 4; d->next = NULL;
    A->next = a;
    LNode *e = (LNode*)malloc(sizeof(LNode));
    LNode *f = (LNode*)malloc(sizeof(LNode));
    LNode *g = (LNode*)malloc(sizeof(LNode));
    LNode *h = (LNode*)malloc(sizeof(LNode));
    e->data = 2; e->next = f;
    f->data = 3; f->next = g;
    g->data = 4; g->next = h;
    h->data = 5; h->next = NULL;
    B->next = e;
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
    Get_Common(A,B);
    printf("B链表：");
    for(LNode *p=B->next;p!=NULL;p=p->next){
        printf("%d ",p->data);
    }
    printf("\n");
}

    