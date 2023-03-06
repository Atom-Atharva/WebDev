// https://leetcode.com/problems/count-and-say/

// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

// countAndSay(1) = "1"
// countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
// To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

// For example, the saying and conversion for digit string "3322251":

// -----------------------------IMG----------------------------------

// Given a positive integer n, return the nth term of the count-and-say sequence.

#include <iostream>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        // Base Case--
        if (n == 1)
        {
            return "1";
        }

        // Reccursive Call--
        string say = countAndSay(n - 1);

        // Generate ans string from say command--
        string ans = "";
        for (int i = 0; i < say.size(); i++)
        {
            char c = say[i];
            int count = 1;
            while (i + 1 < say.size() && say[i + 1] == c)
            {
                count++;
                i++;
            }
            char times = '0' + count;
            ans = ans + times + c;
        }
        return ans;
    }
};