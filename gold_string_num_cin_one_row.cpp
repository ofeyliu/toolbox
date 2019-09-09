#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include<stdio.h>
using namespace std;
//*************************************************************
//��������split()
//���ã����ض��ַ� �ָ��ַ���
//*************************************************************
vector<string> split(const string &str, const string &pattern)
{
	//const char* convert to char*
	char * strc = new char[strlen(str.c_str()) + 1];
	strcpy(strc, str.c_str());
	vector<string> resultVec;
	char* tmpStr = strtok(strc, pattern.c_str());
	while (tmpStr != NULL)
	{
		resultVec.push_back(string(tmpStr));
		tmpStr = strtok(NULL, pattern.c_str());
	}
	delete[] strc;
	return resultVec;
}



//*************************************************************
//�������� num2str, str2num, secondsToTime, num2str2()
//���ã��ַ��� <------> ���� �໥ת��
//*************************************************************
string num2str(double i)
{
	stringstream ss;
	ss << i;
	return ss.str();
}

int str2num(string s)
{
	int num;
	stringstream ss(s);
	ss >> num;
	return num;
}

string secondsToTime(size_t & ss)
{
	int H, M, S;
	string time_str;
	H = ss / 3600;
	M = (ss % 3600) / 60;
	S = (ss % 3600) % 60;
	char ctime[10];
	sprintf(ctime, "%d:%d:%d", H, M, S);             // ������ת�����ַ���
	time_str = ctime;                                                 // ��� 
	return time_str;
}

void string2num2()
{
	char    str[] = "15.455";
	int     i;
	float     fp;
	sscanf(str, "%d", &i);         // ���ַ���ת��������   i = 15
	sscanf(str, "%f", &fp);      // ���ַ���ת���ɸ����� fp = 15.455000
	//��ӡ
	printf("Integer: = %d ", i + 1);
	printf("Real: = %f ", fp + 1);
	//��һ�ַ���
	int n;
	char *str = "12345";
	n = atoi(str);
	printf("int=%d\n", n);

}


int main()
{

	std::string line, num;
	std::vector<std::vector<int>> v;
	size_t linenum = 0;
	getline(cin, line);
	getline(cin, num);
	cout << num << endl;
	cout << line << endl;

	string str = "hello";
	//string[]  a = str.split("");  c# 
	string delimiter = " ";
	vector<string> nums = split(num, delimiter);
	for (int i = 0; i<nums.size(); i++)
	{
		cout << nums[i] << endl;
	}
	system("pause");
}