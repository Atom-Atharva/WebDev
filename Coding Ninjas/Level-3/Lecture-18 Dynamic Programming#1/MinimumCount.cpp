#include <iostream>
using namespace std;

// Brute Force--
int minCount(int n)
{
    // Base Case--
    if (n == 0 || n == 1)
    {
        return n;
    }

    // Reccursive Call and Small Calculation--
    int count = 1000;
    for (int i = 1; (i * i) <= n; i++)
    {
        int smallcount = minCount(n - (i * i)) + 1;
        count = min(count, smallcount);
    }
    return count;
}

// Memoization Approach--
int minCount_Helper(int n, int *arr)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    // Check if the Solution exist--
    if (arr[n] != -1)
    {
        return arr[n];
    }

    int count = 1000;
    for (int i = 1; i * i <= n; i++)
    {
        int smallcount = minCount(n - i * i) + 1;
        count = min(count, smallcount);
    }
    arr[n] = count;
    return arr[n];
}

int minCount_2(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }
    return minCount_Helper(n, arr);
}

// Dynamic Programming--
int minCount_3(int n)
{
    int *arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        arr[i] = 9999;
        for (int j = 1; j * j <= n; j++)
        {
            arr[i] = min(arr[i], arr[i - j * j]);
        }
        arr[i] += 1;
    }
    return arr[n];
}

int main()
{
    int n;
    cin >> n;

    cout << minCount_2(n) << endl;

    return 0;
}