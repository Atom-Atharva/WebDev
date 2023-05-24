// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

// Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

#include <iostream>
using namespace std;
#include <vector>

/******************IMPORTANT QUESTION**************************/

/*
    Method 1: Naive Method--
    Time Complexity O(N*M).
    1. Itterate Over each row.
    2. Find Max no of 1s in row.
    3. Return row with max 1s.
*/

// Method 2: Optimized Solution--
// Time Complexity O(M+N);
class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        // Start at top-right corner--
        int i = 0, j = m - 1, r = -1;
        while (j >= 0 && i < n)
        {
            // If cell contain 1 then be on that row--
            if (arr[i][j] == 1)
            {
                r = i;
                j--;
            }
            // Else change row--
            else
            {
                i++;
            }
        }
        return r;
    }
};