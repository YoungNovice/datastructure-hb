#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct Queue {
	int *pBase; // 动态数组
	int front; // 队头
	int rear; // 队尾
	int len; // 数组长度
} QUEUE, *PQUEUE;

void init(PQUEUE);
bool empty(PQUEUE);
bool full(PQUEUE);
bool en_queue(PQUEUE, int);
bool out_queue(PQUEUE, int *);
void traverse_queue(PQUEUE);

int main(void) {
	QUEUE q;
	init(&q);
	for (int i=0; i < 4; i++) {
		en_queue(&q, i);
	}
	int val;
	traverse_queue(&q);

	printf("出队列: ");
	for (int i=0; i < 4; i++) {
		out_queue(&q, &val);
		printf("%d\t", val);
	}
	printf("\n");
	return 0;
}

void traverse_queue(PQUEUE pQ) {
	for (int i=pQ->front; i<pQ->rear; i = (i+1)% pQ->len) {
		printf("%d\t", pQ->pBase[i]);
	}
	printf("\n");
}

bool out_queue(PQUEUE pQ, int *pVal) {
	if (empty(pQ))
		return false;

	*pVal = pQ->pBase[pQ->front];
	pQ->front = (pQ->front+1) % pQ->len;
}

// 入队
bool en_queue(PQUEUE pQ, int val) {
	if (full(pQ))
		return false;
	pQ->pBase[pQ->rear] =  val;
	// rear后移
	pQ->rear = (pQ->rear+1) % pQ->len;
	return false;
}

bool empty(PQUEUE pQ) {
	return pQ->front == pQ->rear;
}

bool full(PQUEUE pQ) {
	// 我们假设n-1个就算满 那么rear的下一个就是front
	return (pQ->rear+1) % pQ->len == pQ->front;
}

void init(PQUEUE pQ) {
	int len = 6;
	pQ->pBase = (int *)malloc(sizeof(int) * len);
	pQ->front = 0;
	pQ->rear = 0;
	pQ->len = len;
}

