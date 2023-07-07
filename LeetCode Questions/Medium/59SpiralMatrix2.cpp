// https://leetcode.com/problems/spiral-matrix-ii/

// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        // Base Case--
        if (n == 0)
        {
            return {{}};
        }

        vector<vector<int>> matrix(n, vector<int>(n));

        int cst = 0, rst = 0, cen = n - 1, ren = n - 1;
        int element = 1;
        while (cst <= cen && rst <= ren)
        {
            // First Row--
            for (int i = cst; cst <= cen && i <= cen; i++)
            {
                matrix[rst][i] = element;
                element++;
            }
            rst++;

            // Last Column--
            for (int i = rst; rst <= ren && i <= ren; i++)
            {
                matrix[i][cen] = element;
                element++;
            }
            cen--;

            // Last Row--
            for (int i = cen; cst <= cen && i >= cst; i--)
            {
                matrix[ren][i] = element;
                element++;
            }
            ren--;

            // First Column--
            for (int i = ren; rst <= ren && i >= rst; i--)
            {
                matrix[i][cst] = element;
                element++;
            }
            cst++;
        }

        return matrix;
    }
};