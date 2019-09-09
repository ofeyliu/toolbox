/*链接：https://www.nowcoder.com/questionterminal/a22dd98b3d224f2bb89142f8acc2fe57?tocommentid=1234209
来源：牛客网

平面内有n个矩形, 第i个矩形的左下角坐标为(x1[i], y1[i]), 右上角坐标为(x2[i], y2[i])。
如果两个或者多个矩形有公共区域则认为它们是相互重叠的(不考虑边界和角落)。
请你计算出平面内重叠矩形数量最多的地方, 有多少个矩形相互重叠

输入包括五行。
第一行包括一个整数n(2 <= n <= 50), 表示矩形的个数。
第二行包括n个整数x1[i](-10 ^ 9 <= x1[i] <= 10 ^ 9), 表示左下角的横坐标。
第三行包括n个整数y1[i](-10 ^ 9 <= y1[i] <= 10 ^ 9), 表示左下角的纵坐标。
第四行包括n个整数x2[i](-10 ^ 9 <= x2[i] <= 10 ^ 9), 表示右上角的横坐标。
第五行包括n个整数y2[i](-10 ^ 9 <= y2[i] <= 10 ^ 9), 表示右上角的纵坐标。

输出描述 :
输出一个正整数, 表示最多的地方有多少个矩形相互重叠, 如果矩形都不互相重叠, 输出1。
示例1
输入
2
0 90
0 90
100 200
100 200
输出
2
*/

//*******************************解答*****************************************
//注意判断重叠矩形数量最多的地方：遍历所有可能包含的点, 看一下有多少矩形包含它
//误区：A和B交，B和C交，但是A不和C交-- - B同时和A, C交, 但是重叠区域只为1

#include<iostream>
#include<vector>
#include<string>
#include <cstdio>

using namespace std;
struct rect{
	int x1;
	int y1;
	int x2;
	int y2;
};

bool isOverlap(rect& m, rect& n)
{

	return true;
}

int main()
{
	int n;
	vector<rect> rects;
	cin >> n;
	int *x1 = new int(n);
	int *y1 = new int(n);
	int *x2 = new int(n);
	int *y2 = new int(n);
	rect tmp;
	for (int i = 0; i < n; i++)
		cin >> x1[i];
	for (int i = 0; i < n; i++)
		cin >> y1[i];
	for (int i = 0; i < n; i++)
		cin >> x2[i];
	for (int i = 0; i < n; i++)
		cin >> y2[i];
	int *x = new int(n * 2);
	int *y = new int(n * 2);
	x = x1;
	y = y1;
	for (size_t i = 0; i < n; i++)
	{
		x[i + n] = x2[i];
		y[i + n] = y2[i];
	}

	int num = 0;
	int result = 1;
	/*for (size_t i = 0; i < 2 * n; i++)
	{
	cout << x[i] << endl;
	}*/
	for (size_t i = 0; i < n * 2; i++)
	{
		for (size_t j = 0; j < n * 2; j++)
		{
			for (size_t k = 0; k < n; k++)
			{
				num = 0;
				if (x[i]>x1[k] && y[j] >= y1[k] && x[i] <= x2[k] && y[j] <= y2[k])
					num++;
			}
			result = num > result ? num : result;
		}
	}
	cout << result << endl;
	system("pause");
	return 0;
}