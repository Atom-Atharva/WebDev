// https://leetcode.com/problems/jump-game-ii/

// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

// Constraints:

//      1 <= nums.length <= 104
//      0 <= nums[i] <= 1000
//      It's guaranteed that you can reach nums[n - 1].

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int jumps = 0;
        int current = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            farthest = max(farthest, nums[i] + i);

            if (i == current)
            {
                current = farthest;
                jumps++;
            }
        }
        return jumps;
    }
};