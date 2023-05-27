#include <iostream>
using namespace std;

class Solution
{
    // Memomization (Helper Function)--
    int maxMoneyLooted2(int *arr, int n, int **dp, bool prev)
    {
        // Base Case--
        if (n <= 0)
        {
            return 0;
        }

        // If prev ans is already exist--
        if (dp[n][prev] != -1)
        {
            return dp[n][prev];
        }
        // Prev Looted then Skip--
        if (prev == 1)
        {
            return dp[n][prev] = maxMoneyLooted2(arr + 1, n - 1, dp, 0);
        }

        // Reccursive Call--
        int select = arr[0] + maxMoneyLooted2(arr + 1, n - 1, dp, 1);
        int reject = maxMoneyLooted2(arr + 1, n - 1, dp, prev);

        return dp[n][prev] = max(select, reject);
    }

    // Reccursion (Helper Function)--
    int maxMoneyLooted(int *arr, int n, bool prev)
    {
        // Base Case--
        if (n <= 0)
        {
            return 0;
        }
        // Prev Looted then Skip--
        if (prev == 1)
        {
            return maxMoneyLooted(arr + 1, n - 1, 0);
        }

        // Reccursive Call--
        int select = arr[0] + maxMoneyLooted(arr + 1, n - 1, 1);
        int reject = maxMoneyLooted(arr + 1, n - 1, prev);

        return max(select, reject);
    }

public:
    int maxMoneyLooted2(int *arr, int n)
    {
        int **dp = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[2];
            for (int j = 0; j < 2; j++)
            {
                dp[i][j] = -1;
            }
        }

        return maxMoneyLooted2(arr, n, dp, 0);
    }

    // Reccursion--
    int maxMoneyLooted(int *arr, int n)
    {
        return maxMoneyLooted(arr, n, 0);
    }
};