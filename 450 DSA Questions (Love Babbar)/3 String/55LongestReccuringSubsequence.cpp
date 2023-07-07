// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

// Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

// The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of first "x" must be different in the original string for A and B.

/****************IMPORTANT QUESTION**********************/

// PREREQUISTIE: Longest Common Subsequencee

// Approach: Find out longest common subsequence excluding 2 characters at same index--

#include <iostream>
using namespace std;

class Solution
{
public:
    int LongestRepeatingSubsequence(string str)
    {
        // GOAL: Find Longest Common Subsequence with no 2 character shares same index--

        int n = str.size();
        int **arr = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            arr[i] = new int[n + 1];
        }

        // Fill First Cell--
        arr[0][0] = 0;

        // Fill First Row--
        for (int i = 1; i <= n; i++)
        {
            arr[0][i] = 0;
        }

        // Fill First Column--
        for (int i = 0; i <= n; i++)
        {
            arr[i][0] = 0;
        }

        // Fill Remaining Cells--
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // Contraint: (i != j)
                if (str[i - 1] == str[j - 1] && i != j)
                {
                    arr[i][j] = 1 + arr[i - 1][j - 1];
                }
                else
                {
                    arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
                }
            }
        }

        return arr[n][n];
    }
};