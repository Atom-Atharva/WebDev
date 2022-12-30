// https://leetcode.com/problems/search-insert-position/

// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    // Optimized Solution--
    int searchInsert(vector<int> &nums, int k)
    {
        int st = 0;
        int en = nums.size() - 1;
        int mid;

        while (st <= en)
        {
            mid = st + (en - st) / 2;

            if (nums[mid] < k)
            {
                st = mid + 1;
            }
            else
            {
                en = mid - 1;
            }
        }
        return st;
    }

    // Naive Solution--
    //  int search(vector<int> &nums, int k)
    //  {
    //      int st = 0;
    //      int en = nums.size() - 1;
    //      int mid;

    //     while (st <= en)
    //     {
    //         mid = (st + en) / 2;
    //         if (nums[mid] == k)
    //         {
    //             return mid;
    //         }
    //         else if (nums[mid] > k)
    //         {
    //             en = mid - 1;
    //         }
    //         else
    //         {
    //             st = mid + 1;
    //         }
    //     }
    //     return -1;
    // }

    // int searchInsert(vector<int> &nums, int target)
    // {
    //     int index = search(nums, target);

    //     if (index != -1)
    //     {
    //         return index;
    //     }

    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         if (nums[i] > target)
    //         {
    //             index = i;
    //             break;
    //         }
    //     }
    //     if (index == -1)
    //     {
    //         index = nums.size();
    //     }
    //     return index;
    // }
};