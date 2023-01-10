// https://leetcode.com/problems/pascals-triangle

// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Given Pascal's triangle structure

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        int row = 1;
        vector<vector<int>> ans;

        while (row <= numRows)
        {
            vector<int> rowline;

            for (int i = 1; i <= row; i++)
            {
                if (i == 1 || i == row)
                {
                    rowline.push_back(1);
                }
                else
                {
                    int element = ans[row - 2][i - 2] + ans[row - 2][i - 1];
                    rowline.push_back(element);
                }
            }

            ans.push_back(rowline);
            row++;
        }
        return ans;
    }
};
