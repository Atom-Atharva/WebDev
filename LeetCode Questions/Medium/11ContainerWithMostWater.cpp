// https://leetcode.com/problems/container-with-most-water/

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        // Using 2 Pointers--
        int i = 0, j = height.size() - 1;
        int max_ar = 0;
        while (i < j)
        {
            // Taking Out new area of container--
            int area = min(height[i], height[j]) * (j - i);
            if (max_ar < area)
            {
                max_ar = area;
            }

            // Moving Container--
            if (height[i] > height[j])
            {
                j--;
            }
            else if (height[i] == height[j])
            {
                i++;
                j--;
            }
            else
            {
                i++;
            }
        }
        return max_ar;
    }
};