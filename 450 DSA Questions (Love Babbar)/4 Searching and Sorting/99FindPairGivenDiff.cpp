// https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1

// Given an array Arr[] of size L and a number N, you need to write a program to find if there exists a pair of elements in the array whose difference is N.

// Example 1:

// Input:
// L = 6, N = 78
// arr[] = {5, 20, 3, 2, 5, 80}
// Output: 1
// Explanation: (2, 80) have difference of 78.

#include <iostream>
using namespace std;
#include <algorithm>

// Method 2: Sort and 2 Pointer--
// Time Complextiy: O(nlogn)--
class Solution
{
public:
    bool findPair(int a[], int l, int n)
    {
        // Sort Array--
        sort(a, a + l);

        // Initialize from starting position--
        int i = 0, j = 0;
        while (j <= l - 1)
        {
            // If diff same--
            if (a[j] - a[i] == n && i != j)
                return true;

            // if diff less--
            else if (a[j] - a[i] < n)
                j++;

            // if diff more--
            else
                i++;
        }
        
        return false;
    }
};

// Time Limit Exceeded-
// Method 1:Reccursion--
class Solution
{
    bool find(int arr[], int size, int n, int st, int en)
    {
        // Base Case--
        if (st < 0 || en >= n)
        {
            return false;
        }
        int diff = arr[en] - arr[st];
        if (diff == n)
        {
            return true;
        }
        if (diff > n)
        {
            return -1;
        }

        // Reccursive Calls--
        bool lfind = find(arr, size, n, st - 1, en);
        bool rfind = find(arr, size, n, st, en + 1);

        return lfind || rfind;
    }

public:
    bool findPair(int arr[], int size, int n)
    {
        // Sort the array--
        sort(arr, arr + size);

        return find(arr, size, n, (size / 2) - 1, size / 2);
    }
};