// https://leetcode.com/problems/minimum-size-subarray-sum/

// Given an array of positive integers nums and a positive integer target, return the minimal length of a
// subarray
//  whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

// Sliding Window Problem--
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int l = 0, r = 0, sum = nums[0];
        int minlen = INT_MAX;
        while (r < nums.size() && l < nums.size())
        {
            if (l > r)
            {
                r = l;
                if (l == nums.size())
                {
                    break;
                }
                sum = nums[l];
            }

            if (sum >= target)
            {
                // Find Minimum Length--
                minlen = min(minlen, r - l + 1);

                sum -= nums[l];
                l++;
            }
            else
            {
                r++;

                if (r == nums.size())
                {
                    break;
                }
                sum += nums[r];
            }
        }

        if (minlen == INT_MAX)
        {
            return 0;
        }
        return minlen;
    }
};
