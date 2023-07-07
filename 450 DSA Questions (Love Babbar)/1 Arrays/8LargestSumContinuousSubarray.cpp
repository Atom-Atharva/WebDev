// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

// Kadane's Algorithm

// Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.

#include <iostream>
using namespace std;

class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {
        long long maxsum = arr[0], currsum = 0, curr = arr[0];
        for (int i = 0; i < n; i++)
        {
            currsum = currsum + arr[i];
            curr = arr[i];
            maxsum = max(maxsum, max(currsum, curr));

            // If Break Point--
            if (curr > currsum)
            {
                currsum = curr;
            }
        }

        return maxsum;
    }
};