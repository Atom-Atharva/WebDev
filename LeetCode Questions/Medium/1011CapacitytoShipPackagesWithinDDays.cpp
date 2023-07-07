// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

// A conveyor belt has packages that must be shipped from one port to another within days days.

// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    bool isPossible(vector<int> &weights, int days, int mid)
    {
        int d = 1;
        int sum = 0;

        for (int i = 0; i < weights.size(); i++)
        {
            sum += weights[i];
            if (sum > mid)
            {
                d++;
                sum = weights[i];
            }
        }
        if (d <= days)
        {
            return true;
        }
        return false;
    }

public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        // High and Low weights that can be shipped--
        int high = 0, low = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            if (weights[i] > low)
            {
                low = weights[i];
            }
            high = high + weights[i];
        }

        int ans = 0;

        // Binary Search for the weight--
        while (low <= high)
        {
            int mid = (high + low) / 2;

            // Check if the mid load is sufficient for the work--
            if (isPossible(weights, days, mid))
            {
                ans = mid;
                high = mid - 1;
            }

            // Else increase the load--
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};