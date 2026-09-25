/**
 对第i-1个结点进行前插操作
 */
#include <stdio.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
bool ListInsert(LinkList &L, int i, ElemType e){
   if( L == NULL || i < 1 ){
      return false;
   } 
   LNode *p = L;
   int j = 0;
   while(p->next != NULL && j < i - 1){
      p = p->next;
      j++;
   }
   if(p == NULL)
      return false;
      LNode *s = (LNode*)malloc(sizeof(LNode));
      s->data = e;
      s->next = p->next;
      p->next = s;
      ElemType tmp = p->data;
      p->data = s->data;
      s->data = tmp;
      return true;
  }