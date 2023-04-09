// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

// You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

// You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

// Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
    int searchLeast(int element, vector<int> &potions, long long success)
    {
        int st = 0;
        int en = potions.size() - 1;

        int mid;
        long long strength;
        while (st <= en)
        {
            mid = (st + en) / 2;

            strength = (long long)potions[mid] * element;

            if (strength < success)
            {
                st = mid + 1;
            }
            else
            {
                en = mid - 1;
            }
        }
        return st;
    }

public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());

        vector<int> ans;
        for (int i = 0; i < spells.size(); i++)
        {
            int least_index = searchLeast(spells[i], potions, success);

            // Add to ans vector--
            ans.push_back(potions.size() - least_index);
        }
        return ans;
    }
};
