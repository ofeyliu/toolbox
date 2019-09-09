#include<stdio.h>  
#include<stdlib.h>  
#include<iostream>  
#include<queue>  
#include<climits>  
#include<cstring>  
#include<stdlib.h>  
#include <time.h>
#include<ctime>
#include <iomanip>
using namespace std;

void Add(int *m[], int weight[], int value[], int num, int content)//n������Ʒ�ĸ���   
{
	int i, j;
	for (j = 0; j <= content; j++)//���ôӵ׵�����˳��������m[i][j]��ֵ,���ȷ�weight[num]
	{
		if (j<weight[num])//jС��weight[num],����Ӧ��ֵ��Ϊ0
		{
			m[num][j] = 0;
		}
		else//�����Ϊ���Է���
		{
			m[num][j] = value[num];
		}
	}

	for (i = num - 1; i >= 1; i--)//��ʣ�µ�num-1����Ʒ���з���  
	{
		for (int j = 0; j <= content; j++)
		{
			if (j<weight[i])//���j<weight[i]��ǰλ�þͲ��ܷ��ã���������һ��λ�õ�ֵ��  
			{
				m[i][j] = m[i + 1][j];
			}
			else//���򣬾ͱȽϵ����Ƿ���֮���ֵ�󣬻��ǲ����õ�ֵ��ѡ�����нϴ��ߡ�
			{
				m[i][j] = m[i + 1][j]>m[i + 1][j - weight[i]] + value[i] ? m[i + 1][j] : m[i + 1][j - weight[i]] + value[i];
			}
		}
	}
}
void putout(int *m[], int num, int content, int x[], int weight[])
{
	int j = content, i;
	for (i = 1; i <= num - 1; i++)
	{
		if (m[i][j] == m[i + 1][j])
		{
			x[i] = 0;//0��ʾ���Ž���������Ʒ
		}
		else
		{
			x[i] = 1;//�Ž���������Ʒ
			j = j - weight[i];
		}
	}
	x[num] = m[i][j] ? 1 : 0;
}
int main()
{
	while (true){
		int times = 100000, t;//�����ܴ���
		double alltime = 0;
		int num, content; //��Ʒ�ĸ����ͱ�������
		cout << "������Ʒ����:";
		cin >> num;
		cout << "���뱳������:";
		cin >> content;
		int *weight = new int[num + 1];//��Ʒ������������0��λ�ò�ʹ�� ��   
		int *value = new int[num + 1];//��Ʒ��Ӧ�Ĵ��ӣ�0��λ����Ϊ�ա� 
		int i, j;
		for (t = 0; t<times; t++)
		{
			clock_t start, finish;
			srand((int)time(NULL));//srand()��������һ���Ե�ǰʱ�俪ʼ���������.Ӧ�÷���for��ѭ�����ǰ�� ��ȻҪ�ܳ�ʱ��ȴ� 
			for (i = 1; i <= num; i++)
			{
				//weight[i]=rand()%(content/2);//����0~content/2������
				//value[i]=rand()%(content/2);
				weight[i] = 1 + content * rand() / (RAND_MAX + 1);//����1~content�������
				value[i] = 1 + content * rand() / (RAND_MAX + 1);
			}

			weight[0] = 0;
			value[0] = 0;
			/*cout<<setw(5)<<"���"<<setw(5)<<"����"<<setw(5)<<"��ֵ"<<endl;
			for(i=1;i<=num;i++)
			{
			cout<<setw(3)<<i<<setw(5)<<weight[i]<<setw(5)<<value[i]<<endl;
			}
			cout<<endl;*/

			int *x = new int[num + 1];
			int **m = new int*[num + 1];
			for (i = 0; i<num + 1; i++)
			{
				m[i] = new int[content + 1];
			}
			for (i = 0; i<num + 1; i++)
			{
				for (j = 0; j<content + 1; j++)
				{
					m[i][j] = 0;
				}
			}

			start = clock();//��ʼʱ��
			Add(m, weight, value, num, content);
			putout(m, num, content, x, weight);
			finish = clock();//����ʱ��
			alltime = alltime + (double)(finish - start);//times�μ����ʱ���ܺ�

			/*for(i=0;i<=num;i++)
			{
			for(j=0;j<=content;j++)
			{
			printf("%2d ",m[i][j]);
			}
			cout<<endl;
			}
			cout<<"���뱳������Ʒ���:\n";
			for(i=1;i<=num;i++)
			{
			if(x[i]==1)
			{
			cout<<i<<" ";
			}
			}
			cout<<endl;*/
		}
		cout << times << "������ƽ������ʱ��:" << alltime / times << "ms" << endl;//times�����е�ƽ��ʱ�䣬�������ȷ
		cout << "-----------------------------------" << endl;
	}
	return 0;
}
