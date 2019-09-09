#include <iostream>

int fib(const int i)
{
    if (i == 0) return 0;
    if (i == 1 || i == 2) return 1;
    int a = 1, b = 1;
    int c = 0;
    for (int j = 3;j <= i; j++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}


uint64_t fibonacci(unsigned int n) 
{
    uint64_t m[2][2] = { 1,1,1,0 }; // 1次矩阵
    uint64_t result[][2] = { 1,0,0,1 }; // 单位矩阵
    uint64_t temp[2][2];
    // 计算n次矩阵
    for (unsigned int i = 1; i <= n; i++) {
        temp[0][0] = result[0][0] * m[0][0] + result[0][1] * m[1][0];
        temp[0][1] = result[0][0] * m[0][1] + result[0][1] * m[1][1];
        temp[1][0] = result[1][0] * m[0][0] + result[1][1] * m[1][0];
        temp[1][1] = result[1][0] * m[0][1] + result[1][1] * m[1][1];
        memcpy(result, temp, sizeof(uint64_t) * 4);
    }
    // result[1][0] * 1 + result[1][1] * 0;
    return result[1][0] * 1;
}


int main()
{
    std::cout << fib(45) << std::endl;
    return 0;
}


