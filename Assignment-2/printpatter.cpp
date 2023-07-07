// P22. Write a program without recursion to print following sequence up to given n
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

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= factorial(i); j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}