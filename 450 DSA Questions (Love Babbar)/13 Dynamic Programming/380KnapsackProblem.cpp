// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
// In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).

#include <iostream>
using namespace std;

//*Method 3*: Dynamic Programming--
class Solution
{
public:
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Dynamic Array--
        int **arr = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            arr[i] = new int[W + 1];
        }

        // Fill Initial Element--
        arr[0][0] = 0;

        // Fill First Row--
        for (int j = 0; j <= W; j++)
        {
            arr[0][j] = 0;
        }

        // Fill First Column--
        for (int i = 0; i <= n; i++)
        {
            arr[i][0] = 0;
        }

        // Fill Rest of Cells--
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                // Condition--
                if (j - wt[i - 1] < 0)
                {
                    arr[i][j] = arr[i - 1][j];
                    continue;
                }

                int ignore = arr[i - 1][j];
                int take = val[i - 1] + arr[i - 1][j - wt[i - 1]];

                arr[i][j] = max(ignore, take);
            }
        }

        return arr[n][W];
    }
};

// *Method 2*: Memomisation--
class Solution
{
    int knapSack(int W, int wt[], int val[], int n, int pos, int value, int **arr)
    {
        // Base Case--
        if (pos == n || W == 0)
        {
            return 0;
        }
        if (arr[pos][W] != -1)
        {
            return arr[pos][W];
        }

        if (W - wt[pos] < 0)
        {
            // Skip--
            return knapSack(W, wt, val, n, pos + 1, value, arr);
        }

        // Recursive Calls--
        // Case I: If IGNORED--
        int ignored = knapSack(W, wt, val, n, pos + 1, value, arr);

        // Case II: If TAKEN--
        int taken = val[pos] + knapSack(W - wt[pos], wt, val, n, pos + 1, value + val[pos], arr);

        // Maximum Weight--
        return arr[pos][W] = max(ignored, taken);
    }

public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        int **arr = new int *[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[W + 1];
            for (int j = 0; j <= W; j++)
            {
                arr[i][j] = -1;
            }
        }

        // Helper Function--
        return knapSack(W, wt, val, n, 0, 0, arr);
    }
};

// *Method 1*: Recursion--
class Solution
{
    int knapSack(int W, int wt[], int val[], int n, int pos, int value)
    {
        // Base Case--
        if (pos == n || W == 0)
        {
            return 0;
        }
        if (W - wt[pos] < 0)
        {
            // Skip--
            return knapSack(W, wt, val, n, pos + 1, value);
        }

        // Recursive Calls--
        // Case I: If IGNORED--
        int ignored = knapSack(W, wt, val, n, pos + 1, value);

        // Case II: If TAKEN--
        int taken = val[pos] + knapSack(W - wt[pos], wt, val, n, pos + 1, value + val[pos]);

        // Maximum Weight--
        return max(ignored, taken);
    }

public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Helper Function--
        return knapSack(W, wt, val, n, 0, 0);
    }
};