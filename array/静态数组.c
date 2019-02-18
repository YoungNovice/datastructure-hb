#include <stdio.h>

// 接收数组参数竟然用int *
// 说明在c中数组名代表的是首地址
void Show_Array(int *arr, int len)
{
    arr[3] = 10;
}

int main()
{
    int a[5] = {1, 3, 5, 7, 9};
    Show_Array(a, 5);
    // a[i] == *(a+i) == *(i+a) == i[a]
    printf("a[3] = %d\n", 3[a]);
}
