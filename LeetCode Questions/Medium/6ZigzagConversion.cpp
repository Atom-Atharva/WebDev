// https://leetcode.com/problems/zigzag-conversion/

// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }

        string ans = "";
        for (int i = 0; i < numRows; i++)
        {
            int j = i;
            bool even = true;
            while (j < s.length())
            {
                if (i == 0 || i == numRows - 1)
                {
                    ans += s[j];
                    j = j + (numRows - 1) * 2;
                }

                else
                {
                    ans += s[j];
                    if (even)
                    {
                        j = j + (numRows - 1) * 2 - (2 * i);
                        even = false;
                    }
                    else
                    {
                        j = j + 2 * i;
                        even = true;
                    }
                }
            }
        }
        return ans;
    }
};