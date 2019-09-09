#include<iostream>
#include<vector>
#include<string>
#include"string.h"

using namespace std;


string string_flip(const string & a)
{
	int n = a.length(); 
	string result;
	for (int i = 0; i < n; i++)
		result.push_back(a[n - i - 1]);
	return result;
}

int count_string(string& input)
{
	int n = input.length();
	//test = string_flip(input);
	int max = 1;
	for (int j = 0; j < n / 2; j++)
	{
		for (int i = 1; i + j< n / 2 + 1; i++)   //j 第几个开始; i 有几个数
		{
			string temp, temp2, temp3;
			//int ii = i;
			for (int ii = j; ii < j + i; ii++)
				temp.push_back(input[ii]);
			for (int jj = j + i; jj < 2 * (i)+j; jj++)
				temp2.push_back(input[jj]);
			for (int jj = j + i - 1; jj < 2 * (i)+j - 1; jj++)
				temp3.push_back(input[jj]);

			string temp_f = string_flip(temp);
			bool flaga = strcmp(temp_f.c_str(), temp2.c_str());
			bool flagb = strcmp(temp_f.c_str(), temp3.c_str());
			if (!flaga && 2 * (i)>max)
				max = 2 * (i);
			else if (!flagb && 2 * i > max)
				max = 2 * i - 1;
		}
	}
	return max;
}

int main()
{
	string input;
	cin >> input;
	string test;
	test = string_flip(input);

	int m = count_string(input);
	int n = count_string(test);
	int ans = m > n ? m:n;
	cout << ans << endl;
	
	//system("pause");
}