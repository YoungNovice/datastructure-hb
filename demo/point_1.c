# include <stdio.h>

// 指针对简单的应用
int main()
{
    // p是int*的指针变量 int*表示变量p只能够存储int类型变量的地址
    int *p;
    int i = 10;
    int j;
    // p 保存了i的地址
    p = &i;

    j = *p;
    printf("i = %d j = %d *p = %d\n", i, j, *p);
    return 0;
}
