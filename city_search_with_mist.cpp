// 华为笔试题，住在5城，去X市出差，Y城市大雾不能达，输出最短路径和最短时间，不能到达则为1000；
//  table为城市间到达时间表，1000表示不能达

// liuww
// 2017-03-28

#include<iostream>
#include<vector>
#include<string>

using namespace std;
struct route{
	int city1;
	int city2;
	int city3;
	int city4;
	int city5;
};

int main()
{
	int table[6][6] = { { 0, 2, 10, 5, 3, 1000 },
	{ 1000, 0, 12, 1000, 1000, 10 },
	{ 1000, 1000, 0, 1000, 7, 1000 },
	{ 2, 1000, 1000, 0, 2, 1000 },
	{ 4, 1000, 1000, 1, 0, 1000 },
	{ 3, 1000, 1, 1000, 2, 0 } };
	int times[6] = { 0 };
//	vector<int[6]> times;
	int X,Y;
	int home = 4;
	cin>>X>>Y;	
	if (X > 6 || Y > 6)
	{
		cout << "error input\n";
		return 0;
	}
	int y = Y - 1;                // 大雾城市y;
	bool found = false;
	vector<route> routes;
	for (int i=0;i<6;i++)
	{
		if (i == home|| i==y)
			continue;
		for (int j = 0; j < 6; j++)
		{
			if (j == i || j == home || j==y)
				continue;
			for (int k = 0; k < 6; k++)
			{
				if (k == i || k == j || k == home || k==y)
					continue;
				for (int m = 0; m < 6; m++)
				{
					if (m == i || m == j || m == k || m == home || m==y)
						continue;
					route canditate;
					canditate.city1 = i;
					canditate.city2 = j;
					canditate.city3 = k;
					canditate.city4 = m;
					canditate.city5 = 15-home-i-j-k-m;
					routes.push_back(canditate);
				}
			}
		}
	}
	route minTimeRoute;
	int minTime = 1000;
	int temp;
	for (int i = 0; i < routes.size(); i++)
	{
		if (routes[i].city1 == X-1)
		{
			temp = table[home][routes[i].city1];
		}
		else if (routes[i].city2 == X-1)
		{
			temp = table[home][routes[i].city1] + table[routes[i].city1][routes[i].city2];
		}
		else if (routes[i].city3 == X-1)
		{
			temp = table[home][routes[i].city1] + table[routes[i].city1][routes[i].city2] + table[routes[i].city2][routes[i].city3];
		}
		else if (routes[i].city4 == X-1)
		{
			temp = table[home][routes[i].city1] + table[routes[i].city1][routes[i].city2] + table[routes[i].city2][routes[i].city3] + table[routes[i].city3][routes[i].city4];
		}
		else if (routes[i].city5 == X-1)
		{
			temp = table[home][routes[i].city1] + table[routes[i].city1][routes[i].city2] + table[routes[i].city2][routes[i].city3] + table[routes[i].city3][routes[i].city4] + table[routes[i].city4][routes[i].city5];
		}
		else
			cout << "error0" << endl;
		if (temp < minTime)
		{
			minTimeRoute = routes[i];
			minTime = temp;
		}
	}
	cout << minTimeRoute.city1 << '\t' << minTimeRoute.city2 << '\t' << minTimeRoute.city3 << '\t' << minTimeRoute.city4 << '\t' << minTimeRoute.city5 << endl;
	cout << minTime << endl;
	system("pause");
	return 0;

}