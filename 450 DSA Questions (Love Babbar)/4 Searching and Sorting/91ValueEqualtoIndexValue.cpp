// https://practice.geeksforgeeks.org/problems/value-equal-to-index-value1330/1

// Given an array Arr of N positive integers. Your task is to find the elements whose value is equal to that of its index value ( Consider 1-based indexing ).

// Note: There can be more than one element in the array which have the same value as its index. You need to include every such element's index. Follows 1-based indexing of the array.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    // Linear Search in an Array--
    // Time Complexity O(n).
    vector<int> valueEqualToIndex(int arr[], int n)
    {
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == i + 1)
            {
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};