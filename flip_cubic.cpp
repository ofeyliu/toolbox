#include<iostream>
#include<vector>
#include<string>


using namespace std;

string l_flip(const string & state_old)
{
	char s_old[7], s_new[7];
	strcpy(s_old, state_old.c_str());
	s_new[0] = s_old[4];
	s_new[1] = s_old[5];
	s_new[2] = s_old[2];
	s_new[3] = s_old[3];
	s_new[4] = s_old[1];
	s_new[5] = s_old[0];
	s_new[6] = '\0';
	string result = s_new;
	return result;
}

string r_flip(const string & state_old)
{
	char s_old[7], s_new[7];
	strcpy(s_old, state_old.c_str());
	s_new[0] = s_old[5];
	s_new[1] = s_old[4];
	s_new[2] = s_old[2];
	s_new[3] = s_old[3];
	s_new[4] = s_old[0];
	s_new[5] = s_old[1];
//	delete s_old,s_new;
	s_new[6] = '\0';
	string result= s_new;

	return result;
}

string f_flip(const string & state_old)
{
	char s_old[7], s_new[7];
	strcpy(s_old, state_old.c_str());
	s_new[0] = s_old[0];
	s_new[1] = s_old[1];
	s_new[2] = s_old[4];
	s_new[3] = s_old[5];
	s_new[4] = s_old[3];
	s_new[5] = s_old[2];
	//	delete s_old,s_new;
	s_new[6] = '\0';
	string result = s_new;

	return result;
}

string b_flip(const string & state_old)
{
	char s_old[7], s_new[7];
	strcpy(s_old, state_old.c_str());
	s_new[0] = s_old[0];
	s_new[1] = s_old[1];
	s_new[2] = s_old[5];
	s_new[3] = s_old[4];
	s_new[4] = s_old[2];
	s_new[5] = s_old[3];
	//	delete s_old,s_new;
	s_new[6] = '\0';
	string result = s_new;

	return result;
}

string ni_rotate(const string & state_old)
{
	char s_old[7], s_new[7];
	strcpy(s_old, state_old.c_str());
	s_new[0] = s_old[3];
	s_new[1] = s_old[2];
	s_new[2] = s_old[0];
	s_new[3] = s_old[1];
	s_new[4] = s_old[4];
	s_new[5] = s_old[5];
	s_new[6] = '\0';
	string result = s_new;
	return result;
}

string shun_rotate(const string & state_old)
{
	char s_old[7], s_new[7];
	strcpy(s_old, state_old.c_str());
	s_new[0] = s_old[2];
	s_new[1] = s_old[3];
	s_new[2] = s_old[1];
	s_new[3] = s_old[0];
	s_new[4] = s_old[4];
	s_new[5] = s_old[5];
	s_new[6] = '\0';
	string result = s_new;
	return result;
}
 

int main()
{
	string state0= "123456";
	string input;
	cin >> input;
	char output[7];
	strcpy(output, state0.c_str());

	char a[50];
	strcpy(a,input.c_str());
	for (int i = 0; i < strlen(a); i++)
	{
		char A = a[i];
		string temp;
		switch (A)
		{
		case  'R':  temp = r_flip(output);
			break;
		case  'A':  temp = ni_rotate(output);
			break;
		case  'L':  temp = l_flip(output);
			break;
		case  'B':  temp = b_flip(output);
			break;
		case  'F':  temp = f_flip(output);
			break;
		case  'C':  temp =shun_rotate(output);
			break;
		default:
			break;
		}
		strcpy(output, temp.c_str());
	}
	cout << output << endl;
//	system("pause");
}