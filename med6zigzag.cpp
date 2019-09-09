#include<iostream>
#include<string>
using namespace std;

int main()
{
	string test("abcdefghijkl");
	string result("");
	int N = test.length();
	int M = 4;
	for (int i = 0;i < M;++i)
	{
		
		if (i == 0)
		{
			result += test[i];
			int j = 1;
			while ((i + (2 * M - 2)*(j)) < N)
			{
				result += test[i + (2 * M - 2)*j];
				j++;
			}
				
		}
		if (i > 0 && i != M - 1)
		{
			result += test[i];
			int j = 1;
			while ((i + (2 * M - 2)*(j)) < N)
			{
				result += test[i + (M - 1 - i) * 2*j];
				result += test[i + (2 * M - 2)*j];
				j++;
			}
			if ((i + (M - 1 - i) * 2 +(M-1)*2*(j-1) )< N)
				result += test[i + (M - 1 - i) * 2 + (M - 1) * 2 * (j - 1)];
		}
		if (i == M - 1)
		{
			result += test[i];
			int j = 1;
			while ((i + (2 * M - 2)*(j)) < N)
			{
				result += (test[i + (2 * M - 2)*(j)]);
				j++;
			}
				
		}
	}
	cout << result << endl;
	return 0;
}