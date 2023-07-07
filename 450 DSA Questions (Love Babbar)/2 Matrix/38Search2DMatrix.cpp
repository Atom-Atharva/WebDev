// https://leetcode.com/problems/search-a-2d-matrix/

// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        // Select Row O(log(row))--
        int rs = 0, re = row - 1;
        int r;
        while (rs <= re)
        {
            int mid = (rs + re) / 2;

            if (rs == re)
            {
                r = rs;
                rs = mid + 1;
            }
            else if (target <= matrix[mid][col - 1])
            {
                re = mid;
            }
            else
            {
                rs = mid + 1;
            }
        }

        // Select Row O(row)--
        // int r = 0;
        // for (int i = 0; i < row; i++)
        // {
        //     if (matrix[i][col - 1] >= target)
        //     {
        //         r = i;
        //         break;
        //     }
        // }

        // Binary Search on Selected Row--
        int st = 0, en = col - 1;
        while (st <= en)
        {
            int mid = (st + en) / 2;

            if (matrix[r][mid] == target)
            {
                return true;
            }
            else if (matrix[r][mid] < target)
            {
                st = mid + 1;
            }
            else
            {
                en = mid - 1;
            }
        }
        return false;
    }
};