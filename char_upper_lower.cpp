#include<iostream>
#include<vector>
#include<string>


using namespace std;



int main()
{
	string state0= "123456";
	string input;
	cin >> input;
    char output[100];
	strcpy(output, state0.c_str());

	char a[100];
	strcpy(a,input.c_str());
	int upper = 0;
	int lower = 0;
	char l_str[100];
	char u_str[100];
	char tempA, tempa;
	int num = strlen(a);
	for (int i = 0; i < strlen(a); i++)
	{
		char A = a[i];
		if (A >= 'A' && A <= 'Z')
		{
			upper += 1;
			tempa = A + 32;
			tempA = A;
		}
			

		else if (A >= 'a' && A <= 'z')
		{
			lower += 1;
			tempa = A;
			tempA = A - 32;
		}
		else
		{
			tempa = ' ';
			tempA = ' ';
		}
		l_str[i] = tempa;
		u_str[i] = tempA;
	}
	l_str[num] = '\0';
	u_str[num] = '\0';
	if (upper > lower)
		cout << u_str;
	else
		cout << l_str;

    system("pause");
}