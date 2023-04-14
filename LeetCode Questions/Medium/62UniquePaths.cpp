// https://leetcode.com/problems/unique-paths/

// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or equal to 2 * 109.

#include <iostream>
using namespace std;

// Dynamic Programming--
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // DP Array--
        int **arr = new int *[m];
        for (int i = 0; i < m; i++)
        {
            arr[i] = new int[n];
        }

        // Fill First Cell--
        arr[0][0] = 1;

        // Fill first coloumn--
        for (int i = 1; i < m; i++)
        {
            arr[i][0] = 1;
        }

        // Fill first row--
        for (int i = 1; i < n; i++)
        {
            arr[0][i] = 1;
        }

        // Fill rest of cells--
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
            }
        }

        return arr[m - 1][n - 1];
    }
};

// Reccursion--
// class Solution
//  {
//      int uniquePaths(int m, int n, int i, int j)
//      {
//          // Base Case--
//          if (i == m - 1 && j == n - 1)
//          {
//              return 1;
//          }
//          if (i == m || j == n)
//          {
//              return 0;
//          }

//         // Reccursive Calls--
//         int p1 = uniquePaths(m, n, i + 1, j);
//         int p2 = uniquePaths(m, n, i, j + 1);

//         // Small Calculation--
//         return p1 + p2;
//     }

// public:
//     int uniquePaths(int m, int n)
//     {
//         return uniquePaths(m, n, 0, 0);
//     }
// };
