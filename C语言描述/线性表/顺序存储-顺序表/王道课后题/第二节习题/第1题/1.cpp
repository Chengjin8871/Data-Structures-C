#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
bool Del_x_1(LinkList &L, int x){
if(L == NULL)  return false;
    LNode *p = L->next,*q,*pre=L;
    while(p != NULL){
       if(p->data == x){
        q = p;
        pre->next = q->next;
        free(q);
        pre = p;
        p = p->next;}
        else{
            p = p->next;
            pre = p;
        }
    }
    return true;
}
int main(){
    LinkList L;
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    Del_x_1(L, 1);
    return 0;
}
