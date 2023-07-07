// https://leetcode.com/problems/length-of-last-word/

// Given a string s consisting of words and spaces, return the length of the last word in the string.

// A word is a maximal
// substring
//  consisting of non-space characters only.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    // Optimized Method--
    int lengthOfLastWord(string s)
    {
        int len = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (len != 0 && s[i] == ' ')
            {
                break;
            }
            if (s[i] == ' ')
            {
                continue;
            }
            len++;
        }
        return len;
    }
};
