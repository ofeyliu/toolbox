#include <stdlib.h> 
#include <stdio.h> 

int m[8][8] = { 0 };//��ʾ���̣���ʼΪ0����ʾδ���ûʺ� 
int num = 0;//����Ŀ 

//��������ǰrow-1���ѷ��úûʺ� 
//����ڵ�row�С���column�з���һö�ʺ��Ƿ���� 
bool check(int row, int column)
{
	if (row == 1) return true;
	int i, j;
	//����ֻ����һö�ʺ� 
	for (i = 0; i <= row - 2; i++)
	{
		if (m[i][column - 1] == 1) return false;
	}
	//����������ֻ����һö�ʺ� 
	i = row - 2;
	j = i - (row - column);
	while (i >= 0 && j >= 0)
	{
		if (m[i][j] == 1) return false;
		i--;
		j--;
	}
	//����������ֻ����һö�ʺ� 
	i = row - 2;
	j = row + column - i - 2;
	while (i >= 0 && j <= 7)
	{
		if (m[i][j] == 1) return false;
		i--;
		j++;
	}
	return true;
}

//���ѷ���8ö�ʺ�Ϊ���н�ʱ��������� 
void output()
{
	int i, j;
	num++;
	printf("answer %d:\n", num);
	for (i = 0; i<8; i++)
	{
		for (j = 0; j<8; j++) printf("%d ", m[i][j]);
		printf("\n");
	}
}

//���õݹ麯��ʵ�ְ˻ʺ�����㷨 
//�ú�����⵱����ǰrow-1���ѷ��úûʺ��ڵ�row�з��ûʺ� 
void solve(int row)
{
	int j;
	//�����ڵ�row�еĸ��з��ûʺ� 
	for (j = 0; j<8; j++)
	{
		//������һ�з��ûʺ� 
		m[row - 1][j] = 1;
		//����ڸ��з��ûʺ��Ƿ���� 
		if (check(row, j + 1) == true)
		{
			//�����пɷ��ûʺ��Ҹ���Ϊ���һ�У����ҵ�һ���н⣬��� 
			if (row == 8) output();
			//�����пɷ��ûʺ�������һ�У�������������� 
			else solve(row + 1);
		}
		//ȡ�����еĻʺ󣬽��л��ݣ��������з��ûʺ� 
		m[row - 1][j] = 0;
	}
}

//������ 
int main()
{
	//���˻ʺ����� 
	solve(1);
	return 0;
}