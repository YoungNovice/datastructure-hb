#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int data; // 节点的数据域
    struct Node *pNext; // 指向下一个节点的指针
} NODE, *PNODE;

PNODE create_list(void);
void traverse_list(PNODE);
bool is_empty(PNODE);
int length_list(PNODE);
bool insert_list(PNODE, int index, int val);
bool delete_list(PNODE, int index, int *val);
void bubber_sort_list(PNODE);
void exchange_sort_list(PNODE);

int main()
{
    PNODE pHead = NULL;
    // 创建一个链表 并返回头节点
    pHead = create_list();
    traverse_list(pHead);
    if (is_empty(pHead))
        printf("empty list\n");
    else
        printf("not empty list\n");

    printf("list length is %d\n", length_list(pHead));

//   bubber_sort_list(pHead);

  //  exchange_sort_list(pHead);
  //  traverse_list(pHead);
//	insert_list(pHead, 2, 10);
    traverse_list(pHead);
	int val;
	delete_list(pHead, 5, &val);
	printf("deleted val is %d\n", val);
    traverse_list(pHead);
}

// 
bool delete_list(PNODE pHead, int index, int *val) {
	PNODE pPrev = pHead;
	int length = length_list(pHead);
	if (length < index) {
		printf("out of bounds");
		exit(-1);
	}
	for (int i=0; i < index; i++) {
		pPrev = pPrev->pNext;
	}
	PNODE pCurrent = pPrev->pNext;
	pPrev->pNext = pCurrent->pNext;
	*val = pCurrent->data;
	free(pCurrent);
}

bool insert_list(PNODE pHead, int index, int val) {
	PNODE pTemp = pHead;
	int length = length_list(pHead);
	if (length < index) {
		printf("out of bounds");
		exit(-1);
	}
	for (int i=0; i<index; i++) {
		pTemp = pTemp->pNext;
	}
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew) {
		printf("malloc error");
		exit(-1);
	}
	pNew->data = val;
	pNew->pNext = pTemp->pNext;
	pTemp->pNext = pNew;
}

// 第一轮交换最小值在第一个位置
// 第二轮交换次最小值在第二个位置....
void exchange_sort_list(PNODE pHead) {
    PNODE p, q;
    for(p = pHead->pNext; NULL != p->pNext; p = p->pNext) {
        for (q = p->pNext; NULL != q; q = q->pNext) {
            if (p->data > q->data) {
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}



// 奇葩写法
// 实际上是根据冒泡写出来的 有len-1轮比较 内部从j=i开始比较后面的j和j+1之间的
void bubber_sort_list(PNODE pHead) {
    PNODE pOut = pHead->pNext;
    while (NULL != pOut->pNext) {
        PNODE pIn = pOut->pNext;
        while (NULL != pIn) {
            if (pOut->data > pIn->data) {
                int temp = pOut->data;
                pOut->data = pIn->data;
                pIn->data = temp;
            }
            pIn = pIn->pNext;
        }
        pOut = pOut->pNext;
    }
}


int length_list(PNODE pHead) {
    int len = 0;
    PNODE pTemp = pHead->pNext;
    while (NULL != pTemp) {
        len++;
        pTemp = pTemp->pNext;
    }
    return len;
}

bool is_empty(PNODE pHead) {
    return NULL == pHead->pNext;
}

PNODE create_list(void) {
    int len; // 有效节点的个数
    int i; //
    int val; // 用户输入的临时节点的值

    // 不存放数据的头节点
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    // 最后的一个节点
    PNODE pTail = pHead;
    pTail->pNext = NULL;
    if  (NULL == pHead) {
        printf("mall error program exit!\n");
        exit(-1);
    }

    printf("len = \n");
    scanf("%d", &len);

    for (i = 0; i < len; ++i) {
        printf("the %d th node val is :\n", i+1);
        scanf("%d", &val);

        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if (NULL == pNew) {
            printf("mall error program exit!\n");
            exit(-1);
        }
        // pNew数据初始化
        pNew->data = val;
        pNew->pNext = NULL;
        // 挂载到tail
        pTail->pNext = pNew;
        pTail = pNew;
    }
    return pHead;
}

void traverse_list(PNODE pHead) {
    if (NULL == pHead) {
        return;
    }
    PNODE next = pHead->pNext;
    while (NULL != next) {
        printf("%d\t", next->data);
        next = next->pNext;
    }
    printf("\n");
}

/*
 单链表
 双链表 每个节点有两个指针域
 循环链表 最后一个节点的的指针域指向了第一个节点 能通过任何一个节点找到其他所有的节点

 非循环链表

 狭义的算法与数据结构相关 广义的算法与数据结构不相关
 泛型 通过某种技术达到的效果就是：不同的存数方式， 执行的操作是一样的

*/
