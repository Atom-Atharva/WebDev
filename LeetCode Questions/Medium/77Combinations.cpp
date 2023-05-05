// https://leetcode.com/problems/combinations/

// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

// You may return the answer in any order.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    void combinations(int n, int k, vector<vector<int>> &ans, vector<int> &comb, int i)
    {
        // Base Case--
        if (comb.size() == k)
        {
            ans.push_back(comb);
            return;
        }

        for (; i <= n; i++)
        {
            // Add to combination--
            comb.push_back(i);

            // Reccursion on Combination--
            combinations(n, k, ans, comb, i + 1);

            // Remove from Combination--
            comb.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> comb;
        combinations(n, k, ans, comb, 1);
        return ans;
    }
};