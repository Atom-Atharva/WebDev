// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

#include <iostream>
using namespace std;

class Solution
{
public:
    // Using STL--
    int strStr(string haystack, string needle)
    {
        return haystack.find(needle);
    }

    // Itterative Approach--
    // int strStr(string haystack, string needle)
    // {
    //     int occ = -1;
    //     int ans = -1;
    //     int j = 0;
    //     for (int i = 0; j < needle.size() && i < haystack.size(); i++)
    //     {

    //         // Check for needle--
    //         if (needle[j] == haystack[i])
    //         {
    //             // Occurance set to first location--
    //             if (j == 0)
    //             {
    //                 occ = i;
    //             }
    //             j++;
    //         }
    //         else
    //         {
    //             // Reset to last index--
    //             if (occ != -1)
    //             {
    //                 i = occ;
    //             }
    //             j = 0;
    //             occ = -1;
    //         }
    //     }
    //     // Confirm full needle found--
    //     if (j == needle.size())
    //     {
    //         ans = occ;
    //     }
    //     return ans;
    // }
};