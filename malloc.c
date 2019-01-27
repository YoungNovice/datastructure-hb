#include <stdio.h>
#include <malloc.h>

int main()
{
    int len;
    printf("请输入数组的长度 len =  ");
    scanf("%d", &len);

    int *pArr = (int *)malloc(sizeof(int) * len);

    for (int i = 0; i < len; ++i) {
        scanf("%d", pArr+i);
    }

    for (int i = 0; i < len; ++i) {
        printf("%d \t", *(pArr+i));
    }

    free(pArr);
}

