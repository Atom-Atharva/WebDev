// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1

// Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index).

#include <iostream>
using namespace std;

class Solution
{
public:
    string longestPalin(string S)
    {
        int n = S.length();

        // Base Case--
        if (n <= 1)
        {
            return S;
        }

        string ans = "";
        for (int i = 1; i < n; i++)
        {
            // Even Length Palindrome--
            int low = i - 1;
            int high = i;

            // FInd Max Length Palindromic String--
            string even_string = S.substr(low, high - low);
            while (low >= 0 && high < n && S[low] == S[high])
            {
                low--;
                high++;
            }
            if (low != i - 1 && high != i)
            {
                even_string = S.substr(low + 1, high - low);
            }

            // Odd Length Palindrome--
            low = i - 1;
            high = i + 1;

            // Find Max Length Palindromic String--
            string odd_string = S.substr(low + 1, high - low - 1);
            while (low >= 0 && high < n && S[low] == S[high])
            {
                low--;
                high++;
            }
            if (low != i - 1 && high != i + 1)
            {
                odd_string = S.substr(low + 1, high - low);
            }

            // Store max length palindromic String--
            if (ans.length() < max(odd_string.length(), even_string.length()))
            {
                ans = (odd_string.length() > even_string.length()) ? odd_string : even_string;
            }
        }
        return ans;
    }
};