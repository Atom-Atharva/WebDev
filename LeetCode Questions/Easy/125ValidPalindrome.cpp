// https://leetcode.com/problems/valid-palindrome/

// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

#include <iostream>
using namespace std;

class Solution
{
public:
    char lowerNum(char c)
    {
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            return c;
        }
        else
        {
            return c - 'A' + 'a';
        }
    }
    bool isAlphaNum(char c)
    {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            return true;
        }
        return false;
    }
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i <= j)
        {
            if (!isAlphaNum(s[i]))
            {
                i++;
                continue;
            }
            if (!isAlphaNum(s[j]))
            {
                j--;
                continue;
            }

            if (lowerNum(s[i]) != lowerNum(s[j]))
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }

    // bool isPalindrome(string s)
    // {
    //     // End Case--
    //     if (s.size() == 0)
    //     {
    //         return true;
    //     }

    //     string ans = "";

    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         if (s[i] >= 'a' && s[i] <= 'z')
    //         {
    //             ans += s[i];
    //         }
    //         else if (s[i] >= 'A' && s[i] <= 'Z')
    //         {
    //             ans += s[i] - 'A' + 'a';
    //         }
    //         else if (s[i] >= '0' && s[i] <= '9')
    //         {
    //             ans += s[i];
    //         }
    //         else
    //         {
    //             continue;
    //         }
    //     }

    //     // Check Palindrome--
    //     for (int i = 0; i < ans.size() / 2; i++)
    //     {
    //         if (ans[i] != ans[ans.size() - 1 - i])
    //         {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
};