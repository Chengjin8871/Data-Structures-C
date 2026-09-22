#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
LinkList List_HeadInsert(LinkList &L){
    int x; 
    LNode *s;
    s = (LNode*)malloc(sizeof(LNode));
    scanf("%d", &x);
    while(x != 9999){
        s->data = x;
        s->next = L->next;
        L->next = s;
        s = (LNode*)malloc(sizeof(LNode));
        scanf("%d", &x);
    }
    return L;
}
int main(){
    LinkList L;
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    List_HeadInsert(L);
    return 0;
}