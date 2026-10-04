#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>    //无序哈希集合函数库 属于C++标准库的内容
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
LinkList FindCommon_3(LinkList A, LinkList B){
    LNode *p = A->next, *q = B->next;
    //创建一个存放指针的无序哈希集合
    unordered_set<LNode*>st;
    while(p != NULL){
        st.insert(p);
        p = p->next;
    }
    while(q != NULL){
        if(st.count(q))
        return q;
        q = q->next;        
    }return NULL;
}
int main(){
    
}
