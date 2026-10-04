#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
int length(LinkList L){
    int length = 0 ;
    LNode *p = L->next;
    while(p != NULL){
        length++;
        p = p->next;
    }return length;
}
LinkList FindCommon_2(LinkList A, LinkList B){
    LNode *p = A->next, *q = B->next;
    int LenA = length(A);
    int LenB = length(B);
    int i;
    if(LenA > LenB){
        for(i = 0; i < LenA-LenB; i++)
            p = p->next;
    }
    else if(LenA < LenB){
        for(i = 0; i < LenB-LenA; i++)
            q = q->next;
    }
    while(p != NULL && q != NULL){
        if(p == q)
            return p;
        p = p->next;
        q = q->next;
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
    LNode *p=FindCommon_2(A,B);
    if(p != NULL)
        printf("公共结点的数据为：%d\n",p->data);
    else
        printf("没有公共结点\n");
}