#include <stdio.h>

// 要想修改p的内容这样搞是不行的
void f(int *p);

void f1(int ** q) ;

int main()
{
    int i = 10;
    int *p = &i;

    printf("p = %p\n", p);
    f(p);
    f1(&p);
    printf("p = %p\n", p);

}

void f1(int ** q)
{
    *q = (int *)0xFFFFFF;
}

void f(int * q)
{
    q = (int *)0xFFFFFF;
}
