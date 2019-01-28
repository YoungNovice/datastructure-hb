#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct Arr {
    int len;  //数组的长度
    int cnt; //数组中内容的个数
    int *pBase;  // 数组的干地址
    int inc; // 扩容因子
};

void init_arr(struct Arr *pArr, int length);
bool append_arr(struct Arr *pArr, int val);
bool insert_arr(struct Arr *pArr, int pos, int val);
bool delete_arr(struct Arr *pArr, int pos);
int get(struct Arr *pArr, int index);
bool is_empty(struct Arr *pArr);
bool is_full(struct Arr *pArr);
void sort_arr(struct Arr *pArr);
void show_arr(struct Arr *pArr);
void inversion_arr(struct Arr *pArr);
bool capacity_expand(struct Arr *pArr);

int main()
{
    // 创建一个结构体 但是结构体中的值还没初始化
    struct Arr arr;
    init_arr(&arr, 4);
    append_arr(&arr, 1);
    append_arr(&arr, 5);
    append_arr(&arr, 2);
    append_arr(&arr, 4);
    append_arr(&arr, 3);
    append_arr(&arr, 100);
    append_arr(&arr, 200);
    // 原始
    show_arr(&arr);
    // 排序
    sort_arr(&arr);
    show_arr(&arr);
    // 倒置
    inversion_arr(&arr);
    show_arr(&arr);
    insert_arr(&arr, 0, 520);
    show_arr(&arr);

    int index = 3;
    int val = get(&arr, index);
    printf("array[%d] = %d\n", index, val);

    delete_arr(&arr, 6);
    show_arr(&arr);
}

bool delete_arr(struct Arr *pArr, int pos)
{
    if (pos < 0 || pos > (pArr->cnt)-1)
        return false;

    // pos 到cnt-1的数据前移动一位
    int i;
    for (i = pos;  i < pArr->cnt;) {
        pArr->pBase[i] = pArr->pBase[++i];
    }
    (pArr->cnt)--;
}

bool insert_arr(struct Arr *pArr, int pos, int val)
{
    if (pos < 0 || pos > pArr->cnt)
        return false;

    if (is_full(pArr))
        capacity_expand(pArr);

    // 将pos到最后的数据往后面移动
    for (int i = pArr->cnt; i > pos;) {
        pArr->pBase[i] = pArr->pBase[--i];
    }
    pArr->pBase[pos] = val;
    (pArr->cnt)++;
    return true;
}


bool capacity_expand(struct Arr *pArr)
{
    if (is_full(pArr))
    {
        pArr->pBase = (int *) realloc(pArr->pBase, sizeof(int) * (pArr->len + pArr->inc));
        // 总长度增加inc个
        pArr->len += pArr->inc;
    }
}

int get(struct Arr *pArr, int index)
{
    if (index > pArr->cnt-1)
        return -1;

    return pArr->pBase[index];
}

void sort_arr(struct Arr *pArr)
{
    if (is_empty(pArr))
        return;

    int i;
    int j;
    for (i = 0; i < pArr->cnt - 1; ++i) {
        for (j = 0; j < pArr->cnt - 1 - i; ++j) {
            if (pArr->pBase[j] > pArr->pBase[j+1])
            {
                int temp = pArr->pBase[j];
                pArr->pBase[j] = pArr->pBase[j+1];
                pArr->pBase[j+1] = temp;
            }
        }
    }
}

void init_arr(struct Arr *pArr, int length)
{
    pArr->pBase = (int *)malloc(sizeof(struct Arr) * length);
    if (NULL == pArr->pBase)
    {
        printf("init err");
        exit(-1);
    } else {
        pArr->len = length;
        pArr->cnt = 0;
        pArr->inc = 4;
    }
}

bool append_arr(struct Arr *pArr, int val)
{
    if (is_full(pArr))
        capacity_expand(pArr);

    // 添加数据
    pArr->pBase[(pArr->cnt)++] = val;
    return true;
}

bool is_empty(struct Arr *pArr)
{
    return 0 == pArr->cnt;
}

bool is_full(struct Arr *pArr)
{
    return pArr->len == pArr->cnt;
}


void show_arr(struct Arr *pArr) {
    if (is_empty(pArr))
    {
        printf("没有内容");
    } else {
        for (int i = 0; i < pArr->cnt; ++i) {
            printf("%d \t", pArr->pBase[i]);
        }
        printf("\n");
    }
}

void inversion_arr(struct Arr *pArr)
{
    if (is_empty(pArr))
        return;

    int i;
    for (i = 0; i < pArr->cnt / 2; ++i) {
        int temp = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[pArr->cnt - i -1];
        pArr->pBase[pArr->cnt - i - 1] = temp;
    }
}
