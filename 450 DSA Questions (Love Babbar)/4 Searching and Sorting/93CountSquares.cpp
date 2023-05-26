// https://practice.geeksforgeeks.org/problems/count-squares3649/1

// Consider a sample space S consisting of all perfect squares starting from 1, 4, 9 and so on. You are given a number N, you have to output the number of integers less than N in the sample space S.

#include <iostream>
using namespace std;

class Solution
{
public:
    int countSquares(int N)
    {
        int st = 0, en = N - 1;
        while (st <= en)
        {
            int mid = (st + en) / 2;

            if ((long long)mid * mid > N - 1)
            {
                en = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        return en;
    }
};