// https://leetcode.com/problems/reverse-string/

// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{

public:
    void reverseString(vector<char> &s)
    {
        for (int i = 0; i < s.size() / 2; i++)
        {
            char temp = s[i];
            s[i] = s[s.size() - 1 - i];
            s[s.size() - 1 - i] = temp;
        }

        return;
    }
};