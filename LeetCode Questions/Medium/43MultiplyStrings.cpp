// https://leetcode.com/problems/multiply-strings/

// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

// Constraints:

// 1 <= num1.length, num2.length <= 200
// num1 and num2 consist of digits only.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.

#include <iostream>
using namespace std;

class Solution
{
    int sti(char num)
    {
        return (num - '0');
    }

    char itc(int num)
    {
        return ('0' + num);
    }

public:
    string multiply(string num1, string num2)
    {
        // Defining Variables--
        int size = num1.length() + num2.length();
        int ans[size];

        // Initialize array with 0.
        for (int i = 0; i < size; i++)
        {
            ans[i] = 0;
        }

        int jval = num1.size() - 1;
        int ival = num2.size() - 1;

        // Multiplication Process--
        while (ival >= 0)
        {
            int carry = 0;

            // k = starting point - powerfactor
            int k = (size - 1) - ((num2.size() - 1) - ival);

            // Reset jval--
            jval = num1.size() - 1;

            // Multiplication--
            while (jval >= 0)
            {
                int product = (sti(num1[jval]) * sti(num2[ival]));
                ans[k] = product + carry + ans[k];
                carry = ans[k] / 10;
                ans[k] = ans[k] % 10;

                jval--;
                k--;
            }

            // Handling Last Carry--
            if (jval == -1 && carry != 0)
            {
                ans[k] = carry;
            }
            ival--;
        }

        string res = "";
        bool initial = true;
        for (int i = 0; i < size; i++)
        {
            if (initial && ans[i] == 0)
            {
                continue;
            }
            initial = false;
            res = res + itc(ans[i]);
        }

        return (res == "") ? "0" : res;
    }

    // Method is inefficient for num.lenght() > long long

    //     long long int strToInt(string num)
    //     {
    //         long long int ans = 0;
    //         for (int i = 0; i < num.size(); i++)
    //         {
    //             ans = ans * 10 + (num[i] - '0');
    //         }
    //         return ans;
    //     }

    //     string intToStr(long long int num)
    //     {
    //         string ans = "";
    //         while (num != 0)
    //         {
    //             int r = num % 10;
    //             ans = (char)('0' + r) + ans;
    //             num = num / 10;
    //         }
    //         return (ans == "") ? "0" : ans;
    //     }

    // public:
    //     string multiply(string num1, string num2)
    //     {
    //         long long int n1 = strToInt(num1);
    //         long long int n2 = strToInt(num2);

    //         long long int ans = n1 * n2;
    //         return intToStr(ans);
    //     }
};