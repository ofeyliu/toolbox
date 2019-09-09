#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

//*************************************************************
//函数名：main()
//作用：求二维数组元素所在行和列的最大异或和
//*************************************************************

int main(){
	//freopen("1.in","r",stdin);
	int n, m;
	long long ans = 0;
	cin >> n >> m;
	vector<vector<int>> array;
	for (int i = 0; i < n; i++)
	{
		vector<int> temp;
		for (int j = 0; j < m; j++)
		{
			long long x; 
			cin >> x;
			//scanf_s("%d", &x);
			temp.push_back(x);
			ans ^= x;
		}
		array.push_back(temp);
	}

	long long xor_sum = ans;
	long long max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			long long temp_sum = ans;
			for (int jj = 0; jj < m; jj++)
				temp_sum = temp_sum ^array[i][jj];
			for (int ii = 0; ii < n; ii++)
				temp_sum = temp_sum ^array[ii][j];
			temp_sum ^= array[i][j];
			if (temp_sum>max)
				max = temp_sum;
		}
	}
	cout << max << endl;
	return 0;
}