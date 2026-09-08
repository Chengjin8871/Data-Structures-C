#include <stdio.h>
#define MaxSize 100

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
} SeqList;

/**
 * @brief 删除顺序表中所有值在 [s, t] 范围内的元素。
 *
 * 通过一趟遍历，将不在 [s, t] 区间内的元素向前覆盖，原地压缩数组，
 * 从而删除所有满足 s ≤ data[i] ≤ t 的元素。
 *
 * @param L 待操作的顺序表，修改后其 data 与 length 会同步更新。
 * @param s 区间下界。
 * @param t 区间上界。
 * @return 删除成功返回 true；若顺序表为空或 s ≥ t 则返回 false。
 */
bool Del_s_t(SeqList &L, ElemType s, ElemType t) {
    int i, k = 0;
    if (L.length == 0 || s >= t)
        return false;

    for (i = 0; i < L.length; i++) {
        if (L.data[i] >= s && L.data[i] <= t)
            k++;
        else
            L.data[i - k] = L.data[i];
    }

    L.length = L.length - k;
    return true;
}

int main(void) {
    SeqList L = {{1, 2, 3, 4, 5, 6, 7, 8}, 8};

    printf("删除前：");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");

    Del_s_t(L, 3, 6);

    printf("删除 [3, 6] 后：");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");

    return 0;
}