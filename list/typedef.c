#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef  int INT;

typedef struct People {
    int sid;
    char name[200];
    char sex;
} ST, *PST;

int main()
{
     ST people;
     PST pst = &people;
     pst->sid = 1;
     pst->sex = 'm';
     strcpy(pst->name, "AlanYoung");

     printf("%d, %s, %c\n", pst->sid, pst->name, pst->sex);

}
