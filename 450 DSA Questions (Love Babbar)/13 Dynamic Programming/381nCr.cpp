// https://practice.geeksforgeeks.org/problems/ncr1019/1

// Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.

#include <iostream>
using namespace std;

#define M 1000000007

// Method 3: Dynamic Programming--
class Solution
{
public:
    int nCr(int n, int r)
    {
        // Base Case--
        if (r > n)
        {
            return 0;
        }

        // Dynamic Array--
        int **arr = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            arr[i] = new int[r + 1];
        }

        // Fill First Cell--
        arr[0][0] = 0;

        // Fill First Row--
        for (int i = 1; i <= r; i++)
        {
            arr[0][i] = 0;
        }

        // Fill First Column--
        for (int i = 1; i <= n; i++)
        {
            arr[i][0] = 1;
        }

        // Fill Remaining Cells--
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= r; j++)
            {
                arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]) % M;
            }
        }

        return arr[n][r];
    }
};

// Method 2: Memomization--
class Solution
{
    int nCr(int n, int r, int **arr)
    {
        // Base Case--
        if (r > n)
        {
            return 0;
        }
        if (r == 0 || r == n)
        {
            return 1;
        }
        if (arr[n - 1][r - 1] != -1)
        {
            return arr[n - 1][r - 1];
        }

        // Recursive Calls--
        return arr[n - 1][r - 1] = (nCr(n - 1, r - 1, arr) % M + nCr(n - 1, r, arr) % M) % M;
    }

public:
    int nCr(int n, int r)
    {
        int **arr = new int *[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[r];
            for (int j = 0; j < r; j++)
            {
                arr[i][j] = -1;
            }
        }

        return nCr(n, r, arr);
    }
};

// Method 1: Recursion--
// TLE
class Solution
{
public:
    int nCr(int n, int r)
    {
        // Base Case--
        if (r > n)
        {
            return 0;
        }
        if (r == 0 || r == n)
        {
            return 1;
        }

        // Recursive Calls--
        return (nCr(n - 1, r - 1) % M + nCr(n - 1, r) % M) % M;
    }
};

// // Wrong Answer Always Need Changes Like ((n!/r!)/(n-r)!)--
// // Cant Handle very Large Cases, where multiplication exceeded long long range--
// // Method 2: Memomisation
// class Memoisation
// {
//     int factorial(int n, int *arr)
//     {
//         // Base Case--
//         if (n <= 1)
//         {
//             return 1;
//         }

//         // Check if Exist--
//         if (arr[n - 1] != -1)
//         {
//             return arr[n - 1];
//         }

//         // Recursive Calls--
//         int fact = factorial(n - 1, arr);

//         // Calculation--
//         return arr[n - 1] = (fact * n) % M;
//     }

// public:
//     int nCr(int n, int r)
//     {
//         // Base Case--
//         if (r > n)
//         {
//             return 0;
//         }

//         // Memomisation Table--
//         int *arr = new int[n];
//         for (int i = 0; i < n; i++)
//         {
//             arr[i] = -1;
//         }

//         // Factorials--
//         int fact_n = factorial(n, arr);
//         int fact_r = factorial(r, arr);
//         int fact_nr = factorial(n - r, arr);

//         // Calculation--
//         cout << fact_n << " ";
//         cout << fact_r << " ";
//         cout << fact_nr << " ";
//         return fact_n / ((fact_r * fact_nr) % M);
//     }
// };

// // Method 1: Recursion--
// class Recursion
// {
//     int factorial(int n)
//     {
//         // Base Case--
//         if (n <= 1)
//         {
//             return 1;
//         }

//         // Recursive Calls--
//         int fact = factorial(n - 1);

//         // Calculation--
//         return (fact * n) % M;
//     }

// public:
//     int nCr(int n, int r)
//     {
//         // Base Case--
//         if (r > n)
//         {
//             return 0;
//         }

//         // Factorials--
//         int fact_n = factorial(n);
//         int fact_r = factorial(r);
//         int fact_nr = factorial(n - r);

//         // Calculation--
//         return fact_n / ((fact_r * fact_nr) % M);
//     }
// };