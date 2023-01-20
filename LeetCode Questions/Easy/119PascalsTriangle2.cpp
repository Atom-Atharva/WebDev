// https://leetcode.com/problems/pascals-triangle-ii/

// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Given Pascal's Triangle

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans;
        ans[0] = 1;

        for (int i = 1; i < rowIndex; i++)
        {
            for (int j = i; j >= 1; j--)
            {
                ans[j] = ans[j] + ans[j - 1];
            } 
        }
        return ans;
    }
};