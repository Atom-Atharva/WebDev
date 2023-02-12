// https://leetcode.com/problems/longest-palindromic-substring/

// Given a string s, return the longest
// palindromic
// substring
//  in s.

#include <iostream>
using namespace std;

class Solution
{
public:
    // Brute Force Method--
    // Finding All substrings + Finding Longest Palindrome
    // Time Complexity O(n3).

    // Dynamic Programming--
    // Creating the 2D Array with longest plindromic substring values
    // Time Complexity O(n2).
    string longestPalindrome(string s)
    {
        if (s.length() <= 1)
        {
            return s;
        }

        int n = s.length();
        int arr[n][n];

        // Filling initial cells--
        for (int i = 0; i < n; i++)
        {
            // Diagonal Elements--
            arr[i][i] = 1;

            // Length 2 Elements--
            if (i < n - 1)
            {
                if (s[i] == s[i + 1])
                {
                    arr[i][i + 1] = 1;
                }
                else
                {
                    arr[i][i + 1] = 0;
                }
            }
        }

        // Filling remaining cells--
        for (int j = 2; j < n; j++)
        {
            for (int i = 0; i < n && j + i < n; i++)
            {
                // Check for boundary element && check if the remaining substring is plindrome--
                if (s[i] == s[j + i] && arr[i + 1][j + i - 1] == 1)
                {
                    arr[i][j + i] = 1;
                }
                else
                {
                    arr[i][j + i] = 0;
                }
            }
        }

        // Check for longest palindrome--
        int maxlen = 0, st = -1, en = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j >= i; j--)
            {
                int len = j - i + 1;
                if (arr[i][j] == 1 && len > maxlen)
                {
                    st = i;
                    en = j;
                    maxlen = len;
                }
            }
        }
        string ans = "";
        for (int i = st; i <= en; i++)
        {
            ans += s[i];
        }
        return ans;
    }
};