// https://leetcode.com/problems/minimum-path-sum/

// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    // Using Dynamic Programming--
    int minPathSum(vector<vector<int>> &grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Creating path arr;
        int **arr = new int *[m];
        for (int i = 0; i < m; i++)
        {
            arr[i] = new int[n];
        }

        // Filling First Element--
        arr[0][0] = grid[0][0];

        // Filling First Row--
        for (int i = 1; i < n; i++)
        {
            arr[0][i] = grid[0][i] + arr[0][i - 1];
        }

        // Filling First Coloumn--
        for (int i = 1; i < m; i++)
        {
            arr[i][0] = grid[i][0] + arr[i - 1][0];
        }

        // Filling Remaing Cells--
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                arr[i][j] = grid[i][j] + min(arr[i - 1][j], arr[i][j - 1]);
            }
        }

        return arr[m - 1][n - 1];
    }

    // Using Reccursion--
    // int minPathSum(vector<vector<int>> &grid, int i, int j)
    // {
    //     // Base Case--
    //     if (i > grid.size() - 1 || j > grid[0].size() - 1)
    //     {
    //         return -1;
    //     }
    //     if (i == grid.size() - 1 && j == grid[0].size() - 1)
    //     {
    //         return grid[i][j];
    //     }

    //     // Reccursive Call--
    //     int rpath = minPathSum(grid, i, j + 1);
    //     int dpath = minPathSum(grid, i + 1, j);

    //     // Calculate minimum Path--
    //     int minpath = grid[i][j];
    //     if (rpath == -1)
    //     {
    //         minpath = minpath + dpath;
    //     }
    //     else if (dpath == -1)
    //     {
    //         minpath = minpath + rpath;
    //     }
    //     else
    //     {
    //         minpath = minpath + min(dpath, rpath);
    //     }

    //     return minpath;
    // }

public:
    int minPathSum(vector<vector<int>> &grid)
    {

        return minPathSum(grid, 0, 0);
    }
};