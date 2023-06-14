#include <iostream>
using namespace std;
#include <climits>

// Dynamic Programming (Diagonal Filling)--
class Method3
{
public:
    int matrixChainMultiplication(int *arr, int n)
    {
        // Dynamic Array (start,end)--
        int **dp = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[n + 1];
        }

        // Fill Cases when (st==en)--
        for (int i = 0; i <= n; i++)
        {
            dp[i][i] = 0;
        }

        // Fill Cases when (en-st==1)--
        for (int i = 0; i < n; i++)
        {
            dp[i][i + 1] = 0;
        }

        // Fill Rest of cells (Diagonally)--
        for (int j = 2; j <= n; j++)
        {
            for (int i = 0; i <= n - j; i++)
            {
                // Divide and Calculate--
                int mini = INT_MAX;
                for (int k = i + 1; k < i + j; k++)
                {
                    // Left Cut--
                    int lcount = dp[i][k];

                    // Right Cut--
                    int rcount = dp[k][i + j];

                    // Current Operation--
                    int count = arr[i] * arr[i + j] * arr[k];
                    int total = lcount + rcount + count;

                    // Minimum of All CUTS--
                    mini = min(mini, total);
                }

                dp[i][i + j] = mini;
            }
        }

        return dp[0][n];
    }
};

// Memomization--
class Method2
{
    int matrixMultiplication(int *arr, int **dp, int st, int en)
    {
        // Single Matrix || No Matrix--
        if (en - st <= 1)
        {
            return 0;
        }
        if (dp[st][en] != -1)
        {
            return dp[st][en];
        }

        // Divide and Multiply--
        int mini = INT_MAX;
        for (int i = st + 1; i < en; i++)
        {
            // Reccursion Operations--
            int left = matrixMultiplication(arr, dp, st, i);
            int right = matrixMultiplication(arr, dp, i, en);

            // Current Operation--
            int curr = arr[st] * arr[i] * arr[en];

            // Calculate Minimum Operations--
            mini = min(left + right + curr, mini);
        }

        return dp[st][en] = mini;
    }

public:
    int matrixChainMultiplication(int *arr, int n)
    {
        // Memomization Table (start,end)--
        int **dp = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[n + 1];
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = -1;
            }
        }

        return matrixMultiplication(arr, dp, 0, n);
    }
};

// Reccursion
// Time Limit Exceeded--
class Method1
{
    int matrixMultiplication(int *arr, int st, int en)
    {
        // Single Matrix || No Matrix--
        if (en - st <= 1)
        {
            return 0;
        }

        // Divide and Multiply--
        int mini = INT_MAX;
        for (int i = st + 1; i < en; i++)
        {
            // Reccursion Operations--
            int left = matrixMultiplication(arr, st, i);
            int right = matrixMultiplication(arr, i, en);

            // Current Operation--
            int curr = arr[st] * arr[i] * arr[en];

            // Calculate Minimum Operations--
            mini = min(left + right + curr, mini);
        }

        return mini;
    }

public:
    int matrixChainMultiplication(int *arr, int n)
    {
        return matrixMultiplication(arr, 0, n);
    }
};