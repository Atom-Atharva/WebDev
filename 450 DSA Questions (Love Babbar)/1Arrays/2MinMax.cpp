// https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

// Given an array A of size N of integers. Your task is to find the sum of minimum and maximum element in the array.

#include <iostream>
using namespace std;

class Solution
{
public:
    int findSum(int A[], int N)
    {
        int maxx = A[0], minn = A[0];
        for (int i = 0; i < N; i++)
        {
            maxx = max(maxx, A[i]);
            minn = min(minn, A[i]);
        }
        return maxx + minn;
    }
};