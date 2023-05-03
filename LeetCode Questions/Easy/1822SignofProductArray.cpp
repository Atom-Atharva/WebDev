// https://leetcode.com/problems/sign-of-the-product-of-an-array/

// There is a function signFunc(x) that returns:

// 1 if x is positive.
// -1 if x is negative.
// 0 if x is equal to 0.
// You are given an integer array nums. Let product be the product of all values in the array nums.

// Return signFunc(product).

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int n = nums.size();

        int ans = 1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                return 0;
            }
            if (nums[i] < 0)
            {
                ans *= -1;
            }
        }
        return ans;
    }
};