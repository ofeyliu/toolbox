/*
Introduction:
                        Reverse digits of an integer.

                         Example1: x = 123, return 321
                         Example2: x = -123, return -321

                         The input is assumed to be a 32-bit signed integer. 
                         Your function should return 0 when the reversed integer overflows.

Time :2017-03-29
author: liuww

test case: 0 1534236469 -2147438638 (over flow)

*/

/* shortest way!!
class Solution {
public:
     int reverse(int x) {
     long long res = 0;
     while(x) {
     res = res*10 + x%10;
      x /= 10;
     }
       return (res<INT_MIN || res>INT_MAX) ? 0 : res;
   }
};
*/
#include<iostream>
#include<vector>

using namespace std;

int reverse(long long x) {
	vector<int> perNum;
	bool pos;
	if (x > 0)
		pos = true;
	else{
		pos = false;
		x = -x;
	}
	int y = x % 10;
	x = x / 10;
	perNum.push_back(y);
	while (x > 0)
	{
		y = x % 10;
		x = x / 10;
		perNum.push_back(y);
	}
	long long result = 0;
	bool overFlow;
	std::vector<int>::iterator it = perNum.begin();
	for (; it != perNum.end(); it++)
	{
		result = result * 10 + *it;
	//	overFlow = result & 0x80000000;
		if (result>INT_MAX || result<INT_MIN)             /// check result(int)  over flow
			return 0;
	}
	if (pos == true)
		return result;
	else
		return (-result);
}

int main()
{
	int x;
	cin >> x;
	int y = reverse(x);
	cout<<y;
	system("pause");
}