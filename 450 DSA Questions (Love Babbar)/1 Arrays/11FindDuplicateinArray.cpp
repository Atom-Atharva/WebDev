// https://leetcode.com/problems/find-the-duplicate-number/

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.

#include <iostream>
using namespace std;
#include <vector>

// Slow and Fast Pointers
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[nums[0]];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

// Wrong Answer
// class Solution
// {
// public:
//     int findDuplicate(vector<int> &nums)
//     {
//         // Calculate n (1 to n)--
//         int n = nums.size() - 1;

//         // Calculate Sum till n--
//         int sum = (n * (n + 1)) / 2;

//         for (int i = 0; i < nums.size(); i++)
//         {
//             sum -= nums[i];
//         }

//         return abs(sum);
//     }
// };