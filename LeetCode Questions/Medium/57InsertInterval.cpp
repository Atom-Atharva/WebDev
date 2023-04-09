// https://leetcode.com/problems/insert-interval/

// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

// Return intervals after the insertion.

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {

        bool insert = false;
        vector<vector<int>> ans;

        for (int i = 0; i < intervals.size(); i++)
        {
            if (!insert)
            {
                // newInterval before all elements of intervals--
                if (newInterval[1] < intervals[i][0])
                {
                    ans.push_back(newInterval);
                    insert = true;
                }

                // Not Attached--
                else if (newInterval[0] > intervals[i][1])
                {
                    ans.push_back(intervals[i]);
                }

                // OverLapping--
                else
                {
                    newInterval[0] = (min(intervals[i][0], newInterval[0]));
                    newInterval[1] = (max(intervals[i][1], newInterval[1]));
                }
            }
            if (insert)
            {
                ans.push_back(intervals[i]);
            }
        }

        // If i == n but interval is not inserted--
        if (!insert)
        {
            ans.push_back(newInterval);
        }

        return ans;
    }
};
