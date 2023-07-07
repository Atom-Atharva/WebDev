// https://leetcode.com/problems/maximum-subarray/

// Given an integer array nums, find the
// subarray
//  with the largest sum, and return its sum.

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

class Solution
{
public:
    // Time Complexity : O(n)--
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT_MIN;
        int currmax = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            currmax += nums[i];
            ans = max(currmax, ans);

            // If currmax reach to <0
            currmax = max(currmax, 0);
        }
        return ans;
    }

    // Brute Force--
    // Time Complexity : O(n2)--
    //  int maxSubArray(vector<int> &nums)
    //  {
    //      int ans = INT_MIN;
    //      for (int i = 0; i < nums.size(); i++)
    //      {
    //          int currmax = 0;
    //          for (int j = i; j < nums.size(); j++)
    //          {
    //              currmax += nums[j];
    //              ans = max(currmax, ans);
    //          }
    //      }
    //      return ans;
    //  }
};