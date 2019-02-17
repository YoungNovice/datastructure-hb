#include <stdio.h>
/*
// x source y middle z target
// 汉诺塔是非线性递归 问题的规模呈次幂及递增
void hannuota(int n, char x, char y, char z) {
	如果就只有一个盘子
		直接将A柱子上的盘子从A移动到C
	否则
		将A柱子上的n-1个盘子借助C移动到B
		直接将第n个盘子 从A移动到C
		将B上的n-1个盘子借助A移动到C
}
*/
void hannuota(int n, char x, char y, char z) {
	if (1 == n) {
		printf("将第%d个盘子从%c移动到%c\n", n, x, z);
	} else {
		hannuota(n-1, x, z, y);
		printf("将第%d个盘子从%c移动到%c\n", n, x, z);
		hannuota(n-1, y, x, z);
	}
}

int main(void) {
	hannuota(3, 'A', 'B', 'C');
	return 0;
}
