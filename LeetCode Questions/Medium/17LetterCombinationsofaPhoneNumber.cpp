// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

#include <iostream>
using namespace std;
#include <vector>

// Optimized Solution Using Reccursion--
class Solution
{
    string getLetters(char digit)
    {
        vector<string> comb = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        return comb[(digit - '0')];
    }

    void createComb(string digits, vector<string> &ans, string comb)
    {
        // Base Case--
        if (digits.size() == 0)
        {
            ans.push_back(comb);
            return;
        }

        // Reccursive Call and Small Calculation--
        string insert = getLetters(digits[0]);
        for (int i = 0; i < insert.size(); i++)
        {
            createComb(digits.substr(1), ans, comb + insert[i]);
        }
        return;
    }

public:
    // Using Reccursion--
    // Time Complexity: O(n*4^n)
    vector<string> letterCombinations(string digits)
    {
        // Base Case--
        if (digits.length() == 0)
        {
            return {};
        }
        vector<string> ans;
        createComb(digits, ans, "");
        return ans;
    }
};

// Brute Force Approach O(n3)--
// class Solution
// {
//     string getLetters(char digit)
//     {
//         if (digit == '2')
//         {
//             return "abc";
//         }
//         else if (digit == '3')
//         {
//             return "def";
//         }
//         else if (digit == '4')
//         {
//             return "ghi";
//         }
//         else if (digit == '5')
//         {
//             return "jkl";
//         }
//         else if (digit == '6')
//         {
//             return "mno";
//         }
//         else if (digit == '7')
//         {
//             return "pqrs";
//         }
//         else if (digit == '8')
//         {
//             return "tuv";
//         }
//         else if (digit == '9')
//         {
//             return "wxyz";
//         }
//         return "";
//     }

// public:
//     vector<string> letterCombinations(string digits)
//     {
//         vector<string> ans;
//         ans.push_back("");

//         for (int i = 0; i < digits.length(); i++)
//         {
//             string insert = getLetters(digits[i]);
//             for (int j = 0; j < ans.size(); j++)
//             {
//                 string add = ans[j];
//                 for (int k = 0; k < insert.size(); k++)
//                 {
//                     if (k == 0)
//                     {
//                         ans[j] = ans[j] + insert[k];
//                         continue;
//                     }
//                     ans.push_back(add + insert[k]);
//                 }
//             }
//         }
//         return ans;
//     }
// };