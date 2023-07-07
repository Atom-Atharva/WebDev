// https://leetcode.com/problems/scramble-string/description/

// We can scramble a string s to get a string t using the following algorithm:

// If the length of the string is 1, stop.
// If the length of the string is > 1, do the following:
// Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
// Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
// Apply step 1 recursively on each of the two substrings x and y.
// Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

// Memoization + Pruning--
class Solution
{
    unordered_map<string, bool> mem;

public:
    bool isScramble(string s1, string s2)
    {
        // Base Case--
        if (s1.length() == 1)
        {
            return s1 == s2;
        }
        if (s1 == s2)
        {
            return true;
        }

        // Memoization Technique: Using previous result--
        string key = s1 + s2;
        if (mem.find(key) != mem.end())
        {
            return mem[key];
        }
        int n = s1.size();

        // Pruning: Avoid unnecessary recursive calls--
        vector<int> f1(26), f2(26);
        for (int i = 0; i < n; i++)
        {
            f1[s1[i] - 'a']++;
            f2[s2[i] - 'a']++;
        }

        if (f1 != f2)
        {
            return mem[key] = false;
        }

        // Partition String--
        for (int i = 1; i < n; i++)
        {
            // Reccursive Call--
            // Swap Elements--
            bool swap = isScramble(s1.substr(0, i), s2.substr(n - i, i)) && isScramble(s1.substr(i, n - i), s2.substr(0, n - i));

            // Not Swapping Elements--
            bool remain = isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n - i), s2.substr(i, n - i));

            if (swap || remain)
            {
                return mem[key] = true;
            }
        }
        return mem[key] = false;
    }
};

// Reccursion Only--
// class Solution
// {
// public:
//     bool isScramble(string s1, string s2)
//     {
//         // Base Case--
//         if (s1.length() == 1)
//         {
//             return s1 == s2;
//         }
//         if (s1 == s2)
//         {
//             return true;
//         }

//         int n = s1.size();

//         // Partition String--
//         for (int i = 1; i < n; i++)
//         {
//             // Reccursive Call--
//             // Swap Elements--
//             bool swap = isScramble(s1.substr(0, i), s2.substr(n - i, i)) && isScramble(s1.substr(i, n - i), s2.substr(0, n - i));

//             // Not Swapping Elements--
//             bool remain = isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n - i), s2.substr(i, n - i));

//             if (swap || remain)
//             {
//                 return true;
//             }
//         }
//         return false;
//     }
// };