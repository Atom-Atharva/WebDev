// https://practice.geeksforgeeks.org/problems/middle-of-three2926/1

// Given three distinct numbers A, B and C. Find the number with value in middle (Try to do it with minimum comparisons).

#include <iostream>
using namespace std;

class Solution
{
public:
    // Maximum 2 Comparisons--
    int middle(int A, int B, int C)
    {
        int mid = (A + B) / 2;

        // If C is either smallest or in between-
        if (mid > C)
        {
            // If C is in Between--
            if (C > min(A, B))
            {
                return C;
            }
            else
            {
                return min(A, B);
            }
        }

        // If is either largest or in between-
        else
        {
            // If C is in between--
            if (C < max(A, B))
            {
                return C;
            }
            else
            {
                return max(A, B);
            }
        }
    }
};