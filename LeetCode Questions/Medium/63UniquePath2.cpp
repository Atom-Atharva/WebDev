// https://leetcode.com/problems/unique-paths-ii/

// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The testcases are generated so that the answer will be less than or equal to 2 * 109.

#include <iostream>
using namespace std;
#include <vector>

// Dynamic Approach--
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstaclesGrid)
    {
        int m = obstaclesGrid.size();
        int n = obstaclesGrid[0].size();

        vector<vector<int>> arr(m, vector<int>(n, 0));

        // Check for Base Case--
        if (obstaclesGrid[0][0])
        {
            return 0;
        }

        // Fill First Cell--
        arr[0][0] = 1;

        // Fill First Coloumn--
        for (int i = 1; i < m; i++)
        {
            if (obstaclesGrid[i][0])
            {
                arr[i][0] = 0;
            }
            else
            {
                arr[i][0] = arr[i - 1][0];
            }
        }

        // Fill First Row--
        for (int i = 1; i < n; i++)
        {
            if (obstaclesGrid[0][i])
            {
                arr[0][i] = 0;
            }
            else
            {
                arr[0][i] = arr[0][i - 1];
            }
        }

        // Fill Remaining Cells--
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstaclesGrid[i][j])
                {
                    arr[i][j] = 0;
                }
                else
                {
                    arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
                }
            }
        }
        return arr[m - 1][n - 1];
    }
};

// Reccursive Approach--
//  class Solution
//  {
//      int uniquePathsWithObstacles(vector<vector<int>> &obstaclesGrid, int m, int n, int i, int j)
//      {
//          // Base Case--
//          if (i == m - 1 && j == n - 1 && obstaclesGrid[i][j] == 0)
//          {
//              return 1;
//          }
//          if (i == m || j == n)
//          {
//              return 0;
//          }
//          if (obstaclesGrid[i][j] == 1)
//          {
//              return 0;
//          }

//         // Reccursive Calls--
//         int p1 = uniquePathsWithObstacles(obstaclesGrid, m, n, i + 1, j);
//         int p2 = uniquePathsWithObstacles(obstaclesGrid, m, n, i, j + 1);

//         return p1 + p2;
//     }

// public:
//     int uniquePathsWithObstacles(vector<vector<int>> &obstaclesGrid)
//     {
//         int m = obstaclesGrid.size();
//         int n = obstaclesGrid[0].size();

//         return uniquePathsWithObstacles(obstaclesGrid, m, n, 0, 0);
//     }
// };