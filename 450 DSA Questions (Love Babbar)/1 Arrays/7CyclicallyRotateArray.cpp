// https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1

// Given an array, rotate the array by one position in clock-wise direction.

#include <iostream>
using namespace std;

class Solution
{
public:
    void rotate(int arr[], int n)
    {
        int temp = arr[n - 1];
        for (int i = n - 1; i >= 1; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;

        return;
    }
};