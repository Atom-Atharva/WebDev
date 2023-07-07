// https://leetcode.com/problems/jump-game/

// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxjump = nums[0];
        if (maxjump == 0 && nums.size() > 1)
        {
            return false;
        }

        for (int i = 1; i < nums.size() - 1; i++)
        {
            maxjump = max(maxjump - 1, nums[i]);
            if (maxjump == 0)
            {
                return false;
            }
        }
        return true;
    }
};