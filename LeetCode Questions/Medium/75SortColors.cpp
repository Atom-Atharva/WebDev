// https://leetcode.com/problems/sort-colors/

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // Count no. of colours(red,white,blue)--
        int r = 0, w = 0, b = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                r++;
            }
            else if (nums[i] == 1)
            {
                w++;
            }
            else
            {
                b++;
            }
        }

        // Place all colors in sorted fashion--
        int i = 0;
        while (r != 0)
        {
            nums[i] = 0;
            i++;
            r--;
        }
        while (w != 0)
        {
            nums[i] = 1;
            i++;
            w--;
        }
        while (b != 0)
        {
            nums[i] = 2;
            i++;
            b--;
        }

        return;
    }
};