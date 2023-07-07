// P23. Write a program using recursion to print following sequence up to given n
// 1
// 2 2
// 3 3 3 3 3 3
// 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4

#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    int ans = factorial(n - 1) * n;
    return ans;
}

void print(int n)
{
    if (n == 1)
    {
        cout << n << endl;
        return;
    }
    print(n - 1);
    for (int i = 1; i <= factorial(n); i++)
    {
        cout << n << " ";
    }
    cout << endl;
    return;
}

int main()
{
    int n;
    cin >> n;

    print(n);

    return 0;
}