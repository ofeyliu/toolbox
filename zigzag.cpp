//
//  main.c
//  反向斜对角线打印
//
//  Created by cuixuerui on 15/12/19.
//  Copyright (c) 2015年 cuixuerui. All rights reserved.
//

#include <stdio.h>

/*
一个M行N列的数组，要求反向斜对角线（右上左下）的方式打印该数组。（******）

0	1	2	3
4	5	6	7
8	9	10	11

打印顺序是 0 1 4 2 5 8 3 6 9 7 10 11

*/

int main(int argc, const char * argv[]) {


	int num = 3;
	int** a = new int*[num];
	for (int i = 0; i<num; ++i) {
		a[i] = new int[num];
	}

	int m = num;
	int n = num;
	int count = 0;
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			a[i][j] = count++;
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	/*
	第一层：a[0][0].................... i+j=0
	第二层：a[0][1] a[1][0]............ i+j=1
	第三层：a[0][2] a[1][1] a[2][0].... i+j=2
	第四层：a[0][3] a[1][2] a[2][1].... i+j=3
	第五层：a[1][3] a[2][2]............ i+j=4
	第六层：a[2][3].................... i+j=5

	*/
	num = 0;

	/////////////////优化后的算法////////////////

	printf("*****优化后的算法*****\n");
	int low = 0;   //i的下限
	while (num<(m + n - 1)) {//i+j=5，3*4的数组循环6次

		if (num >= n){ //打印下半部分的时候i的下标开始+1
			low++;
		}
		for (int i = low; i<m; i++) {
			printf("%d ", a[i][num - i]);
			if (num == i) { //列的下标等于0的时候，跳出。
				break;
			}
		}
		printf("\n");//加一个换行可以看得更加明了
		num++;
	}
	/////////////////介绍一种暴力破解办法（穷举法）////////////////
	//简单粗暴，超级好理解

	printf("*****暴力破解办法（穷举法）*****\n");
	int k = 0;
	while (k<(m + n - 1)) {
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				if (i + j == k) {
					printf("%d ", a[i][j]);
				}
			}
		}
		k++;
		printf("\n");
	}

	for (int i = 0; i<m; i++) {
		delete[] a[i];
	}
	delete[] a;
}
