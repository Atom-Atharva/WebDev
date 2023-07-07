#include <iostream>
using namespace std;

// Brute Force Approach--
long staircase(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    int a = staircase(n - 1);
    int b = staircase(n - 2);
    int c = staircase(n - 3);

    return a + b + c;
}

// Dynamic Programming Approach--
long staircase_2(int n)
{
    long *arr = new long[n + 1];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;

    for (int i = 3; i <= n; i++)
    {

        long a = arr[i - 1];
        long b = arr[i - 2];
        long c = arr[i - 3];

        arr[i] = a + b + c;
    }
    return arr[n];
}

int main()
{
    int n;
    cin >> n;

    cout << staircase_2(n) << endl;

    return 0;
}