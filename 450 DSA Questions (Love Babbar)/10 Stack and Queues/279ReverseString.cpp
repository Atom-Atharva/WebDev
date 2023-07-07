// https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1

// You are given a string S, the task is to reverse the string using stack.

#include <iostream>
using namespace std;
#include <stack>

class Solution
{
public:
    char *reverse(char *S, int len)
    {
        stack<char> store;

        // Push elements into the Stack--
        for (int i = 0; i < len; i++)
        {
            store.push(S[i]);
        }

        // Pop elements into the Stack--
        for (int i = 0; i < len; i++)
        {
            S[i] = store.top();
            store.pop();
        }

        return S;
    }
};