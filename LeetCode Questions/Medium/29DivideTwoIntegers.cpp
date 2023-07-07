// https://leetcode.com/problems/divide-two-integers/

// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

// The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

// Return the quotient after dividing dividend by divisor.

// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.\

#include <iostream>
using namespace std;
#include <climits>

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;

        // 1. While we can subtract divisor from the divident--
        //      ->IF YES, then we double the divisor.
        //      ->Increment the counter.
        //      ->Check Again.
        // 2. Add Count into result.
        // 3. Subtract the temp variable from divident.
        while (dvd >= dvs)
        {
            long temp = dvs, m = 1;
            while (temp << 1 <= dvd)
            {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign * ans;
    }
};