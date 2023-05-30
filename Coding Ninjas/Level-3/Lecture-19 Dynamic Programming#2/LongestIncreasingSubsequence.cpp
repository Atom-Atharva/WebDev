#include <iostream>
using namespace std;
#include <climits>
#include <vector>

class Solution
{
    // Memomization--
    int longestIncreasingSubsequence2(int *arr, int n, int i, int pind, int **dp)
    {
        // Base Case--
        if (n == i)
        {
            return 0;
        }

        if (dp[i][pind + 1] != -1)
        {
            return dp[i][pind + 1];
        }

        // Reccursive Call--
        int select = INT_MIN;
        if (pind == -1 || arr[i] > arr[pind])
        {
            select = 1 + longestIncreasingSubsequence2(arr, n, i + 1, i, dp);
        }

        int reject = longestIncreasingSubsequence2(arr, n, i + 1, pind, dp);

        return dp[i][pind + 1] = max(select, reject);
    }

    // Reccursion--
    int longestIncreasingSubsegquece(int *arr, int n, int prev)
    {
        // Base Case--
        if (n == 0)
        {
            return 0;
        }

        // Reccursive Call--
        int select = 0;
        if (arr[0] > prev)
        {
            select = 1 + longestIncreasingSubsegquece(arr + 1, n - 1, arr[0]);
        }

        int reject = longestIncreasingSubsegquece(arr + 1, n - 1, prev);

        return max(select, reject);
    }

public:
    // Dynamic Programming--
    int longestIncreasingSubsequence3(int *arr, int n)
    {
        int *dp = new int[n + 1];

        // First Cell--
        dp[0] = 0;

        int longsubstr = 0;
        // Fill Rest of the cells--
        for (int i = 1; i <= n; i++)
        {
            int maxstr = 0;
            // Find Max of longest Substring--
            for (int j = i - 1; j >= 0; j--)
            {
                if (j == 0 || arr[j - 1] < arr[i - 1])
                {
                    maxstr = max(maxstr, dp[j]);
                }
            }

            // Add Current element to the longest Substring--
            maxstr++;
            dp[i] = maxstr;
            longsubstr = max(longsubstr, maxstr);
        }

        // Return last dp--
        return longsubstr;
    }

    // Memomization--
    int longestIncreaingSubsequence2(int *arr, int n)
    {
        int **dp = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[n + 1];
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = -1;
            }
        }

        return longestIncreasingSubsequence2(arr, n, 0, -1, dp);
    }

    // Reccursion--
    int longestIncreasingSubsequence(int *arr, int n)
    {
        return longestIncreasingSubsegquece(arr, n, INT_MIN);
    }
};