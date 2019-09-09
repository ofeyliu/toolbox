/*
题目：求一个n*m阶矩阵中为1的矩阵最大面积

:例如输入：
0 0 0 0  

1 0 1 1

1 0 1 1

1 0 1 1

那么输出就为 6
*/

#include<iostream>

#include<stack>

#include<cstdio>
#include<vector>

#include<algorithm>
using namespace std;



const int N = int(2e3) + 9;

int a[N][N];

int h[N];

int n, m;

int max_rec(int height[], int n)
{
	if (height == NULL || n == 0)
	{
		return 0;
	}
	int max_area = 0;

	stack<int> stk;

	for (int i = 0; i < n; i++)
	{
		while (!stk.empty() && height[i] <= height[stk.top()])
		{
			int j = stk.top();
			stk.pop();
			int k = stk.empty() ? -1 : stk.top();
			int cur_area = (i - k - 1) * height[j];
			max_area = max(max_area, cur_area);
		}
		stk.push(i);
	}
	while (!stk.empty())
	{
		int j = stk.top();
		stk.pop();
		int k = stk.empty() ? -1 : stk.top();
		int cur_area = (n - k - 1) * height[j];
		max_area = max(max_area, cur_area);
	}
	return max_area;
}

int max_square(vector<vector<int> >& matrix) {
	int row = matrix.size();
	int col = matrix[0].size();

	int max_area = 0;
	int *height = new int[col];
	for (int i = 0; i < col; i++)
	{
		height[i] = 0;
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			height[j] = (matrix[i][j] == 0) ? 0 : height[j] + 1;
		}

		max_area = max(max_area, max_rec(height, col));
	}

	return max_area;
}



int main(){

	vector<vector<int> > matrix;
	vector <int> t_row;
	int temp;
	cin >>n >> m;
		for (int k = 1; k <= n; ++k)
		{
			for (int j = 1; j <= m; ++j)
			{
				cin >> temp;
				t_row.push_back(temp);
			}
			matrix.push_back(t_row);
			t_row.clear();
		}

	int ans = max_square(matrix);
	cout << ans << endl;
	system("pause");
}

