// https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1

// Given two arrays a[] and b[] of size n and m respectively. The task is to find the number of elements in the union between these two arrays.

// Union of the two arrays can be defined as the set containing distinct elements from both the arrays. If there are repetitions, then only one occurrence of element should be printed in the union.

// Note : Elements are not necessarily distinct.

#include <iostream>
using namespace std;
#include <unordered_map>

class Solution
{
public:
    // Optimized Approach: Hashmaps--
    int doUnion(int a[], int n, int b[], int m)
    {
        unordered_map<int, int> seen;
        for (int i = 0; i < n; i++)
        {
            seen[a[i]]++;
        }
        for (int i = 0; i < m; i++)
        {
            seen[b[i]]++;
        }

        return seen.size();
    }

    // Wrong Ans: As the approach does not handle dupblicate entries--
    //  Function to return the count of number of elements in union of two arrays.
    //  int doUnion(int a[], int n, int b[], int m)
    //  {
    //      sort(a, a + n);
    //      sort(b, b + m);

    //     int i = 0, j = 0;
    //     int count = 0;
    //     while (i < n && j < m)
    //     {
    //         if (a[i] == b[j])
    //         {
    //             count++;
    //             i++;
    //             j++;
    //         }
    //         else if (a[i] < b[j])
    //         {
    //             i++;
    //         }
    //         else
    //         {
    //             j++;
    //         }
    //     }

    //     return m + n - count;
    // }
};