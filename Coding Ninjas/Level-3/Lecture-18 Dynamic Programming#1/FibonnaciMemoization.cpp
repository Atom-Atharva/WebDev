#include <iostream>
using namespace std;

// Time Complexity --> O(2^n), which is very BAD!!
// Due to Reapeatative Calls in Reccursive Process--
// Brute Force Approach--
int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    int a = fib(n - 1);
    int b = fib(n - 2);
    return a + b;
}

// Time Complexity--> O(n), Drastic IMPROVEMENT!!
// This method is called Memoization Approach--
// It is also called TOP-DOWN Approach (Recursive)--
int fib_helper(int n, int *arr)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    // Check if Solution exist--
    if (arr[n] != -1)
    {
        return arr[n];
    }

    int a = fib_helper(n - 1, arr);
    int b = fib_helper(n - 2, arr);

    // Save Output for Future use--
    arr[n] = a + b;
    return arr[n];
}

int fib_2(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }

    return fib_helper(n, arr);
}

// Dynamic Approach or DOWN-UP Approach (Iterative)--
// Time Complexity-- O(n)
// Best Possible Solution as Recursion mai space thodi extra use hoti hai--
int fib_3(int n)
{
    int *arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}

int main()
{
    int n;
    cin >> n;

    cout << fib_3(n) << endl;

    return 0;
}