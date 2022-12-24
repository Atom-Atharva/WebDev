#include <iostream>
#include <cmath>
using namespace std;

// Brute Force--
int balancedBTs(int n)
{
    // Base Case--
    if (n <= 1)
    {
        return 1;
    }

    // *****VIMP*****
    // This is done due to make ans in the range of integer
    int mod = (int)(pow(10, 9)) + 7;

    // Reccursive Call--
    int x = balancedBTs(n - 1);
    int y = balancedBTs(n - 2);

    // Small Calculation--
    long long count1 = ((long long)(x)*x) % mod;
    long long count2 = (2 * (long long)(x)*y) % mod;

    long long ans = (count1 + count2) % mod;
    return ans;
}

// Memoization Approach--
int balancedBTs_helper(int n, int *arr)
{
    if (n <= 1)
    {
        return 1;
    }

    // Check if the solution exist--
    if (arr[n] != -1)
    {
        return arr[n];
    }

    int mod = (int)(pow(10, 9)) + 7;

    int x = balancedBTs_helper(n - 1, arr);
    int y = balancedBTs_helper(n - 2, arr);

    long long count1 = ((long)(x)*x) % mod;
    long long count2 = (2 * (long)(x)*y) % mod;

    long long ans = (count1 + count2) % mod;
    arr[n] = ans;
    return arr[n];
}
int balancedBTs_2(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }
    return balancedBTs_helper(n, arr);
}

// Dynamic programming--
int balancedBTs_3(int n)
{
    int *arr = new int[n + 1];
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int mod = (int)(pow(10, 9)) + 7;
        int x = arr[i - 1];
        int y = arr[i - 2];

        long long temp1 = ((long long)(x)*x) % mod;
        long long temp2 = (2 * (long long)(x)*y) % mod;

        long long ans = (temp1 + temp2) % mod;
        arr[i] = ans;
    }
    return arr[n];
}

int main()
{
    int n;
    cin >> n;

    cout << balancedBTs(n) << endl;
    return 0;
}