// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

// Given an array of N integers arr[] where each element represents the maximum length of the jump that can be made forward from that element. This means if arr[i] = x, then we can jump any distance y such that y ≤ x.
// Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.

// Note: Return -1 if you can't reach the end of the array.

/*****************IMPORTANT QUESTION***********************/

#include <iostream>
using namespace std;

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        // Base Case--
        if (n == 1)
        {
            return 0;
        }

        // Variables-
        int step = arr[0];  // Steps can be taken
        int jump = 0;       // Jumps till now
        int range = arr[0]; // Range maximum can be reached
        for (int i = 0; i < n - 1; i++)
        {
            // Update range to maximum--
            range = max(range, i + arr[i]);

            // If no more steps is allowed then jump
            if (step == 0)
            {
                jump++;
                step = range - i;
            }

            // Step decreased
            step--;

            // Base Case when stuck
            if (range == i)
            {
                return -1;
            }
        }

        //+1 for the last jump;
        return jump + 1;
    }
};