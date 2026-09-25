#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
bool ListDelete(LinkList &L, int i, ElemType &e){
    if(L == NULL || i < 1)
        return false;
    LNode *p = L;
    int j = 0;
    while(p->next != NULL && j < i - 1){
        p = p->next;
        j++;
    }
    if(p == NULL)
        return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}
int main(){
    LinkList L;
    L = (LNode *)malloc(sizeof(LNode));
    if(L == NULL)
        return 1;
    L->next = NULL;
    ListDelete(L, 1, e);
    ListDelete(L, 2, e);
    ListDelete(L, 3, e);
    for(LNode *p = L->next; p != NULL; p = p->next){
        printf("%d ", p->data);
    }
    printf("\n");
    return 0;
}