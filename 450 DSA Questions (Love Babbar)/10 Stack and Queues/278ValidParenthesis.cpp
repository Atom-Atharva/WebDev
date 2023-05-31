// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1

// Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
// For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

// Note: The drive code prints "balanced" if function return true, otherwise it prints "not balanced"

#include <iostream>
using namespace std;
#include <stack>

class Solution
{
    // Finding Complementary bracket.
    char findOtherPair(char c)
    {
        if (c == '}')
        {
            return '{';
        }
        if (c == ']')
        {
            return '[';
        }
        if (c == ')')
        {
            return '(';
        }
        return -1;
    }

public:
    // Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> element;
        for (int i = 0; i < x.length(); i++)
        {
            // Push opening bracket in stack.
            if (x[i] == '{' || x[i] == '[' || x[i] == '(')
            {
                element.push(x[i]);
                continue;
            }

            // Check for same brackets in stack.
            char topchar = (element.size() > 0) ? element.top() : -1;
            char comp = findOtherPair(x[i]);
            if (topchar != comp)
            {
                return false;
            }
            element.pop();
        }

        // Check if all elements got paired.
        if (element.size() > 0)
        {
            return false;
        }
        return true;
    }
};