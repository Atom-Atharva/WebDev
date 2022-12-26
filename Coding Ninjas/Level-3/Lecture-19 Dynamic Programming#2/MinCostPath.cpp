#include <iostream>
using namespace std;

// Brute Force Method--
int minCostPathHelper(int **arr, int m, int n, int i, int j)
{
    // Base Case--
    if (i == m - 1 && j == n - 1)
    {
        return arr[i][j];
    }
    if (i == m || j == n)
    {
        return 10000;
    }

    // Reccursive Call--
    int a = minCostPathHelper(arr, m, n, i + 1, j);
    int b = minCostPathHelper(arr, m, n, i, j + 1);
    int c = minCostPathHelper(arr, m, n, i + 1, j + 1);

    // Small Calculation--
    return arr[i][j] + min(a, min(b, c));
}
int minCostPath(int **arr, int m, int n)
{
    return minCostPathHelper(arr, m, n, 0, 0);
}

// Memoization Method--
int minCostPath_2(int **arr, int m, int n, int i, int j, int **path)
{
    // Base Case
    if (i == m - 1 && j == n - 1)
    {
        return arr[i][j];
    }
    if (i == m || j == n)
    {
        return 1000;
    }

    // Check if the solution exist--
    if (path[i][j] != -1)
    {
        return path[i][j];
    }

    // Reccursive Calls--
    int a = minCostPath_2(arr, m, n, i, j + 1, path);
    int b = minCostPath_2(arr, m, n, i + 1, j, path);
    int c = minCostPath_2(arr, m, n, i + 1, j + 1, path);

    path[i][j] = min(a, min(b, c)) + arr[i][j];
    return path[i][j];
}
int minCostPath_2(int **arr, int m, int n)
{
    int **path = new int *[m];
    for (int i = 0; i < m; i++)
    {
        path[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            path[i][j] = -1;
        }
    }
    return minCostPath_2(arr, m, n, 0, 0, path);
}

// Dynamic Programming--
// Time Complexity--O(m*n)
// This approach is better than memoization becoz isme call stack nahi banana padta :)
int minCostPath_3(int **arr, int m, int n)
{
    int **path = new int *[m];
    for (int i = 0; i < m; i++)
    {
        path[i] = new int[n];
    }

    // Fill Destination--
    path[m - 1][n - 1] = arr[m - 1][n - 1];

    // Fill Last Row (right to left)--
    for (int i = n - 2; i >= 0; i--)
    {
        path[m - 1][i] = path[m - 1][i + 1] + arr[m - 1][i];
    }

    // Fill Last Coloumn (bottom to top)--
    for (int i = m - 2; i >= 0; i--)
    {
        path[i][n - 1] = path[i + 1][n - 1] + arr[i][n - 1];
    }

    // Fill Remaining Cells--
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            path[i][j] = arr[i][j] + min(path[i + 1][j + 1], min(path[i + 1][j], path[i][j + 1]));
        }
    }

    return path[0][0];
}

int main()
{
    int m, n;
    cin >> m >> n;

    // Construction of Heap Memory--
    int **arr = new int *[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << minCostPath(arr, m, n) << endl;

    // Delete Heap Memory--
    for (int i = 0; i < m; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}