#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <string>
#include <cstring>
using namespace std;


/*������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^
******************************��ʼд����******************************/
int solve(string &S, string &T) {

	int i, j;
	int count = 0;
	int N = S.size();
	int M = T.size();
	//int *a = new int[M];
	if (N < M)
		return 0;
	//if (N>10000 || M>10000)
	//    return 1;
	bool flag;
	int temp;
	char jChar;
	int a[26] = { 0 };
	for (i = 0; i < N - M + 1; i++)
	{
		memset(a, 0, 26 * sizeof(int));
		flag = true;
		for (j = 0; j < M; j++)
		{
			temp = S[j + i] - T[j];
			//temp = temp >0 ? temp : -temp;
			jChar = T[j];
			if (a[jChar - 'a'] == 0)
				a[jChar - 'a'] = temp;
			else if (a[jChar - 'a'] != temp)
			{
				flag = false;
				break;
			}
		}
		if (flag)
			count += 1;
	}
	return count;
}
/******************************����д����******************************/


int main() {
	int res;

	string _S;
	getline(cin, _S);
	string _T;
	getline(cin, _T);

	res = solve(_S, _T);
	cout << res << endl;

	return 0;

}