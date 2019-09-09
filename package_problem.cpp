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

void Add(int *m[], int weight[], int value[], int num, int content)//n代表物品的个数   
{
	int i, j;
	for (j = 0; j <= content; j++)//采用从底到顶的顺序来设置m[i][j]的值,首先放weight[num]
	{
		if (j<weight[num])//j小于weight[num],所对应的值设为0
		{
			m[num][j] = 0;
		}
		else//否则就为可以放置
		{
			m[num][j] = value[num];
		}
	}

	for (i = num - 1; i >= 1; i--)//对剩下的num-1个物品进行放置  
	{
		for (int j = 0; j <= content; j++)
		{
			if (j<weight[i])//如果j<weight[i]则当前位置就不能放置，它等于上一个位置的值。  
			{
				m[i][j] = m[i + 1][j];
			}
			else//否则，就比较到底是放置之后的值大，还是不放置的值大，选择其中较大者。
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
			x[i] = 0;//0表示不放进背包该物品
		}
		else
		{
			x[i] = 1;//放进背包该物品
			j = j - weight[i];
		}
	}
	x[num] = m[i][j] ? 1 : 0;
}
int main()
{
	while (true){
		int times = 100000, t;//运行总次数
		double alltime = 0;
		int num, content; //物品的个数和背包容量
		cout << "输入物品个数:";
		cin >> num;
		cout << "输入背包容量:";
		cin >> content;
		int *weight = new int[num + 1];//物品的重量，其中0号位置不使用 。   
		int *value = new int[num + 1];//物品对应的待加，0号位置置为空。 
		int i, j;
		for (t = 0; t<times; t++)
		{
			clock_t start, finish;
			srand((int)time(NULL));//srand()函数产生一个以当前时间开始的随机种子.应该放在for等循环语句前面 不然要很长时间等待 
			for (i = 1; i <= num; i++)
			{
				//weight[i]=rand()%(content/2);//生成0~content/2的整数
				//value[i]=rand()%(content/2);
				weight[i] = 1 + content * rand() / (RAND_MAX + 1);//生成1~content的随机数
				value[i] = 1 + content * rand() / (RAND_MAX + 1);
			}

			weight[0] = 0;
			value[0] = 0;
			/*cout<<setw(5)<<"编号"<<setw(5)<<"重量"<<setw(5)<<"价值"<<endl;
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

			start = clock();//开始时间
			Add(m, weight, value, num, content);
			putout(m, num, content, x, weight);
			finish = clock();//结束时间
			alltime = alltime + (double)(finish - start);//times次计算的时间总和

			/*for(i=0;i<=num;i++)
			{
			for(j=0;j<=content;j++)
			{
			printf("%2d ",m[i][j]);
			}
			cout<<endl;
			}
			cout<<"放入背包的物品编号:\n";
			for(i=1;i<=num;i++)
			{
			if(x[i]==1)
			{
			cout<<i<<" ";
			}
			}
			cout<<endl;*/
		}
		cout << times << "组数据平均运行时间:" << alltime / times << "ms" << endl;//times次运行的平均时间，结果更精确
		cout << "-----------------------------------" << endl;
	}
	return 0;
}
