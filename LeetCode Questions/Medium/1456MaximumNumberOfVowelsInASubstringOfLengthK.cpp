// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

// Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

#include <iostream>
using namespace std;

class Solution
{
    bool isVow(char c)
    {
        if (c == 'a' ||
            c == 'e' ||
            c == 'i' ||
            c == 'o' ||
            c == 'u')
        {
            return true;
        }
        return false;
    }

public:
    int maxVowels(string s, int k)
    {
        int n = s.size();
        int vow = 0;
        // First count k window--
        for (int i = 0; i < k; i++)
        {
            if (isVow(s[i]))
            {
                vow++;
            }
        }
        if (vow == k)
        {
            return vow;
        }

        // Shifting Windows--
        int maxvow = vow;
        int st = 0;
        for (int en = k ; en < n; st++, en++)
        {
            if (isVow(s[en]))
            {
                if (!isVow(s[st]))
                {
                    vow++;
                }
            }
            else
            {
                if (isVow(s[st]))
                {
                    vow--;
                }
            }

            if (vow > maxvow)
            {
                maxvow = vow;
            }
        }
        return maxvow;
    }
};

// Time Limit Exceeded--
// Time Complexity = O(k*n)
// class Solution
// {
//     int countVow(string s)
//     {
//         int vow = 0;
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
//             {
//                 vow++;
//             }
//         }
//         return vow;
//     }

// public:
//     int maxVowels(string s, int k)
//     {
//         int n = s.size();
//         int maxvow = 0;
//         for (int i = 0; i <= n - k; i++)
//         {
//             int vow = countVow(s.substr(i, k));
//             if (vow > maxvow)
//             {
//                 maxvow = vow;
//             }
//         }
//         return maxvow;
//     }
// };
