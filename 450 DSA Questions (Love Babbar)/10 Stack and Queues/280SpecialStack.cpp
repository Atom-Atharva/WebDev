// https://practice.geeksforgeeks.org/problems/special-stack/1

// Design a data-structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. Your task is to complete all the functions, using stack data-Structure.

#include <iostream>
using namespace std;
#include <stack>
#include <climits>

class Solution
{
public:
    void push(stack<int> &s, int a)
    {
        s.push(a);
    }

    bool isFull(stack<int> &s, int n)
    {
        return (s.size() == n);
    }

    bool isEmpty(stack<int> &s)
    {
        return s.empty();
    }

    int pop(stack<int> &s)
    {
        int temp = s.top();
        s.pop();
        return temp;
    }

    int getMin(stack<int> &s)
    {
        stack<int> temp;

        // Find Minimum from the stack--
        int mn = INT_MAX;
        while (!s.empty())
        {
            temp.push(s.top());
            mn = min(mn, s.top());
            s.pop();
        }

        // Again push to original stack--
        while (!temp.empty())
        {
            s.push(temp.top());
            temp.pop();
        }

        return mn;
    }
};