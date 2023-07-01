// https://practice.geeksforgeeks.org/problems/coin-change2448/1

// Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ].
// Note: Assume that you have an infinite supply of each type of coin.

#include <iostream>
using namespace std;

//*Method 3*: Dynamic Programming--
class Solution
{
public:
    long long int count(int coins[], int N, int sum)
    {
        // Dynamic Programming Array--
        long long **arr = new long long *[N + 1];
        for (int i = 0; i <= N; i++)
        {
            arr[i] = new long long[sum + 1];
        }

        // Fill First Cell--
        arr[0][0] = 1;

        // Fill First Row--
        for (int j = 1; j <= sum; j++)  
        {
            arr[0][j] = 0;
        }

        // Fill First Column--
        for (int i = 1; i <= N; i++)
        {
            arr[i][0] = 1;
        }

        // Fill Remaining Cells--
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                // Case I: If Ignored--
                long long ignore = arr[i - 1][j];

                // Case II: If Taken--
                long long take;
                if (j - coins[i - 1] < 0)
                {
                    take = 0;
                }
                else
                {
                    take = arr[i][j - coins[i - 1]];
                }

                arr[i][j] = ignore + take;
            }
        }

        return arr[N][sum];
    }
};

// *Method 2*: Memomisation--
class Solution
{
    long long count(int coins[], int N, int pos, int sum, long long **arr)
    {
        // Base Case--
        if (sum == 0)
        {
            return 1;
        }
        if (pos == N || sum < 0)
        {
            return 0;
        }

        if (arr[pos][sum] != -1)
        {
            return arr[pos][sum];
        }

        // Recursive Cases--
        // Case I: If Ignored--
        long long ignore = count(coins, N, pos + 1, sum, arr);

        // Case II: If Taken--
        long long taken = count(coins, N, pos, sum - coins[pos], arr);

        // Total Combinations--
        return arr[pos][sum] = ignore + taken;
    }

public:
    long long int count(int coins[], int N, int sum)
    {
        long long int **arr = new long long *[N];
        for (int i = 0; i < N; i++)
        {
            arr[i] = new long long[sum + 1];
            for (int j = 0; j <= sum; j++)
            {
                arr[i][j] = -1;
            }
        }

        return count(coins, N, 0, sum, arr);
    }
};

// *Method 1*: Recursion--
// Time Complexity O(2^n).
class Solution
{
    long long count(int coins[], int N, int pos, int sum)
    {
        // Base Case--
        if (sum == 0)
        {
            return 1;
        }
        if (pos == N || sum < 0)
        {
            return 0;
        }

        // Recursive Cases--
        // Case I: If Ignored--
        long long ignore = count(coins, N, pos + 1, sum);

        // Case II: If Taken--
        long long taken = count(coins, N, pos, sum - coins[pos]);

        // Total Combinations--
        return ignore + taken;
    }

public:
    long long int count(int coins[], int N, int sum)
    {
        return count(coins, N, 0, sum);
    }
};