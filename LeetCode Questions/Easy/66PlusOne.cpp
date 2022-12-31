// https://leetcode.com/problems/plus-one/

// You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

// Increment the large integer by one and return the resulting array of digits

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:

    //Optimized Method--
    vector<int> plusOne(vector<int> &digits)
    {
        if (digits[digits.size() - 1] != 9)
        {
            digits[digits.size() - 1]++;
            return digits;
        }

        vector<int> ans;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {

            if (digits[i] == 9 && carry == 1)
            {
                ans.push_back(0);
                carry = 1;
            }
            else
            {
                ans.push_back(carry + digits[i]);
                carry = 0;
            }
        }
        if (carry == 1)
        {
            ans.push_back(1);
        }

        for (int i = 0; i < ans.size() / 2; i++)
        {
            int temp = ans[i];
            ans[i] = ans[ans.size() - 1 - i];
            ans[ans.size() - 1 - i] = temp;
        }
        return ans;
    }
};