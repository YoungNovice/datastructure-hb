# include <stdio.h>

struct S {
	int i;
	int *p;
};

/*
 * 在x64平台下这个程序不会崩溃
 * 因为int*占8个字节 int占四个字节
 *
 * 在x86平台下int *占4个字节
 */
int main(void) {
	struct S s;
	int *p = &s.i;
	p[0] = 4;
	p[1] = 3;
	s.p = p;
	s.p[1] = 1;
	s.p[0] = 2;
	printf("sizeof struct s = %lu\n", sizeof(struct S));
	return 0;
}
