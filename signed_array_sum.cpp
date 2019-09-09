#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

double myAdd(double t_sum, long long int &pos, long long int &m, bool flag)
{
	if (flag)
	for (double i = pos; i< pos + m; i++)
		t_sum = t_sum + i;
	else
	for (double i = pos; i< pos + m; i++)
		t_sum = t_sum + i * (-1.0);
	return t_sum;
}
int main()
{
	long long int n, m;
	cin >> n >> m;
	double sums = 0;
	//size_t t = n / m;
	if (m == 1)
	{
		cout << n / 2 << endl;
		return 0;
	}
	for (long long int i = 1; i <= n; i = i + m)
	{
		int test = i / m;
		int test2 = test % 2;
		if ((i / m) % 2 == 0)
			sums = myAdd(sums, i, m, false);
		else
			sums = myAdd(sums, i, m, true);
	}
	cout << sums << endl;
}