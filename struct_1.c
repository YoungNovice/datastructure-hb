#include <stdio.h>
#include <string.h>

struct Student {
    int sid;
    char name[200];
    int age;
};

int main()
{
    struct Student st = {200, "杨选", 25};
    printf("%d %s %d\n", st.sid, st.name, st.age);

    st.sid = 300;
    strcpy(st.name, "nihao");
    st.age = 30;
    printf("%d %s %d\n", st.sid, st.name, st.age);
}
