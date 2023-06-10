// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.

// Example 1:

// Input:
// N = 2
// Arr[] = {2, 2}
// Output: 2 1
// Explanation: Repeating number is 2 and
// smallest positive missing number is 1.

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

// Method 2: Using Equations (SUM and PRODUCT)--
// Wrong Approach: As factorial can exceed the range of long long.
// class Solution
// {
//     long long fact(int n)
//     {
//         if (n == 0 || n == 1)
//         {
//             return 1;
//         }

//         long long ans = fact(n - 1);

//         return ans * n;
//     }

// public:
//     vector<int> findTwoElement(vector<int> arr, int n)
//     {
//         // Sum till n--
//         long long nsum = n * (n + 1) / 2;
//         // Product till n--
//         long long npro = fact(n);

//         // Original Sum and Product--
//         long long P = 1, S = 0;
//         for (int i = 0; i < n; i++)
//         {
//             P *= arr[i];
//             S += arr[i];
//         }

//         // By Solving Two Equations--
//         int y = (S - nsum) * P / (P - (npro));
//         int x = (npro * y) / P;

//         // Repeat and Missing--
//         return {y, x};
//     }
// };

// Method 1: Using Maps--
// Time Complexity O(n).
class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        unordered_map<int, int> seen;
        for (int i = 0; i < n; i++)
        {
            seen[arr[i]]++;
        }

        int repeat;
        int missing;
        for (int i = 1; i <= n; i++)
        {
            if (seen[i] == 2)
            {
                repeat = i;
            }
            if (seen[i] == 0)
            {
                missing = i;
            }
        }

        return {repeat, missing};
    }
};