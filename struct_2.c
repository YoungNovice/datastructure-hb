#include <stdio.h>
#include <string.h>

struct Student
{
    int age;
};

int main()
{
    struct Student st = {12};
    struct Student *pst = &st;
    // pst->age == (*pst).age
    pst->age = 34;
    printf("%d\n", pst->age);

}

