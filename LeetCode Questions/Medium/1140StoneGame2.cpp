// https://leetcode.com/problems/stone-game-ii/

// Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones.

// Alice and Bob take turns, with Alice starting first.  Initially, M = 1.

// On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).

// The game continues until all the stones have been taken.

// Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

/********************Important Question*************************/

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

// Method 2: Memomization Approach
class Solution
{
    int stoneGame(vector<int> &piles, int st, int m, vector<vector<int>> &dp)
    {
        // Base Case--
        if (st >= piles.size())
        {
            return 0;
        }
        if (dp[st][m] != -1)
        {
            return dp[st][m];
        }

        // Pick Stones--
        int stones = 0;
        int ans = INT_MIN;

        // Maximum stones, one can pick up--
        for (int i = 0; i < 2 * m; i++)
        {
            if (st + i < piles.size())
            {
                stones += piles[st + i];
            }
            ans = max(ans, stones - stoneGame(piles, st + i + 1, max(m, i+1), dp));
        }
        return dp[st][m] = ans;
    }

public:
    int stoneGameII(vector<int> &piles)
    {
        int sum = 0;
        for (auto i : piles)
        {
            sum += i;
        }

        vector<vector<int>> dp(piles.size() + 1, vector<int>(2 * piles.size() + 1));
        for (int i = 0; i < piles.size() + 1; i++)
        {
            for (int j = 0; j < 2 * piles.size() + 1; j++)
            {
                dp[i][j] = -1;
            }
        }

        // We have difference of stones.
        int diff = stoneGame(piles, 0, 1, dp);

        return (sum + diff) / 2;
    }
};

// Method 1: Reccursion
// Time Limit Exceeded--
// class Solution
// {

//     int stoneGameII(vector<int> &piles, int st, int m)
//     {
//         // Base Case--
//         if (st >= piles.size())
//         {
//             return 0;
//         }

//         // Pick Stones--
//         int stones = 0;
//         int ans = INT_MIN;

//         // Maximum stones, one can pick up--
//         for (int i = 0; i < 2 * m; i++)
//         {
//             if (st + i < piles.size())
//             {
//                 stones += piles[st + i];
//             }
//             ans = max(ans, stones - stoneGameII(piles, st + i + 1, max(m, 2 * i)));
//         }
//         return ans;
//     }

// public:
//     int stoneGameII(vector<int> &piles)
//     {
//         int sum = 0;
//         for (auto i : piles)
//         {
//             sum += i;
//         }

//          // We have difference of stones.
//         int diff = stoneGameII(piles, 0, 1);

//         return (sum + diff) / 2;
//     }
// };