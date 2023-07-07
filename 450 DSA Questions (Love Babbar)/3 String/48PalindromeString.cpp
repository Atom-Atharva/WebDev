// https://practice.geeksforgeeks.org/problems/palindrome-string0817/1

// Given a string S, check if it is palindrome or not.

#include <iostream>
using namespace std;

class Solution
{
public:
    int isPalindrome(string S)
    {
        for (int i = 0; i < S.length() / 2; i++)
        {
            if (S[i] != S[S.length() - 1 - i])
            {
                return 0;
            }
        }
        return 1;
    }
};