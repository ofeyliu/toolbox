/*���ӣ�https://www.nowcoder.com/questionterminal/a22dd98b3d224f2bb89142f8acc2fe57?tocommentid=1234209
��Դ��ţ����

ƽ������n������, ��i�����ε����½�����Ϊ(x1[i], y1[i]), ���Ͻ�����Ϊ(x2[i], y2[i])��
����������߶�������й�����������Ϊ�������໥�ص���(�����Ǳ߽�ͽ���)��
��������ƽ�����ص������������ĵط�, �ж��ٸ������໥�ص�

����������С�
��һ�а���һ������n(2 <= n <= 50), ��ʾ���εĸ�����
�ڶ��а���n������x1[i](-10 ^ 9 <= x1[i] <= 10 ^ 9), ��ʾ���½ǵĺ����ꡣ
�����а���n������y1[i](-10 ^ 9 <= y1[i] <= 10 ^ 9), ��ʾ���½ǵ������ꡣ
�����а���n������x2[i](-10 ^ 9 <= x2[i] <= 10 ^ 9), ��ʾ���Ͻǵĺ����ꡣ
�����а���n������y2[i](-10 ^ 9 <= y2[i] <= 10 ^ 9), ��ʾ���Ͻǵ������ꡣ

������� :
���һ��������, ��ʾ���ĵط��ж��ٸ������໥�ص�, ������ζ��������ص�, ���1��
ʾ��1
����
2
0 90
0 90
100 200
100 200
���
2
*/

//*******************************���*****************************************
//ע���ж��ص������������ĵط����������п��ܰ����ĵ�, ��һ���ж��پ��ΰ�����
//������A��B����B��C��������A����C��-- - Bͬʱ��A, C��, �����ص�����ֻΪ1

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