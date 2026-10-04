#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
LNode* FindCommon_4(LinkList A, LinkList B){
    LNode *p = A->next;
    while(p != NULL){
        LNode *q = B->next;
        while(q != NULL){
            if(p == q)
                return p;
            q = q->next;
        } p = p->next;
    }
    return NULL;
}
int main(){
    LinkList A = (LinkList)malloc(sizeof(LNode));
    LinkList B = (LinkList)malloc(sizeof(LNode));
    A->next = NULL;
    B->next = NULL;
    LNode *a = (LNode*)malloc(sizeof(LNode));
    LNode *b = (LNode*)malloc(sizeof(LNode));
    LNode *c = (LNode*)malloc(sizeof(LNode));
    a->data = 1; a->next = b;
    b->data = 2; b->next = c;
    c->data = 3; c->next = NULL;
    A->next = a;
    LNode *e = (LNode*)malloc(sizeof(LNode));
    LNode *f = (LNode*)malloc(sizeof(LNode));
    e->data = 4; e->next = f;
    f->data = 5; f->next = c;
    B->next = e;
    LNode *p=FindCommon_4(A,B);
    if(p != NULL)
        printf("公共结点的数据为：%d\n",p->data);
    else
        printf("没有公共结点\n");
}