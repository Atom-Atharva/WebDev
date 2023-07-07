// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

// Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.

#include <iostream>
using namespace std;
#include <climits>  

class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {
        long long maxsum = INT_MIN, currsum = 0, curr = 0;
        for (int i = 0; i < n; i++)
        {
            curr = arr[i];
            currsum += curr;

            maxsum = max(maxsum, max(currsum, curr));

            if (currsum < curr)
            {
                currsum = curr;
            }
        }

        return maxsum;
    }
};