#include <stdio.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SeqList;      
bool SearchExchangeInsert(SeqList &L, ElemType e) {
    //折半查找法
    int low=0,high=L.length-1,mid=0;
    // 必须用 while(low<=high)：for 循环在找不到的情况下会继续算 mid，
    // 可能得到负数下标，导致 L.data[-1] 越界崩溃
   /* while(low<=high){
         mid=(low+high)/2;
        if(L.data[mid]==e)
        break;
        else if(L.data[mid]<e)
        low=mid+1;
        else
        high=mid-1;
    }*/
   //不使用while循环，使用for循环
   if(low<=high)    
   {
       mid=(low+high)/2;
   for(int i=0;i<L.length;i++)
    {
          if(L.data[mid]==e)
          break;
          else if(L.data[mid]<e)
          low=mid+1;
          else
          high=mid-1;
    }
    if(low<=high && mid!=L.length-1)   // 查找成功，mid 为命中位置
    {
        {
            ElemType tmp=L.data[mid];
            L.data[mid]=L.data[mid+1];
            L.data[mid+1]=tmp;
        }
        return true;
    }
    if(high<low)    // 查找失败，把 e 插入到下标 low 处
    {
        if(L.length>=MAXSIZE)
        return true;
        for(int i=L.length;i>low;i--)
        L.data[i]=L.data[i-1];
        L.data[low]=e;
        L.length++;
        return true;
    }
}
int main( int argc, char *argv[]) {
        return true;
    }
    return false;
}
int main( int argc, char *argv[]) {
    SeqList L;
    L.length=5;
    for(int i=0;i<L.length;i++)
    L.data[i]=i+1;      // 1 2 3 4 5
    ElemType e=3;
    SearchExchangeInsert(L,e);
    printf("顺序表为：");
    for(int i=0;i<L.length;i++)
    printf("%d ",L.data[i]);
    printf("\n");
    return 0;
}    

