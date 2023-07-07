// https://leetcode.com/problems/fair-distribution-of-cookies/

// You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are also given an integer k that denotes the number of children to distribute all the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.

// The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.

// Return the minimum unfairness of all distributions.

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

class Solution
{
    void distribute(vector<int> &cookies, int k, vector<int> &children, int st, int &unfairness)
    {
        // Base Case--
        if (st == cookies.size())
        {
            int currUnfair = INT_MIN;
            for (int i = 0; i < k; i++)
            {
                currUnfair = max(children[i], currUnfair);
            }

            unfairness = min(unfairness, currUnfair);
            return;
        }

        // Distribute Cookies to Children--
        for (int i = 0; i < k; i++)
        {
            // Using Backtracking--

            // Give--
            children[i] += cookies[st];

            // Call--
            distribute(cookies, k, children, st + 1, unfairness);

            // Take--
            children[i] -= cookies[st];
        }
        return;
    }

public:
    int distributeCookies(vector<int> &cookies, int k)
    {
        // Childrens--
        vector<int> children(k, 0);

        int unfairness = INT_MAX;

        // Distribute Cookies--
        distribute(cookies, k, children, 0, unfairness);

        return unfairness;
    }
};