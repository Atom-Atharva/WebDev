// https://leetcode.com/problems/find-the-difference-of-two-arrays/

// Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

// answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
// answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
// Note that the integers in the lists may be returned in any order.

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> ans;
        unordered_map<int, int> seen1;
        unordered_map<int, int> seen2;

        // Insert Elements in Hash Map--
        for (int i = 0; i < nums1.size(); i++)
        {
            if (seen1.count(nums1[i]) > 0)
            {
                seen1[nums1[i]]++;
                continue;
            }
            seen1[nums1[i]] = 1;
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if (seen2.count(nums2[i]) > 0)
            {
                seen2[nums2[i]]++;
                continue;
            }
            seen2[nums2[i]] = 1;
        }

        // Add distinct element in vector array--
        vector<int> ans1;
        for (auto itr = seen1.begin(); itr != seen1.end(); itr++)
        {
            if (seen2.count(itr->first) > 0)
            {
                seen2[itr->first] = 0;
                continue;
            }
            ans1.push_back(itr->first);
        }
        ans.push_back(ans1);

        // Add distinct element in vector array--
        vector<int> ans2;
        for (auto itr = seen2.begin(); itr != seen2.end(); itr++)
        {
            if (itr->second == 0)
            {
                continue;
            }
            ans2.push_back(itr->first);
        }
        ans.push_back(ans2);

        return ans;
    }
};