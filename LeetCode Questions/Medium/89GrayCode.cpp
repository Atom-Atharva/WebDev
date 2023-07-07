// https://leetcode.com/problems/gray-code/description/

// An n-bit gray code sequence is a sequence of 2n integers where:

// Every integer is in the inclusive range [0, 2n - 1],
// The first integer is 0,
// An integer appears no more than once in the sequence,
// The binary representation of every pair of adjacent integers differs by exactly one bit, and
// The binary representation of the first and last integers differs by exactly one bit.

// Given an integer n, return any valid n-bit gray code sequence.

/*****************Important Question**********************/

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> code;
        code.push_back(0);

        // Base Case--
        if (n == 0)
        {
            return code;
        }

        code.push_back(1);
        int curr = 1;

        // For each itteration find out power(2,i)--
        for (int i = 2; i <= n; i++)
        {
            curr *= 2;

            // Add curr to all elements in reverse order--
            for (int j = code.size() - 1; j >= 0; j--)
            {
                code.push_back(curr + code[j]);
            }
        }
        return code;
    }
};
