// https://leetcode.com/problems/rotate-array/description/

// Given an array, rotate the array to the right by k steps, where k is non-negative.

#include <vector>
using namespace std;

class Solution
{
public:
    // Optimized Solution--
    void reverse(vector<int> &nums, int st, int en)
    {
        for (int i = 0; i <= (en - st) / 2; i++)
        {
            int temp = nums[st + i];
            nums[st + i] = nums[en - i];
            nums[en - i] = temp;
        }
        return;
    }

    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        int n = nums.size();
        if (n <= 1 || k == 0 || k == nums.size())
        {
            return;
        }
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);

        return;
    }

    // Naive Approach--
    // void rotate(vector<int> &nums, int k)
    // {
    //     vector<int> temp;

    //     int n = nums.size();
    //     k = k % n;
    //     for (int i = n - k; i < n; i++)
    //     {
    //         temp.push_back(nums[i]);
    //     }
    //     for (int i = 0; i <= n - k - 1; i++)
    //     {
    //         temp.push_back(nums[i]);
    //     }

    //     for (int i = 0; i < n; i++)
    //     {
    //         nums[i] = temp[i];
    //     }
    // }
};