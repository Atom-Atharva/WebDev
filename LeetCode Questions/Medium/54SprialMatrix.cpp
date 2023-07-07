// https://leetcode.com/problems/spiral-matrix/

// Given an m x n matrix, return all elements of the matrix in spiral order.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int r_st = 0, r_en = matrix.size() - 1;
        int c_st = 0, c_en = matrix[0].size() - 1;

        vector<int> ans;

        while (r_st <= r_en && c_st <= c_en)
        {
            // Top Row--
            for (int i = c_st; i <= c_en; i++)
            {
                ans.push_back(matrix[r_st][i]);
            }
            r_st++;

            // Last Column--
            if (r_st > r_en)
            {
                break;
            }
            for (int i = r_st; i <= r_en; i++)
            {
                ans.push_back(matrix[i][c_en]);
            }
            c_en--;

            // Bottom Row--
            if (c_st > c_en)
            {
                break;
            }
            for (int i = c_en; i >= c_st; i--)
            {
                ans.push_back(matrix[r_en][i]);
            }
            r_en--;

            // First Coloumn--
            if (r_st > r_en)
            {
                break;
            }
            for (int i = r_en; i >= r_st; i--)
            {
                ans.push_back(matrix[i][c_st]);
            }
            c_st++;
        }

        return ans;
    }
};