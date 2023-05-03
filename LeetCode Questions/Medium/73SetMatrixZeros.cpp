// https://leetcode.com/problems/set-matrix-zeroes/

// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        // Insert position of 0s in stack--
        stack<pair<int, int>> pos;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    pos.push({i, j});
                }
            }
        }

        // Change row and coloumn--
        while (!pos.empty())
        {
            pair<int, int> p = pos.top();
            pos.pop();

            int r = p.first;
            int c = p.second;

            for (int i = 0; i < col; i++)
            {
                matrix[r][i] = 0;
            }
            for (int i = 0; i < row; i++)
            {
                matrix[i][c] = 0;
            }
        }
        return;
    }
};