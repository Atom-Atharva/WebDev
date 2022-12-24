#include <iostream>
using namespace std;

// Brute Force Approach--
int minSteps(int n)
{
    // Base Case--
    if (n == 1)
    {
        return 0;
    }

    // Reccursive Call--
    int steps1 = minSteps(n - 1) + 1;
    int steps2 = 999;
    int steps3 = 999;
    if (n % 2 == 0)
    {
        steps2 = minSteps(n / 2) + 1;
    }
    if (n % 3 == 0)
    {
        steps3 = minSteps(n / 3) + 1;
    }

    int minStepsto1 = min(steps1, min(steps2, steps3));
    return minStepsto1;
}

// Memoization Approach--
// To check if we can use Memoization Approach by checking overlapping processes--
int minSteps_helper(int n, int *arr)
{
    if (n == 1)
    {
        return 0;
    }

    // Check if Solution exist--
    if (arr[n - 1] != -1)
    {
        return arr[n - 1];
    }

    int a = minSteps_helper(n - 1, arr);
    int b = 999, c = 999;
    if (n % 2 == 0)
    {
        b = minSteps_helper(n / 2, arr);
    }
    if (n % 3 == 0)
    {
        c = minSteps_helper(n / 3, arr);
    }
    int minsteps = min(a, min(b, c)) + 1;

    // Saving Result for future use--
    arr[n - 1] = minsteps;
    return arr[n - 1];
}

int minSteps_2(int n)
{
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = -1;
    }
    return minSteps_helper(n, arr);
}

// Dynamic Approach--
int minSteps_3(int n)
{
    int *arr = new int[n];
    arr[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int a = arr[i - 1];
        int b = 999, c = 999;
        if ((i + 1) % 2 == 0)
        {
            b = arr[((i + 1) / 2) - 1];
        }
        if ((i + 1) % 3 == 0)
        {
            c = arr[((i + 1) / 3) - 1];
        }

        arr[i] = min(a, min(b, c)) + 1;
    }
    return arr[n - 1];
}

int main()
{
    int n;
    cin >> n;

    int ans = minSteps_3(n);
    cout << ans << endl;
    return 0;
}