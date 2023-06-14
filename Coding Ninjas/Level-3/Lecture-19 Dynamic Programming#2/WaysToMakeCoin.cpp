#include <iostream>
using namespace std;

// Method 3: Dynamic Programming--
class Method3
{
    int countWaysToMakeChange(int arr[], int n, int val)
    {
        // DP Matrix (Value,N)--
        int **dp = new int *[val + 1];
        for (int i = 0; i <= val; i++)
        {
            dp[i] = new int[n];
        }
        // Initial Cell--
        dp[0][0] = 1;

        // First Row--
        for (int i = 1; i < n; i++)
        {
            dp[0][i] = 1;
        }

        // Fill Rest of Matrix--
        for (int i = 1; i <= val; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int take = (i - arr[j] >= 0) ? dp[i - arr[j]][j] : 0;

                int refuse = (j >= 1) ? dp[i][j - 1] : 0;

                dp[i][j] = take + refuse;
            }
        }

        return dp[val][n - 1];
    }
};

// Method 2: Memomization--
class Method2
{
    int ways(int arr[], int n, int val, int pos, int **dp)
    {
        // Base Case--
        if (val == 0)
        {
            return 1;
        }
        if (pos == n || val < 0)
        {
            return 0;
        }

        // Check if Solution Exist--
        if (dp[val - 1][pos] != -1)
        {
            return dp[val - 1][pos];
        }

        // Reccursive Calls--
        int take = ways(arr, n, val - arr[pos], pos, dp);
        int refuse = ways(arr, n, val, pos + 1, dp);

        // Return
        return dp[val - 1][pos] = take + refuse;
    }

public:
    int countWaysToMakeChange(int denominations[], int numDenominations, int value)
    {
        int **dp = new int *[value];
        for (int i = 0; i < value; i++)
        {
            dp[i] = new int[numDenominations];
            for (int j = 0; j < numDenominations; j++)
            {
                dp[i][j] = -1;
            }
        }

        return ways(denominations, numDenominations, value, 0, dp);
    }
};

// Method 1: Reccursion--
// Time Limit Exceeded--
class Method1
{
    int ways(int arr[], int n, int val, int pos)
    {
        // Base Case--
        if (val == 0)
        {
            return 1;
        }
        if (pos == n || val < 0)
        {
            return 0;
        }

        // Reccursive Calls--
        int take = ways(arr, n, val - arr[pos], pos);
        int refuse = ways(arr, n, val, pos + 1);

        // Return
        return take + refuse;
    }

public:
    int countWaysToMakeChange(int denominations[], int numDenominations, int value)
    {
        return ways(denominations, numDenominations, value, 0);
    }
};