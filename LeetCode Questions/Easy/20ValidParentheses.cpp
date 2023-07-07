// https://leetcode.com/problems/valid-parentheses/

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

#include <iostream>
using namespace std;
#include <stack>
#include <unordered_map>

class Solution
{
public:

    // Optimized Solution--
    bool isValid(string s)
    {
        unordered_map<char, char> brack = {{'}', '{'},
                                           {')', '('},
                                           {']', '['}};

        stack<char> c;
        c.push('\0');
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            {
                c.push(s[i]);
            }
            else
            {
                if (brack[s[i]] == c.top())
                {
                    c.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if (c.top() != '\0')
        {
            return false;
        }
        return true;
    }
};