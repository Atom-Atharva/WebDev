// https://leetcode.com/problems/median-of-two-sorted-arrays/

// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> merge;
        int i, j;
        for (i = 0, j = 0; i < nums1.size() && j < nums2.size();)
        {
            if (nums1[i] <= nums2[j])
            {
                merge.push_back(nums1[i]);
                i++;
            }
            else
            {
                merge.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size())
        {
            merge.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size())
        {
            merge.push_back(nums2[j]);
            j++;
        }

        if (merge.size() % 2 != 0)
        {
            return (double)merge[merge.size() / 2];
        }

        return ((double)merge[merge.size() / 2] + merge[(merge.size() / 2) - 1]) / 2;
    }
};