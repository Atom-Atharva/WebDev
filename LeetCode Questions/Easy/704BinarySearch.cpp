// https://leetcode.com/problems/binary-search/

// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.

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
            else if (nums[mid] > target)
            {
                en = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        return -1;
    }
};