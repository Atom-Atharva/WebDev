// https://leetcode.com/problems/merge-intervals/

// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // Sorting Array--
        sort(intervals.begin(), intervals.end());

        // Valid for sorted array--
        vector<vector<int>> ans;

        int st = intervals[0][0];
        int en = intervals[0][1];

        vector<int> inter;
        inter.push_back(st);
        inter.push_back(en);

        for (int i = 1; i < intervals.size(); i++)
        {
            // Check for overlapping--
            if ((intervals[i][0] > en && intervals[i][1] > en) || (intervals[i][0] < st && intervals[i][1] < st))
            {
                ans.push_back(inter);
                st = intervals[i][0];
                en = intervals[i][1];
            }
            else
            {
                st = min(st, intervals[i][0]);
                en = max(en, intervals[i][1]);
            }
            inter[0] = st;
            inter[1] = en;
        }
        ans.push_back(inter);

        return ans;
    }
};