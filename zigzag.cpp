//
//  main.c
//  ����б�Խ��ߴ�ӡ
//
//  Created by cuixuerui on 15/12/19.
//  Copyright (c) 2015�� cuixuerui. All rights reserved.
//

#include <stdio.h>

/*
һ��M��N�е����飬Ҫ����б�Խ��ߣ��������£��ķ�ʽ��ӡ�����顣��******��

0	1	2	3
4	5	6	7
8	9	10	11

��ӡ˳���� 0 1 4 2 5 8 3 6 9 7 10 11

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
	��һ�㣺a[0][0].................... i+j=0
	�ڶ��㣺a[0][1] a[1][0]............ i+j=1
	�����㣺a[0][2] a[1][1] a[2][0].... i+j=2
	���Ĳ㣺a[0][3] a[1][2] a[2][1].... i+j=3
	����㣺a[1][3] a[2][2]............ i+j=4
	�����㣺a[2][3].................... i+j=5

	*/
	num = 0;

	/////////////////�Ż�����㷨////////////////

	printf("*****�Ż�����㷨*****\n");
	int low = 0;   //i������
	while (num<(m + n - 1)) {//i+j=5��3*4������ѭ��6��

		if (num >= n){ //��ӡ�°벿�ֵ�ʱ��i���±꿪ʼ+1
			low++;
		}
		for (int i = low; i<m; i++) {
			printf("%d ", a[i][num - i]);
			if (num == i) { //�е��±����0��ʱ��������
				break;
			}
		}
		printf("\n");//��һ�����п��Կ��ø�������
		num++;
	}
	/////////////////����һ�ֱ����ƽ�취����ٷ���////////////////
	//�򵥴ֱ������������

	printf("*****�����ƽ�취����ٷ���*****\n");
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
