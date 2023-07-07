// https://leetcode.com/problems/minimum-cost-for-tickets/

// You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

// Train tickets are sold in three different ways:

//      a 1-day pass is sold for costs[0] dollars,
//      a 7-day pass is sold for costs[1] dollars, and
//      a 30-day pass is sold for costs[2] dollars.
//      The passes allow that many days of consecutive travel.

// For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
// Return the minimum number of dollars you need to travel every day in the given list of days.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    // Dynamic Programming--
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int *arr = new int[days.size()];
        // fill first cell--
        arr[0] = min(costs[0], min(costs[1], costs[2]));

        // Fill remaining cells--
        for (int i = 1; i < days.size(); i++)
        {
            // Moving to last7 and last 30 days--
            int last7 = i, last30 = i;
            while (last7 >= 0 && days[last7] + 7 > days[i])
            {
                last7--;
            }
            while (last30 >= 0 && days[last30] + 30 > days[i])
            {
                last30--;
            }

            // Adding Costs of 1Day Ticket--
            arr[i] = costs[0] + arr[i - 1];

            // Adding Costs of 7Day Tickets--
            if (last7 != -1)
            {
                arr[i] = min(arr[i], arr[last7] + costs[1]);
            }
            else
            {
                arr[i] = min(arr[i], costs[1]);
            }

            // Adding Costs of 30Days Tickets--
            if (last30 != -1)
            {
                arr[i] = min(arr[i], arr[last30] + costs[2]);
            }
            else
            {
                arr[i] = min(arr[i], costs[2]);
            }
        }

        return arr[days.size() - 1];
    }

    //     // Reccursion--
    //     int mincostTickets(vector<int> &days, vector<int> &costs, int st)
    //     {
    //         // Base Case--
    //         if (st >= days.size())
    //         {
    //             return 0;
    //         }

    //         // Reccursive Call--
    //         int path1 = costs[0] + mincostTickets(days, costs, st + 1);

    //         int day = st;
    //         while (day < days.size())
    //         {
    //             if (days[day] >= days[st] + 7)
    //             {
    //                 break;
    //             }
    //             day++;
    //         }
    //         int path2 = costs[1] + mincostTickets(days, costs, day);

    //         day = st;
    //         while (day < days.size())
    //         {
    //             if (days[day] >= days[st] + 30)
    //             {

    //                 break;
    //             }
    //             day++;
    //         }
    //         int path3 = costs[2] + mincostTickets(days, costs, day);

    //         // Small Calculation--
    //         return min(path1, min(path2, path3));
    //     }

    // public:
    //     int mincostTickets(vector<int> &days, vector<int> &costs)
    //     {
    //         return mincostTickets(days, costs, 0);
    //     }
};