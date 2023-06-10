// https://practice.geeksforgeeks.org/problems/searching-in-an-array-where-adjacent-differ-by-at-most-k0456/1

// A step array is an array of integers where each element has a difference of at most k with its neighbor. Given a key x, we need to find the index value of x if multiple elements exist, and return the first occurrence of the key.

// Example 1:

// Input : arr[ ] = {4, 5, 6, 7, 6}, K = 1
//         and X = 6
// Output : 2
// Explanation:
// In an array arr 6 is present at index 2.
// So, return 2.

#include <iostream>
using namespace std;

class Solution
{
public:
    // x is the element to be searched in arr[0..n-1]
    // such that all elements differ by at-most k.
    int search(int arr[], int n, int x, int k)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
            {
                return i;
            }
        }

        return -1;
    }
};