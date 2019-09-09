#include <stdio.h>
#include <stdlib.h>
 
void main(){
	int doubleCheck(int a, int b, int c, int d[]);
	int d[] = { 1, 2, 3, 4, 5, 6 };
        doubleCheck(0,5,5,d);
	getchar();
 
}
 
void doubleCheck(int a,int b,int c,int d []){//a为数组的下界，b为数组的上界，c为匹配目标,d为查找的范围数组。
	int x = (a + b) / 2;
	//递归的结束条件一定要写在判断条件之前。
	if (d[x] == c)
	{
		printf("%d",x);
	}
	if (d[x] > c)//说明在d[a]-d[x]范围之中
	{
		doubleCheck(a, x-1, c, d);
	}
	if (d[x] < c)
	{
		doubleCheck(x+1, b, c, d);
	}
}
