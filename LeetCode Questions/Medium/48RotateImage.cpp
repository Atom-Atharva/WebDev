// https://leetcode.com/problems/rotate-image/

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

#include <iostream>
using namespace std;
#include <vector>

// Approach for 90 clockwise rotation--
//       -> Mirror form diagonal
//       -> Swap first and last likewise

class Solution
{
public:
    void rotate(vector<vector<int>> &nums)
    {
        int n = nums.size();

        // Mirror from diagonal--
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int temp = nums[i][j];
                nums[i][j] = nums[j][i];
                nums[j][i] = temp;
            }
        }

        // Swap (first,last),(second,secondlast),and so on--
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                int temp = nums[i][j];
                nums[i][j] = nums[i][n - 1 - j];
                nums[i][n - 1 - j] = temp;
            }
        }

        return;
    }
};