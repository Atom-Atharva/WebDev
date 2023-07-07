// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

// Given a binary array nums, you should delete one element from it.

// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int maxCount = 0;
        bool zeros = false;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                zeros = true;
                int count = 0;
                for (int j = i - 1; j >= 0; j--)
                {
                    if (nums[j] == 0)
                    {
                        break;
                    }
                    count++;
                }

                for (int j = i + 1; j < n; j++)
                {
                    if (nums[j] == 0)
                    {
                        break;
                    }
                    count++;
                }

                maxCount = max(maxCount, count);
            }
        }

        if (!zeros)
        {
            return n - 1;
        }

        return maxCount;
    }
};