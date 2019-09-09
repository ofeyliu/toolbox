#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
struct xy
{
	int x;
	int y;
};

double computeA(int x, int y)
{
	double ans = 1.0;
	for (int i = 0; i < y; i++)
		ans = ans * (x - i);
	return ans;
}

int main()
{
	int K;
	int A, X, B, Y;
	cin >> K;
	cin >> A >> X >> B >> Y;
	long long unsigned int sums = 0;
	vector <xy> probs;
	for (int i = 0; i <= X; i++)
	for (int j = 0; j <= Y; j++)
	if (i*A + j*B == K)
	{
		xy temp;
		temp.x = i;
		temp.y = j;
		probs.push_back(temp);
	}
	
	for (int i = 0; i < probs.size(); i++)
		sums = sums + computeA(X, probs[i].x) * computeA(Y, probs[i].y);


	cout << sums % 1000000007 << endl;
}