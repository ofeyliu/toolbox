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

int main()
{
    std::cout << fib(45) << std::endl;
    return 0;
}
