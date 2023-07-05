// https://practice.geeksforgeeks.org/problems/set-bits0143/1

// Given a positive integer N, print count of set bits in it.

#include <iostream>
using namespace std;

class Solution
{
public:
    int setBits(int N)
    {
        int count = 0;
        while (N > 0)
        {
            if (N % 2 != 0)
            {
                count++;
            }

            N /= 2;
        }

        return count;
    }
};