// https://leetcode.com/problems/3sum-closest/

// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <climits>

class Solution
{
public:
    // Brute Force O(n3)--
    //  Itterate over each element and find the closest sum to target

    // Optimized Solution O(n2)--
    // Two Pointer Approach--
    int threeSumClosest(vector<int> &nums, int target)
    {
        // Sort the array--
        sort(nums.begin(), nums.end());

        int ans = INT_MAX;
        int minclose = INT_MAX;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            // Two Pointers--
            int st = i + 1, en = nums.size() - 1;
            while (st < en)
            {
                // Check for minclose--
                int sum = nums[i] + nums[st] + nums[en];
                int close = abs(target - sum);
                int minclose = min(minclose, close);
                if (minclose == close)
                {
                    ans = sum;
                }

                // Moving pointers--
                if (sum < target)
                {
                    st++;
                }
                else if (sum > target)
                {
                    en--;
                }
                else
                {
                    st++;
                    en--;
                }
            }
        }
        return ans;
    }
};