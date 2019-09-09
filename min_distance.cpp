// Example program
#include <iostream>
#include <string>

using namespace std;
#include <stdio.h>
int split(int n, int m)
{
	if (n < 1 || m < 1) return 0;
	if (n == 1 || m == 1) return 1;
	if (n < m) return split(n, n);
	if (n == m) return (split(n, m - 1) + 1);
	if (n > m) return (split(n, m - 1) + split((n - m), m));

}

int minDis(int m[5][5])
{
	int dp[4 + 1][4 + 1];
	dp[0][0] = m[0][0];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 5; j++) {
			if (i == 1) {
				dp[i][j] = dp[i][j - 1] + m[i][j];
			}
			else if (j == 1) {
				dp[i][j] = dp[i - 1][j] + m[i][j];
			}
			else {
				int temp1 = dp[i][j - 1] + m[i][j];
				int temp2 = dp[i - 1][j] + m[i][j];
				int min = temp1<temp2 ? temp1 : temp2;
				dp[i][j] = min;
			}

		}

	}

	return dp[5-1][5 - 1];
}


int main()
{
	//int a = split(6,6);
	//cout<<a<<endl;
	int martix[5][5] = { { 0, 0, 0, 0, 0 },
								 { 0, 1, 3, 5, 9 },
								 { 0, 8, 1, 3, 2 },
								 { 0, 5, 0, 6, 1 },
								 { 0, 8, 8, 4, 0 } };
	cout << minDis(martix) << endl;
}
