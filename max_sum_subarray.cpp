#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/**
*输入一个整形数组，数组里有正数也有负数。
*数组中连续的一个或多个整数组成一个子数组，
*每个子数组都有一个和。 求所有子数组的和的最大值。
*要求时间复杂度为O(n)。
*/
int maxsum(int*a,int n)
{
    int sum=0;
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(c<0)
            c=a[i];
        else
            c+=a[i];
        if(sum<c)
            sum=c;
    }
    return sum;
}
int main()
{
    int a[8]={8,-4,6,-1,3,7,2,-3};
    cout<<maxsum(a,8)<<endl;
    return 0;
}

