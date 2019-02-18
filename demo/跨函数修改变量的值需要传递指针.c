#include <stdio.h>

void f(int * p);

// 想跨函数修改变量的内容 需要通过传递变量的指针才行
// 因为方法的调用是值拷贝
int main()
{
    int i = 9;
    f(&i);
    printf("i = %d\n", i);
    return 0;
}

void f(int * p)
{
    *p = 100;
}