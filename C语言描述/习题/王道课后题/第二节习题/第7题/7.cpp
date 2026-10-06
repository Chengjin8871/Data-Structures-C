#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
LinkList Del_Same(LinkList &L){
    LNode *p = L->next;  //p为扫描工作指针
    while(p->next != NULL){
          LNode *q = p->next;
          if(p->data == q->data){
            p->next = q->next;
            free(q);
          }
          else
          p = p->next;
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
    Del_Same(L);
    printf("删除后：");
    for(LNode *p=L->next;p!=NULL;p=p->next){
        printf("%d ",p->data);
    }
    printf("\n");
}