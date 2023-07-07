// https://leetcode.com/problems/reducing-dishes/

// A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

// Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

// Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.

// Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    // Prefix Sum + Sorting--
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());

        vector<int> sum = satisfaction;
        for (int i = 1; i < satisfaction.size(); i++)
        {
            sum[i] += sum[i - 1];
        }

        int curr = 0, mx = 0;
        for (int i = 0; i < satisfaction.size(); i++)
        {
            curr = curr + sum[i];
            mx = max(mx, curr);
        }
        return mx;
    }

    //     // Reccursion--
    //     int maxSatisfaction(vector<int> &satisfaction, int st, int i)
    //     {
    //         // Base Case--
    //         if (st >= satisfaction.size())
    //         {
    //             return 0;
    //         }

    //         // Reccursion--
    //         // Take--
    //         int take = (satisfaction[st] * i) + maxSatisfaction(satisfaction, st + 1, i + 1);

    //         // Leave--
    //         int leave = maxSatisfaction(satisfaction, st + 1, i);

    //         return max(take, leave);
    //     }

    // public:
    //     int maxSatisfaction(vector<int> &satisfaction)
    //     {
    //         sort(satisfaction.begin(), satisfaction.end());
    //         return maxSatisfaction(satisfaction, 0, 1);
    //     }
};