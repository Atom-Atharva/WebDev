// https://leetcode.com/problems/search-in-rotated-sorted-array/

// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int st = 0, en = nums.size() - 1;
        while (st <= en)
        {
            int mid = (st + en) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }

            // If left part is sorted--
            if (nums[mid] >= nums[st])
            {
                // If element exitst in sorted part--
                if (nums[mid] >= target && nums[st] <= target)
                {
                    en = mid - 1;
                }
                else
                {
                    st = mid + 1;
                }
            }

            // If right part is sorted--
            else
            {
                // If element exist in sorted part--
                if (nums[mid] <= target && nums[en] >= target)
                {
                    st = mid + 1;
                }
                else
                {
                    en = mid - 1;
                }
            }
        }
        return -1;
    }
};