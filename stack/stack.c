#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

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
bool pop(PSTACK, int *);
void traverse(PSTACK);
bool empty(PSTACK);
void clear(PSTACK);

// 使用链表 栈
int main(void) {
	STACK s;
	initStack(&s);
	push(&s, 1);
	push(&s, 4);
	push(&s, 2);
	traverse(&s);
	int val;
	if(pop(&s, &val)) {
		printf("pop success value is %d\n", val);
	} else {
		printf("pop failed\n");
	}
	traverse(&s);
	clear(&s);
	traverse(&s);
	return 0;
}

void clear(PSTACK s) {
	PNODE p = s->pTop;
	while (p != s->pBottom) {
		PNODE q = p->pNext;
		free(p);
		p = q;
	}
	s->pTop = s->pBottom;
}

bool empty(PSTACK s) {
	if (s->pTop == s->pBottom)
		return true;
	else 
		return false;
}

bool pop(PSTACK s, int *pVal) {
	if (empty(s)) {
		return false;
	}
	PNODE pTemp = s->pTop;
	s->pTop = s->pTop->pNext;
	*pVal = pTemp->data;
	free(pTemp);
	pTemp = NULL;
	return true;
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
		s->pTop->pNext = NULL;
		s->pTop->data = -1;
	}
}
