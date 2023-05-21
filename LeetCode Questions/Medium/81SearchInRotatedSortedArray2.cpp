// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

// There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

// Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

// Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

// You must decrease the overall operation steps as much as possible.

/*************IMPORTANT QUESTION****************/

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int st = 0, en = nums.size() - 1;
        while (st <= en)
        {
            int mid = (st + en) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            // If first part is sorted--
            else if (nums[mid] >= nums[st])
            {
                // If target Lies in the part--
                if (nums[mid] > target && nums[st] <= target)
                {
                    en = mid - 1;
                }
                else
                {
                    st = mid + 1;
                }
            }
            // If second part is sorted--
            else if (nums[mid] < nums[st])
            {
                // If target Lies in the part--
                if (nums[mid] < target && nums[en] >= target)
                {
                    st = mid + 1;
                }
                else
                {
                    en = mid - 1;
                }
            }
            else
            {
                st++;
            }
        }
        return false;
    }
};