#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
bool Del_min_1(LinkList &L){
    if(L == NULL || L->next == NULL) return false;
    LNode *p = L->next,*pre = L,*q;
    LNode *minp = p,*minpre = pre;
    while(p->next != NULL){
       pre = p;
        p = p->next;
        if(p->data < minp->data){
            minp = p;
            minp = pre;
        }
    }
    if(minp->data > p->next->data){
        minp = p->next;
    }
    minpre->next = minp->next;
    free(minp);
    return true;
}
int main(){
    LinkList L;
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    Del_min_1(L);
    return 0;
}