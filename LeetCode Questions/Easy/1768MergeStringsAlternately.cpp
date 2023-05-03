// https://leetcode.com/problems/merge-strings-alternately/

// You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

// Return the merged string.

#include <iostream>
using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        // Base Case--
        // if (word1.size() == 0 && word2.size() == 0)
        // {
        //     return "";
        // }
        // if (word1.size() == 0)
        // {
        //     return word2;
        // }
        // if (word2.size() == 0)
        // {
        //     return word1;
        // }

        // Alternate Letters--
        int i = 0, j = 0;
        // bool even = true;
        string ans = "";
        while (i < word1.size() && j < word2.size())
        {
            // if (even)
            // {
            //     ans += word1[i];
            //     i++;
            //     even = false;
            // }
            // else
            // {
            //     ans += word2[j];
            //     j++;
            //     even = true;
            // }
            ans += word1[i++];
            ans += word2[j++];
        }

        // Remaining Letter--
        ans += word1.substr(i);
        ans += word2.substr(j);

        // while (i < word1.size())
        // {
        //     ans += word1[i];
        //     i++;
        // }
        // while (j < word2.size())
        // {
        //     ans += word2[j];
        //     j++;
        // }

        return ans;
    }
};