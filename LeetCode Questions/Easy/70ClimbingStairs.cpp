// https://leetcode.com/problems/climbing-stairs/

// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

#include <iostream>
using namespace std;

// Dynamic Programming--
int climbStairs(int n)
{
    if (n == 0)
    {
        return 0;
    }
    
    int *arr = new int[n + 1];
    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}

// // Memoization Approach--
// int climbStairs(int n, int *arr)
// {
//     // Base Case--
//     if (n < 0)
//     {
//         return 0;
//     }
//     if (n == 0)
//     {
//         return 1;
//     }

//     // Check for the solution
//     if (arr[n] != -1)
//     {
//         return arr[n];
//     }

//     // Reccursive Call--
//     int a = climbStairs(n - 1, arr);
//     int b = climbStairs(n - 2, arr);

//     // Store solution for future use--
//     arr[n] = a + b;
//     return arr[n];
// }
// int climbStairs(int n)
// {
//     int *arr = new int[n + 1];
//     for (int i = 0; i <= n; i++)
//     {
//         arr[i] = -1;
//     }
//     return climbStairs(n, arr);
// }

// // Brute Force--
// int climbStairs(int n)
// {
//     // Base Case--
//     if (n < 0)
//     {
//         return 0;
//     }
//     if (n == 0)
//     {
//         return 1;
//     }

//     // Reccursive Call--
//     int a = climbStairs(n - 1);
//     int b = climbStairs(n - 2);

//     // Small Calculation--
//     int sol = a + b;
//     return sol;
// }

int main()
{
    int n;
    cin >> n;

    cout << climbStairs(n) << endl;
    return 0;
}