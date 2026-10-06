#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
LinkList Del_Same_2(LinkList &L){
    LNode *r = L, *p = L->next;
    r->next = p;
    r = p;
    p = p->next;
    while(p != NULL){
        if(r->data != p->data){
            r->next = p;
            r = p;
            p = p->next;
        }

        else{
            LNode *q = p;
            p = p->next;
            r->next = p;     //r的next指针存放q的后继结点来断开q结点，以便后面free删除q结点
            free(q);        }
    }
    return L;
}
int main(){
    LinkList L;
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *a = (LNode*)malloc(sizeof(LNode));
    LNode *b = (LNode*)malloc(sizeof(LNode));
    LNode *c = (LNode*)malloc(sizeof(LNode));
    LNode *d = (LNode*)malloc(sizeof(LNode));
    a->data = 1; a->next = b;
    b->data = 2; b->next = c;
    c->data = 2; c->next = d;
    d->data = 3; d->next = NULL;
    L->next = a;
    printf("删除前：");
    for(LNode *p=L->next;p!=NULL;p=p->next){
        printf("%d ",p->data);
    }
    printf("\n");
    Del_Same_2(L);
    printf("删除后：");
    for(LNode *p=L->next;p!=NULL;p=p->next){
        printf("%d ",p->data);
    }
    printf("\n");
}