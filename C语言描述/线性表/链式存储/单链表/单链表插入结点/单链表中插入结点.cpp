//一般都是后插一个新结点作为单链表第i个结点 
//要检验第i和第i-1个结点是否存在,不能为空
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// 先遍历找出存储第 i-1 个结点的地址的指针，并返回其指针
bool ListInsert(LinkList &L, int i, ElemType e) {   // 在第 i 个位置插入元素 e
    if (L == NULL || i < 1) {
        return false;
    }

    LNode *p = L;
    int j = 0;
    while (p->next != NULL && j < i - 1) {   // 该单链表含头结点作为第 0 个结点，因此 j = i - 1
        p = p->next;
        j++;
    }

    if (p == NULL) {
        return false;
    }

    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) {
        return false;
    }

    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

int main() {
    LinkList L;
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL) {
        return 1;
    }
    L->next = NULL;

    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);

    for (LNode *p = L->next; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
    printf("\n");
    return 0;
}  