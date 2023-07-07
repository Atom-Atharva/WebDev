// https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1

// You are given two numbers A and B. The task is to count the number of bits needed to be flipped to convert A to B.

#include <iostream>
using namespace std;

// Method 2: XOR
class Solution
{
public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b)
    {
        // Calculate XOR of a,b
        int XOR = a ^ b;

        // Calculate Set bits in both OR and AND
        int setbits = 0;
        while (XOR > 0)
        {
            setbits += XOR & 1;
            XOR = XOR >> 1;
        }

        return setbits;
    }
};

// Method 1: OR and AND
class Solution
{
public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b)
    {
        // Calculate OR and AND of a,b
        int OR = a | b;
        int AND = a & b;

        // Calculate Set bits in both OR and AND
        int setInOR = 0;
        while (OR > 0)
        {
            setInOR += OR & 1;
            OR = OR >> 1;
        }
        int setInAND = 0;
        while (AND > 0)
        {
            setInAND += AND & 1;
            AND = AND >> 1;
        }

        return setInOR - setInAND;
    }
};