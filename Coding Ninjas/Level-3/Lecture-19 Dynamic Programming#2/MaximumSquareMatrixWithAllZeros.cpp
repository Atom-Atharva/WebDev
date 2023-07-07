#include <iostream>
using namespace std;

// Reccursion--
class Method1
{
public:
    int findMaxSquareWithAllZeros(int **arr, int n, int m)
    {
        // Base Case--
        if (n == 0 || m == 0)
        {
            return 0;
        }

        // Make Dp Array--
        int **dp = new int *[n];
        for (int i = 0; i < n; i++)
        {
            dp[i] = new int[m];
        }

        // Fill Initial Cells--
        dp[0][0] = (arr[0][0] == 1) ? 0 : 1;

        // Fill First Row--
        for (int j = 1; j < m; j++)
        {
            dp[0][j] = (arr[0][j] == 1) ? 0 : 1;
        }

        // Fill First Column--
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = (arr[i][0] == 1) ? 0 : 1;
        }

        // Fill Remaining Cells--
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                // If One--
                if (arr[i][j] == 1)
                {
                    dp[i][j] = 0;
                    continue;
                }

                // Check row and coloumn of the arr--
                int ele = dp[i - 1][j - 1];
                int k = 1;
                for (k = 1; k <= ele; k++)
                {
                    if (arr[i][j - k] == 1 || arr[i - k][j] == 1)
                    {
                        break;
                    }
                }
                dp[i][j] = k;
            }
        }

        // Calculate Maximum Square--
        int maximum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                maximum = max(maximum, dp[i][j]);
            }
        }

        return maximum;
    }
};