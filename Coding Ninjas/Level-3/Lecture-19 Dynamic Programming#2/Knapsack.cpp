#include <iostream>
using namespace std;

// Dynamic Programming--
int knapsack_3(int *weights, int *values, int n, int maxweights)
{
    int **arr = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = new int[maxweights + 1];
    }

    // Filling the first cell (0,0)--
    arr[0][0] = 0;

    // Filling the top row--
    for (int j = 1; j <= maxweights; j++)
    {
        arr[0][j] = 0;
    }

    // Filling the first coloumn--
    for (int i = 1; i <= n; i++)
    {
        arr[i][0] = 0;
    }

    // Filling rest of the cells--
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxweights; j++)
        {
            if (weights[i - 1] <= j)
            {
                int a = values[i - 1] + arr[i - 1][j - weights[i - 1]];
                int b = arr[i - 1][j];
                arr[i][j] = max(a, b);
            }
            else
            {
                arr[i][j] = arr[i - 1][j];
            }
        }
    }
    return arr[n][maxweights];
}

// Memoization Approach--
int knapsack_2(int *weights, int *values, int n, int maxweight, int **arr)
{
    // Base Case--
    if (maxweight == 0 || n == 0)
    {
        return 0;
    }
    // Check if the solution exist--
    if (arr[n][maxweight] != -1)
    {
        return arr[n][maxweight];
    }

    if (maxweight < weights[0])
    {
        return knapsack_2(weights + 1, values + 1, n - 1, maxweight, arr);
    }

    // Reccursive Calls--
    int a = values[0] + knapsack_2(weights + 1, values + 1, n - 1, maxweight - weights[0], arr);
    int b = knapsack_2(weights + 1, values + 1, n - 1, maxweight, arr);

    // Small Calculation & Saving for future use--
    arr[n][maxweight] = max(a, b);
    return arr[n][maxweight];
}
int knapsack_2(int *weights, int *values, int n, int maxweight)
{
    // Memory Array--
    int **arr = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = new int[maxweight + 1];
        for (int j = 0; j <= maxweight; j++)
        {
            arr[i][j] = -1;
        }
    }

    return knapsack_2(weights, values, n, maxweight, arr);
}

// Brute Force--
int knapsack(int *weights, int *values, int n, int maxweight)
{
    // Base Case--
    if (maxweight == 0 || n == 0)
    {
        return 0;
    }
    if (maxweight < weights[0])
    {
        return knapsack(weights + 1, values + 1, n - 1, maxweight);
    }

    // Reccursive Calls--
    int a = values[0] + knapsack(weights + 1, values + 1, n - 1, maxweight - weights[0]);
    int b = knapsack(weights + 1, values + 1, n - 1, maxweight);

    // Small Calculation--
    return max(a, b);
}

int main()
{
    int *weights;
    int *values;
    int n;
    cin >> n;

    weights = new int[n];
    values = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int maxweight;
    cin >> maxweight;

    cout << knapsack(weights, values, n, maxweight) << endl;
    cout << knapsack_2(weights, values, n, maxweight) << endl;
    cout << knapsack_3(weights, values, n, maxweight) << endl;

    return 0;
}