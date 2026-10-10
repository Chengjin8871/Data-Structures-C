#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unordered_set>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
LinkList Union(LinkList &A, LinkList &B){
    LNode *pa = A->next, *pb = B->next;
    LNode *r = A;  //r为尾指针
    LNode *q;
    while(pa  && pb){
        if(pa->data == pb->data){
            r->next = pa;
            r = pa;
            pa = pa->next;
            q = pb;
            pb = pb->next;
            free(q);
        }
        else if(pa->data < pb->data){
            q = pa;
            pa = pa->next;
            free(q);
        }
        else{
            q = pb;
            pb = pb->next;
            free(q);
        }
        while(pa){
            q = pa;
            pa = pa->next;
            free(q);
        }
        while(pb){
            q = pb;
            pb = pb->next;
            free(q);
        }
        r->next = NULL;
        free(B);
        return A;
    }
}
int main(){
    LinkList A, B;
    A = (LNode*)malloc(sizeof(LNode));
    B = (LNode*)malloc(sizeof(LNode));
    A->next = NULL;
    B->next = NULL;
    LNode *a1 = (LNode*)malloc(sizeof(LNode));
    LNode *a2 = (LNode*)malloc(sizeof(LNode));
    LNode *a3 = (LNode*)malloc(sizeof(LNode));
    a1->data = 1; a1->next = a2;
    a2->data = 3; a2->next = a3;
    a3->data = 5; a3->next = NULL;
    A->next = a1;
    LNode *b1 = (LNode*)malloc(sizeof(LNode));
    LNode *b2 = (LNode*)malloc(sizeof(LNode));
    LNode *b3 = (LNode*)malloc(sizeof(LNode));
    b1->data = 2; b1->next = b2;
    b2->data = 3; b2->next = b3;
    b3->data = 4; b3->next = NULL;
    B->next = b1;
    printf("A: ");
    for(LNode *p=A->next;p!=NULL;p=p->next){
        printf("%d ",p->data);
    }
    printf("\n");
    printf("B: ");
    for(LNode *p=B->next;p!=NULL;p=p->next){
        printf("%d ",p->data);
    }
    printf("\n");
    Union(A, B);
    printf("A∪B: ");
    for(LNode *p=A->next;p!=NULL;p=p->next){
        printf("%d ",p->data);
    }
    printf("\n");   
}