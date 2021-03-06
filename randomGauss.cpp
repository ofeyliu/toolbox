#include <iostream>
#include <math.h>

using namespace std;

/*生成标准正态分布随机数*/
// 常用的成熟的生成高斯分布随机数序列的方法由Marsaglia和Bray在1964年提出
double gaussRand(){
	static double V1, V2, S;
	static int  phase = 0;
	double X;

	if (phase == 0){
		do{
			double U1 = (double)rand() / RAND_MAX;
			double U2 = (double)rand() / RAND_MAX;

			V1 = 2 * U1 - 1;
			V2 = 2 * U2 - 1;
			S = V1*V1 + V2*V2;
		} while (S >= 1 || S == 0);

		X = V1*sqrt(-2 * log(S) / S);
	}
	else
		X = V2*sqrt(-2 * log(S) / S);

	phase = 1 - phase;

	return X;
}

/*将随机值从正态分布N(0,1)转化到高斯分布N(mu,sigma)*/
double gaussValue(double val, double mu, double sigma)
{
	return mu + sigma*val;
}
/*判断随机值是否在曲线内*/
bool isInside(double x, double y)
{
	double x2 = x*x;
	double y2 = y*y;
	double temp = x2 + y2 - 1;
	return (temp*temp - x2*y2)>0 ? false : true;
}
/*模拟*/
double learnCurve(double mu1, double sigma1, double mu2, double sigma2)
{
	int n = 10000;//模拟次数
	int count = 0;
	int i = n;
	while (i-->0){
		double x = gaussValue(gaussRand(), mu1, sigma1);
		double y = gaussValue(gaussRand(), mu2, sigma2);
		if (isInside(x, y))
			count++;
	}
	return (double)count / n;
}

int main()
{
	double mu1, mu2, sigma1, sigma2;
	cin >> mu1 >> sigma1 >> mu2 >> sigma2;

	double res = learnCurve(mu1, sigma1, mu2, sigma2);
	printf("%.1f\n", res);

	return 0;
}