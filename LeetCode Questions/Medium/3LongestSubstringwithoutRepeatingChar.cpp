// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Given a string s, find the length of the longest 
// substring
//  without repeating characters.

#include <iostream>
using namespace std;
#include <unordered_map>

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxlen = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int len = 0;
            unordered_map<int, bool> used;
            int j;
            for (j = i; j < s.length(); j++)
            {
                if (used.count(s[j]) > 0)
                {
                    maxlen = (len > maxlen) ? len : maxlen;
                    break;
                }
                used[s[j]] = 1;
                len++;
            }
            if (j == s.length())
            {
                maxlen = (len > maxlen) ? len : maxlen;
            }
        }
        return maxlen;
    }
};