#include <iostream>
#include <iomanip>

using namespace std;

#define SIZE 8

int main(int argc, char** argv) {
	int matrix[SIZE][SIZE] = { 0 };
	int a[SIZE][SIZE] = { 0 };

	int i, j, x, y, value = 0;

	int * p;
	p = &matrix[0][0];
	//初始化矩阵
	for (i = 0; i<SIZE * SIZE; i++)
		*p++ = i;

	//打印原始矩阵
	cout << "原始矩阵如下:" << endl;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
			cout << setw(4) << *(*(matrix + i) + j);
		cout << endl;
	}

	i = 0; j = 0;
	//进行Z字编排
	for (x = 0; x < SIZE; x++)
	for (y = 0; y < SIZE; y++)
	{
		*(*(a + i) + j) = *(*(matrix + x) + y);

		if ((i == SIZE - 1 || i == 0) && j % 2 == 0)
		{
			j++;
			continue;
		}

		if ((j == 0 || j == SIZE - 1) && i % 2 == 1)
		{
			i++;
			continue;
		}

		if ((i + j) % 2 == 0)
		{
			i--;
			j++;
		}
		else if ((i + j) % 2 == 1)
		{
			i++;
			j--;
		}
	}

	cout << endl << "经过Z字编排后的矩阵如下:" << endl;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
			cout << setw(4) << *(*(a + i) + j);
		cout << endl;
	}
	return 0;
}
