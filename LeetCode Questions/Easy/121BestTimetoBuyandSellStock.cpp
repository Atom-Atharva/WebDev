// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int least = INT_MAX;
        int mdif = 0;
        int tpr = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < least)
            {
                least = prices[i];
            }

            tpr = prices[i] - least;
            if (mdif < tpr)
            {
                mdif = tpr;
            }
        }
        return mdif;
    }
};