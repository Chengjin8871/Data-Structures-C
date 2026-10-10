#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;
int Pattern(LinkList h1, LinkList h2) {
	//本题假设不含头结点  判断h2链表是否是h1链表的一个连续子串
	LNode* p = h1, * q = h2;
	LNode* pre = p;
	while (p && q) {
		if (p->data == q->data) {
			p = p->next;
			q = q->next;
		}
		else {
			q = h2;
			pre = pre->next;
			p = pre;
		}
	}
	if (!q)
		return 1;
	else
		return 0;
}
int main() {
	int n, m;
	LinkList h1, h2;
	h1 = (LinkList)malloc(sizeof(LNode));
	h2 = (LinkList)malloc(sizeof(LNode));
	h1->next = NULL;
	h2->next = NULL;
	LNode* p = h1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
        LNode* node = (LNode*)malloc(sizeof(LNode));
        scanf("%d", &node->data);
        node->next = NULL;
        p->next = node;
        p = node;
    }
}
