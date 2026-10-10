#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
#include <string.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
LinkList Union(LinkList &A, LinkList &B){
    std:: unordered_set<LNode*> st;
    LNode *pa = A->next, *pb = B->next;
    while(pa){
        st.insert(pa);
        pa = pa->next;
    }
    while(pb){
        if(st.count(pb)){
            
            pb = pb->next;
        }
    }
}