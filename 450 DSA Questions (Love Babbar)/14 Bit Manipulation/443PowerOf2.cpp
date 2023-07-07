// https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1

// Given a non-negative integer N. The task is to check if N is a power of 2. More formally, check if N can be expressed as 2x for some x.

#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n)
    {
        // Count Set Bits in number--
        long long countSetBits = 0;
        while (n > 0)
        {
            countSetBits += n & 1;
            n = n >> 1;
        }

        // Set Bits should be 1
        return countSetBits == 1;
    }
};