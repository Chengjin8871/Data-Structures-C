#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
LinkList List_TailInsert(LinkList &L){
    int x;
    LNode *s, *r;
    s = (LNode*)malloc(sizeof(LNode));
    scanf("%d", &x);
    L->next = NULL;
    r = L;
    while(x != 9999){
        s->data = x;
        r->next = s;
        r = s;
        s = (LNode*)malloc(sizeof(LNode));
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}
int main(){
    LinkList L;
    L = (LNode*)malloc(sizeof(LNode));
    List_TailInsert(L);
    return 0;
}