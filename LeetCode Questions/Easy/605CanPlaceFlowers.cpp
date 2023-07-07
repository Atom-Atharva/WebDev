// https://leetcode.com/problems/can-place-flowers/

// You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

// Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {

        for (int i = 0; i < flowerbed.size() && n > 0; i++)
        {
            if (flowerbed[i] == 1)
            {
                continue;
            }

            bool left = true;
            if (i - 1 >= 0)
            {
                if (flowerbed[i - 1] == 1)
                {
                    left = false;
                }
            }

            bool right = true;
            if (i + 1 <= flowerbed.size() - 1)
            {
                if (flowerbed[i + 1] == 1)
                {
                    right = false;
                }
            }

            if (left && right)
            {
                flowerbed[i] = 1;
                n--;
            }

        }
        if (n == 0)
        {
            return true;
        }
        return false;
    }
};