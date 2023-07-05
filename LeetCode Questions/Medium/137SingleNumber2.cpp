// https://leetcode.com/problems/single-number-ii/

// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ones = 0;
        int twos = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int curr = nums[i];

            // Solve for ones--
            int res = ones ^ curr;
            ones = res & ~twos;

            // Solve for twos--
            res = twos ^ curr;
            twos = res & ~ones;
        }

        return ones;
    }
};