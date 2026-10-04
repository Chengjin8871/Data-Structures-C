#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>    //无序哈希集合函数库 属于C++标准库的内容
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
LinkList FindCommon_3(LinkList A, LinkList B){
    if(A == NULL || B == NULL)
        return NULL;

    LNode *p = A->next, *q = B->next;
    //创建一个存放指针的无序哈希集合
    std::unordered_set<LNode*> st;
    while(p != NULL){
        st.insert(p);
        p = p->next;
    }
    while(q != NULL){
        if(st.count(q))
            return q;
        q = q->next;
    }
    return NULL;
}
int main(){
    LNode common1 = {4, NULL};
    LNode common2 = {5, NULL};
    common1.next = &common2;

    LNode a = {1, &common1};
    LNode b = {2, &common1};
    LNode headA = {0, &a};
    LNode headB = {0, &b};

    LNode *common = FindCommon_3(&headA, &headB);
    if(common != NULL)
        printf("公共结点的数据为：%d\n", common->data);
    else
        printf("没有公共结点\n");

    return 0;
}
