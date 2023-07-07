// https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

// You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

//********************** IMPORTANT QUESTION *******************************//

#include <iostream>
using namespace std;

class Solution
{
    int highestPowerOf2(int n)
    {
        int power = 0;
        while ((1 << power) <= n)
        {
            power++;
        }

        return power - 1;
    }

public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Base Case--
        if (n == 0)
        {
            return 0;
        }

        // Find highest power of 2 possible--
        int x = highestPowerOf2(n);

        // Count Bits in the Set--
        int count = ((1 << x - 1) * x) + (n - (1 << x) + 1);

        // Call Recursion--
        return count + countSetBits(n - (1 << x));
    }
};