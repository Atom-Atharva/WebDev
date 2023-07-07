// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

class Solution
{
public:
    void sort012(int a[], int n)
    {
        // Count total zeros, ones and twos
        int zeros = 0, ones = 0, twos = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                zeros++;
            }
            else if (a[i] == 1)
            {
                ones++;
            }
            else
            {
                twos++;
            }
        }

        // Place in array--
        for (int i = 0; i < n; i++)
        {
            if (zeros > 0)
            {
                a[i] = 0;
                zeros--;
                continue;
            }
            if (ones > 0)
            {
                a[i] = 1;
                ones--;
                continue;
            }
            if (twos > 0)
            {
                a[i] = 2;
                twos--;
            }
        }

        return;
    }
};