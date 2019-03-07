# include <stdio.h>

/* 
快速排序
9  0  8  10  -5  2

先找第一个元素的9确切位置 这个位置的左右两边分成两半 
在升序条件下 左边的数都小于9 右边的数都大于9 但是他们的顺序还是乱序的 再排好 左边和右边的 

定义 low high 两个指针 分别指向边位置 当high的数字小时需要放到底位 当low的数字大时需要放到高位
交换完成后需要保证 9的左边都是小于9的数字 9的右边都是大于9的数字

*/
int FindPos(int *a, int low, int high) {
	int val = a[low];
	while (low < high) {
		while(low < high && a[high] >= val) {
			--high;
		}
		a[low] = a[high];

		while(low < high && a[low] <= val) {
			++low;
		}
		a[high] = a[low];
	}
	a[low] = val;
	return high;
}

 
void QuickSort(int *a, int low, int high) {
	int pos;
	if (low < high) {
		pos = FindPos(a, low, high);
		QuickSort(a, low, pos-1);
		QuickSort(a, pos+1, high);
	}
}

int main(void) { 
	int a[9] = {2, 1, 0, 5, 4, 3, 123, 153, -100};
	int i;
	QuickSort(a, 0, 8);

	for (i=0; i<9; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
