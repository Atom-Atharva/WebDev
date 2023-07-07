// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

// A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
// Note: Follow 0 based indexing.
// Follow Up: Can you optimize it to O(N)

#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    // Method-2: Stacks--
    // Time Complexity: O(n).
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }

        while (s.size() > 1)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            // Down Sizing the stack--
            // If a knows b then b is famous--
            if (M[a][b] == 1)
            {
                s.push(b);
            }

            // Else a is famous--
            else
            {
                s.push(a);
            }
        }

        // Potential Candidate--
        int ans = s.top();

        // Check Column--
        for (int i = 0; i < n; i++)
        {
            if (M[i][ans] != 1 && ans != i)
            {
                return -1;
            }
        }

        // Check Row--
        for (int i = 0; i < n; i++)
        {
            if (M[ans][i] != 0)
            {
                return -1;
            }
        }

        return ans;
    }

    // Function to find if there is a celebrity in the party or not.
    // Method-1: Matrix--
    // Time Complexity: O(n^2).
    int celebrity(vector<vector<int>> &M, int n)
    {
        for (int i = 0; i < n; i++)
        {
            int j;
            for (j = 0; j < n; j++)
            {
                if (M[i][j] != 0)
                {
                    break;
                }
            }
            if (j == n)
            {
                int k;
                for (k = 0; k < n; k++)
                {
                    if (k == i)
                    {
                        continue;
                    }
                    if (M[k][i] == 0)
                    {
                        break;
                    }
                }
                if (k == n)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};