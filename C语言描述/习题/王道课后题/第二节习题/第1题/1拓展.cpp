#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
bool Del_x_2(LinkList &L,ElemType x){
    LNode *p = L->next, *r = L, *q;   //尾插法要求尾指针初始时指向头指针
if(L == NULL)  return false;
while(p != NULL ){
    if(p->data != x){
    r->next = p;
    r = p;
    p = p->next;}
    else{
       q = p;
       free(q);
       p = p->next;
    }
r->next = NULL;
}
return true;
}
int main(){
    LinkList L;
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    Del_x_2(L, 1);
    return 0;
}
