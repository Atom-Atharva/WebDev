// https://leetcode.com/problems/next-permutation/

// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

#include <iostream>
using namespace std;
#include <vector>

//******************* CONCEPTUAL PROBLEM *************************//
//! HINT FOR THE PROBLEM   --->   https://www.youtube.com/watch?v=LuLCLgMElus

class Solution
{
    void swap(vector<int> &nums, int a, int b)
    {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
        return;
    }

    void reverse(vector<int> &nums, int st)
    {
        int en = nums.size() - 1;
        while (st < en)
        {
            swap(nums, st, en);
            st++;
            en--;
        }
        return;
    }

public:
    void nextPermutation(vector<int> &nums)
    {
        // Base Case--
        if (nums.size() <= 1)
        {
            return;
        }

        int eletoswap = -1;
        int elebyswap = 0;

        // Finding elements for the swap--
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                eletoswap = i;
                break;
            }
        }

        if (eletoswap == -1)
        {
            reverse(nums, 0);
            return;
        }

        // Finding elements by which it is swapped--
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] > nums[eletoswap])
            {
                elebyswap = i;
                break;
            }
        }

        // Swap Elements--
        swap(nums, eletoswap, elebyswap);

        // Reverse Array after element to swap--
        reverse(nums, eletoswap + 1);

        return;
    }
};