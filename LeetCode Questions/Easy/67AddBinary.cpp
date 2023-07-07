// https://leetcode.com/problems/add-binary/

// Given two binary strings a and b, return their sum as a binary string.

#include <iostream>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int carry = 0;
        string ans = "";

        int i, j;

        // Adding in both bit strings
        for (i = a.length() - 1, j = b.length() - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (carry == 1)
            {
                if (a[i] == '1' && b[j] == '1')
                {
                    ans += '1';
                    carry = 1;
                }
                else if (a[i] == '1' || b[j] == '1')
                {
                    ans += '0';
                    carry = 1;
                }
                else
                {
                    ans += '1';
                    carry = 0;
                }
            }
            else
            {
                if (a[i] == '1' && b[j] == '1')
                {
                    ans += '0';
                    carry = 1;
                }
                else if (a[i] == '1' || b[j] == '1')
                {
                    ans += '1';
                    carry = 0;
                }
                else
                {
                    ans += '0';
                    carry = 0;
                }
            }
        }

        // Adding in the long bit string
        while (i >= 0)
        {
            if (carry == 1)
            {
                if (a[i] == '1')
                {
                    ans += '0';
                    carry = 1;
                }
                else
                {
                    ans += '1';
                    carry = 0;
                }
            }
            else
            {
                if (a[i] == '1')
                {
                    ans += '1';
                    carry = 0;
                }
                else
                {
                    ans += '0';
                    carry = 0;
                }
            }
            i--;
        }
        while (j >= 0)
        {
            if (carry == 1)
            {
                if (b[j] == '1')
                {
                    ans += '0';
                    carry = 1;
                }
                else
                {
                    ans += '1';
                    carry = 0;
                }
            }
            else
            {
                if (b[j] == '1')
                {
                    ans += '1';
                    carry = 0;
                }
                else
                {
                    ans += '0';
                    carry = 0;
                }
            }
            j--;
        }

        // Check for remaining carry--
        if (carry == 1)
        {
            ans += '1';
        }

        // Reversing the ans string--
        for (int i = 0; i < ans.size() / 2; i++)
        {
            int temp = ans[i];
            ans[i] = ans[ans.size() - 1 - i];
            ans[ans.size() - 1 - i] = temp;
        }
        return ans;
    }
};