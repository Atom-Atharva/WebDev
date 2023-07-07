// https://leetcode.com/problems/sqrtx/

// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

// You must not use any built-in exponent function or operator.

// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

#include <iostream>
using namespace std;

// Just Like Binary Search we have discovered the middle most element from (1 to x)
int mySqrt(int x)
{
    int st = 1, en = x;
    int ans = 0;

    while (st <= en)
    {
        long long mid = ((long long)st + en) / 2;
        if (mid * mid <= x)
        {
            ans = mid;
            st = mid + 1;
        }
        else
        {
            en = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int x;
    cin >> x;

    cout << mySqrt(x) << endl;

    return 0;
}