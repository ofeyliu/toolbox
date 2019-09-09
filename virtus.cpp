#include<iostream>
#include<vector>
#include<string>
#include"string.h"

using namespace std;

int main()
{
	string input;
	cin >> input;
	string::size_type idx;
	string t="virus";
	idx = input.find(t);
	int N = input.size();
	if (idx == string::npos)
		cout << "found";
	else
		cout << idx;

	system("pause");
}