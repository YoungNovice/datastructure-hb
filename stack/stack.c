#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *pNext;
} NODE, *PNODE;

typedef struct Stack {
	PNODE pTop;
	PNODE pBottom;
} STACK, *PSTACK;

void initStack(PSTACK);
void push(PSTACK, int);
int pop(PSTACK);
void traverse(PSTACK);

// 使用链表 栈
int main(void) {
	STACK s;
	initStack(&s);
	push(&s, 1);
	push(&s, 4);
	push(&s, 2);
	traverse(&s);
	int val = pop(&s);
	printf("pop value:%d\n", val);
	traverse(&s);
	return 0;
}

int pop(PSTACK s) {
	if (s->pTop == s->pBottom)
		return;
	PNODE pTemp = s->pTop;
	s->pTop = s->pTop->pNext;
	int val = pTemp->data;
	free(pTemp);
	pTemp = NULL;
	return val;
}

void traverse(PSTACK s) {
	PNODE pTemp = s->pTop; 
	while (pTemp != s->pBottom) {
		printf("%d\t", pTemp->data);
		pTemp = pTemp->pNext;
	}
	printf("\n");
}

void push(PSTACK s, int val) {
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew) {
		printf("pNew malloc err");
		exit(-1);
	}
	pNew->data = val;
	pNew->pNext = s->pTop;
	s->pTop = pNew;
	printf("push value:%d\n", pNew->data);
}

void initStack(PSTACK s) {
	s->pBottom = (PNODE)malloc(sizeof(NODE));
	if (NULL == s->pBottom) {
		printf("init err");
		exit(-1);
	} else {
		s->pTop = s->pBottom;
	}
}
