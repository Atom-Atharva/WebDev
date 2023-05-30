// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1

// Given an array arr[] denoting heights of N towers and a positive integer K.

// For each tower, you must perform exactly one of the following operations exactly once.

// Increase the height of the tower by K
// Decrease the height of the tower by K
// Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

// You can find a slight modification of the problem here.
// Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any negative integers.

/***************IMPORTANT QUESTION*****************/

#include <iostream>
using namespace std;
#include <algorithm>
#include <climits>

class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {
        // Sort array--
        sort(arr, arr + n);

        // Get initial Diff--
        int ans = arr[n - 1] - arr[0];
        for (int i = 1; i < n; i++)
        {
            // If negative then skip--
            if (arr[i] - k < 0)
            {
                continue;
            }

            // Find MAX--
            int maxx = max(arr[i - 1] + k, arr[n - 1] - k);
            // Find MIN--
            int minn = min(arr[0] + k, arr[i] - k);

            // Calculate MIN DIFF so far--
            ans = min(ans, maxx - minn);
        }

        return ans;
    }
};