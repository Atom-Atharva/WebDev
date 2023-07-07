// https://leetcode.com/problems/generate-parentheses/

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    void generateParenthesis(int n, vector<string> &ans, int open, int close, string pat)
    {
        // Base Case--
        if (close > open)
        {
            return;
        }
        if (open > n)
        {
            return;
        }
        if (close == n && open == n)
        {
            ans.push_back(pat);
        }

        // Reccursive Call-
        generateParenthesis(n, ans, open + 1, close, pat + "(");
        generateParenthesis(n, ans, open, close + 1, pat + ")");

        return;
    }

public:
    vector<string> generateParenthesis(int n)
    {
        // Base Case--
        if (n == 0)
        {
            return {};
        }

        // Calling Backtracking Function--
        vector<string> ans;
        generateParenthesis(n, ans, 0, 0, "");
        return ans;
    }
};