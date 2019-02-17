#include <stdio.h>

int total(int n) {
	if (n == 1)
		return 1;
	return n + total(n-1);
}

int main(void) {
	printf("%d\n", total(100));

	return 0;
}
