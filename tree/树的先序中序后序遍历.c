# include <stdio.h>
# include <malloc.h>

typedef struct BTNode {
	char data; //数据域
	struct BTNode * pLeft; // 左孩子
	struct BTNode * pRight; // 右孩子
} SBTNODE, *PSBTNODE;

struct BTNode * createTree();
void preTraverse(struct BTNode *);
void inTraverse(struct BTNode *);
void postTraverse(struct BTNode *);

int main(void) {
	struct BTNode *pH = createTree();
	printf("二叉树前序遍历: ");
	preTraverse(pH);
	printf("\n");
	printf("二叉树中序遍历: ");
	inTraverse(pH);
	printf("\n");
	printf("二叉树后序遍历: ");
	postTraverse (pH);
	printf("\n");
	return 0;
}

// 后序遍历
void postTraverse(struct BTNode *p) {
	if (NULL != p->pLeft) {
		postTraverse(p->pLeft);
	}
	if (NULL != p->pRight) {
		postTraverse(p->pRight);
	}
	if (NULL != p) {
		printf("%c\t", p->data);
	}
}

// 中序遍历
void inTraverse(struct BTNode *p) {
	if (NULL != p->pLeft) {
		inTraverse(p->pLeft);
	}
	if (NULL != p) {
		printf("%c\t", p->data);
	}
	if (NULL != p->pRight) {
		inTraverse(p->pRight);
	}
}


void preTraverse(struct BTNode *p) {
	if (NULL != p) {
		printf("%c\t", p->data);
	}
	if (NULL != p->pLeft) {
		preTraverse(p->pLeft);
	}
	if (NULL != p->pRight) {
		preTraverse(p->pRight);
	}
}

// 静态构造 简单些 
// 如果用动态构造则需要 用递归实现 还会产生很多空节点
struct BTNode * createTree() {
	struct BTNode * pA = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pB = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pC = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pD = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pE = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pF = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pG = (struct BTNode *)malloc(sizeof(struct BTNode));

	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';
	pF->data = 'F';
	pG->data = 'G';
	
	pA->pLeft = pB;
	pA->pRight = pC;
	pB->pLeft = pB->pRight = NULL;
	pC->pLeft = pD;
	pC->pRight = pE;
	pD->pLeft = pF;
	pD->pRight = NULL;
	pE->pLeft = pG;
	pE->pRight = NULL;
	pF->pLeft = pF->pRight = NULL;
	pG->pLeft = pG->pRight = NULL;
	return pA;
}

