#include<iostream>

#include<stack>

#include<cstdio>

using namespace std;



const int N = int(2e3) + 9;

int a[N][N];

int h[N];

int n, m;

int main(){



	while (cin >> n >> m){

		for (int k = 1; k <= n; ++k){

			for (int j = 1; j <= n; ++j){

				cin >> a[k][j];

			}

		}



		int ans = 0;

		memset(h, 0, sizeof(h));



		for (int i = 1; i <= n; ++i){

			for (int j = 1; j <= n; j++){

				h[j] = a[i][j] == 0 ? 0 : h[j] + 1;

			}

			stack<int> s; s.push(0); h[++m] = 0;

			for (j = 1; j <= m; ++j)
			{
				while (h[j]<h[s.top()])
				{
					int a = h[s.top()]; s.pop();
					int b = j - s.top() - 1;
					if (a * b > ans)
					{
						ans = a *b;
					}
				}
				s.push(j);
			}
			--m;
		}
		cout << ans << endl;

		return 0;

	}
	system("pause");
}