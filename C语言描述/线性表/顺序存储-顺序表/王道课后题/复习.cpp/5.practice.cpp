#include <stdio.h>
#define MAXSIZE 100
typedef int ElemType;   
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SeqList;
void Delete_same(SeqList &L){
	if(L.length==0)
	return ;
	int k=0,i;
	for(i=1;i<L.length;i++){
		if(L.data[k]!=L.data[i])
		L.data[++k]=L.data[i];
	}
	L.length=k;
	return;
}
int main(){
    SeqList L;
    L.length=10;
    ElemType values[] = {1, 2, 2, 3, 4, 4, 5, 6, 6, 7};
    for (int i = 0; i < L.length; i++) {
        L.data[i] = values[i];
    }
    printf("原顺序表为：");
    for(int i=0;i<L.length;i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");
    Delete_same(L);
    printf("删除重复元素后的顺序表为：");
    for(int i=0;i<L.length;i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");
}