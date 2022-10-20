#include <iostream>

using namespace std;

// loop
int factorial(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

// recursion
int factorial2(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * factorial2(n - 1);
}

int factorial3(int n, int product = 1)
{
    if (n == 1)
    {
        return product;
    }
    return factorial3(n - 1, n * product);
}

int main()
{
    cout << factorial(3) << endl;
    cout << factorial(4) << endl;

    cout << factorial2(3) << endl;
    cout << factorial2(4) << endl;

    cout << factorial3(3) << endl;
    cout << factorial3(4) << endl;

    return 0;
}