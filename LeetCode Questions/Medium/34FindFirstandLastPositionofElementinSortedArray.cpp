// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    vector<int> searchEnds(vector<int> &nums, int mid)
    {
        int n = nums.size();
        vector<int> ans = {mid, mid};
        for (int i = mid; i < n; i++)
        {
            if (nums[mid] == nums[i])
            {
                ans[1] = i;
            }
            else
            {
                break;
            }
        }

        for (int i = mid; i >= 0; i--)
        {
            if (nums[mid] == nums[i])
            {
                ans[0] = i;
            }
            else
            {
                break;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() < 1)
        {
            return {-1, -1};
        }
        int st = 0, en = nums.size() - 1;
        vector<int> ans = {-1, -1};
        while (st <= en)
        {
            int mid = (st + en) / 2;
            if (nums[mid] == target)
            {
                ans = searchEnds(nums, mid);
                break;
            }
            else if (nums[mid] > target)
            {
                en = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        return ans;
    }
};