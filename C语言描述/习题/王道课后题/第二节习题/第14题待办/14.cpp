define_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;
LinkList link(LinkList& L, int k) {
	LNode* p = L; //不带头结点
	int n = 1;
	while (p->next != NULL) {
		p = p->next;
		n++;
	}
	p->next = L;
	int i = n - k;
	while (i > 0) {
		p = p->next;
	}
	L = p->next;
	p->next = NULL; //将环断开
	return L;
}
int main() {
	LinkList L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	int n, k;
	printf("请输入结点个数和删除结点序号：");
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		LNode* s = (LNode*)malloc(sizeof(LNode));
        s->next = L->next;
        L->next = s;
        scanf("%d", &s->data);
	}
    LinkList L1 = link(L, k);
    printf("删除结点后，链表为：");
    while (L1->next != NULL) {
        printf("%d ", L1->next->data);
        L1 = L1->next;
    }
    printf("\n");
    return 0;   
}