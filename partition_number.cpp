#include<iostream>
using namespace std;
// 存储可行解
int a[100];
// 输出一个可行解
void Output(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
// 验证当前解是否可行
bool IsOk(int* a, int curIndex, int curValue)
{
	for (int i = 0; i < curIndex; ++i)
		if (a[i] == curValue)
			return false;
	return true;
}
// 对自然数n进行拆分，t用来控制拆分个数
void Partition(int n, int t, int *b)
{
	if (n < 0)
		return;
	if (n == 0) // 找到一个拆分
		Output(a, t); //输出之
	else
	{
		for (int i = 0; i < n; i++)
		{
			a[t] = b[i];
			if (IsOk(a, t, b[i]))
				Partition(n - b[i], t + 1, b);
		}
	}
}
int main(void)
{
	// 拆分子数的集合，相当于各个背包党重量。可根据题目自行设定
	int b[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	// 背包容量为10，从b中选若干件物品，使这些物品总量为10
	Partition(10, 0, b);
	system("pause");
	return 0;
}