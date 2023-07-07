// https://leetcode.com/problems/count-and-say/

// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

// countAndSay(1) = "1"
// countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
// To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

// For example, the saying and conversion for digit string "3322251":

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
        string ans = countAndSay(n - 1);

        // Say ans--
        string output = "";
        char curr = ans[0];
        int count = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            if (curr == ans[i])
            {
                count++;
            }
            else
            {
                output += to_string(count) + curr;

                curr = ans[i];
                count = 1;
            }
        }
        output += to_string(count) + curr;

        return output;
    }
};