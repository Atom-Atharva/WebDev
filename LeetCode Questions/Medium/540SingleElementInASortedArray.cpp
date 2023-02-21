// https://leetcode.com/problems/single-element-in-a-sorted-array/

// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    // Optimized Solution--
    // Time Complexity O(log n)
    int singleNonDuplicate(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
                left = mid + 1;
            else
                right = mid;
        }

        return nums[left];
    }
    // Naive Solution--
    // Time Complexity O(n)
    // int singleNonDuplicate(vector<int> &nums)
    // {
    //     int ans = 0;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         ans = ans ^ nums[i];
    //     }
    //     return ans;
    // }
};