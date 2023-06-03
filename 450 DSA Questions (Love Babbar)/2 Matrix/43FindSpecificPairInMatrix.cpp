// https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/

// Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.

// Input:
// mat[N][N] = {{ 1, 2, -1, -4, -20 },
//              { -8, -3, 4, 2, 1 },
//              { 3, 8, 6, 1, 3 },
//              { -4, -1, 1, 7, -6 },
//              { 0, -4, 10, -5, 1 }};
// Output: 18
// The maximum value is 18 as mat[4][2]
// - mat[1][0] = 18 has maximum difference.

#include <iostream>
using namespace std;

#define N 100

// Method 1: Brute Force--
// Time Complexity: O(n^4).
// Itterate Over each element and find max difference for each element.

// Method 2: Pre-computed Matrix (Stores the maximum element)--
// Time Complexity: O(n^2).
class Solution
{
public:
    int maxValue(int mat[][N])
    {
        // Make precompute Matrix (Which stores maximum)--
        int pre[N][N];

        // Last cell--
        pre[N - 1][N - 1] = mat[N - 1][N - 1];

        // Last Row--
        for (int i = N - 2; i >= 0; i--)
        {
            pre[N - 1][i] = max(mat[N - 1][i], pre[N - 1][i + 1]);
        }

        // Last Column--
        for (int i = N - 2; i >= 0; i--)
        {
            pre[i][N - 1] = max(pre[i + 1][N - 1], mat[i][N - 1]);
        }

        // Fill Remaining Cells--
        for (int i = N - 2; i >= 0; i--)
        {
            for (int j = N - 2; j >= 0; j--)
            {
                pre[i][j] = max(mat[i][j], max(pre[i + 1][j], pre[i][j + 1]));
            }
        }

        // Find Maximum Difference--
        int diff = 0;
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = 0; j < N - 1; j++)
            {
                // Find diff of current element in matrix to precomputed diagonal element--
                int curr = pre[i + 1][j + 1] - mat[i][j];
                diff = max(diff, curr);
            }
        }

        return diff;
    }
};