// https://leetcode.com/problems/matrix-diagonal-sum/

// Given a square matrix mat, return the sum of the matrix diagonals.

// Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

#include <iostream>
using namespace std;
#include <vector>

// Optimized Solution--
class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int n = mat.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += mat[i][i];
            if (i != n - i - 1)
                ans += mat[i][n - i - 1];
        }
        return ans;
    }
};

// Naive Solution--
// class Solution
// {
// public:
//     int diagonalSum(vector<vector<int>> &mat)
//     {
//         int n = mat.size();
//         int sum = 0;

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 // Right Diagonal--
//                 if (i == j)
//                 {
//                     sum += mat[i][j];
//                 }
//                 // Left Diagonal--
//                 if (i + j == n - 1)
//                 {
//                     if (n % 2 != 0 && i == n / 2)
//                     {
//                         continue;
//                     }
//                     sum += mat[i][j];
//                 }
//             }
//         }

//         return sum;
//     }
// };