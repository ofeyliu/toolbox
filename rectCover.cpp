#include<iostream>
using namespace std;

int rectCover(int number)
{
	if (number <= 0) return 0;
	if (number == 1) return 1;
	if (number == 2)
		return 2;
	else
		return rectCover(number - 1) + rectCover(number - 2);
}

int a[1000];
int rectCover2(int number)
{
	a[1] = 1;
	a[2] = 2;
	for (int i = 3; i <= number; i++)
		a[i] = a[i - 1] + a[i - 2];
	return a[number];
}

int rectCover3(int number)
{
	if (number <= 0) return 0;
	if (number == 1) return 1;
	if (number == 2) return 2;
	int num1 = 1;
	int num2 = 2;
	int result = 0;
	number = number - 2;
	while (number--){
		result = num1 + num2;
		num1 = num2;
		num2 = result;
	}
	return result;
}

int main()
{
	cout << "递归 " << rectCover(5) << endl;
	cout << "动态规划 " << rectCover2(5) << endl;
	cout << "迭代思想 " << rectCover3(5) << endl;
	cout << "test" << endl;
	system("pause");
}