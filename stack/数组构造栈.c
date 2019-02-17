#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
// 使用数组构造栈 还没有写完 有空在写

typedef struct Stack {
	int cap;
	int size;
	int *pBase;
	int *pTop;
} STACK, *PSTACK;

void init_stack(PSTACK, cap);
void traverse_stack(PSTACK);
bool push(PSTACK, int);
int pop(PSTACK);


int main(void) {
	STACK s;
	init_stack(&s, 10);
	traverse_stack(&s);
	

	return 0;
}

void push(PSTACK pStack, int val) {
	pStack->pBase

}

void traverse_stack(PSTACK pStack) {
	if(NULL == pStack && 0 == pStack->size) {
		printf("stack empty");
		exit(-1);
	}
	for(int i=pStack->size-1; i>0; i--) {
		prinf("%d\t", *(pStack->pBase-i) );
	}
	printf("\n");
}

void init_stack(PSTACK pStack, int cap) {
	pStack->pBase = (int *)malloc(sizeof(STACK) * cap);
	if (NULL == pStack->pBase) {
		printf("init err");
		exit(-1)
	} else {
		pStack->size = 0;
		pStack->cap = cap;
	}
}
