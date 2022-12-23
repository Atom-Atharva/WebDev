#include <iostream>
using namespace std;

void ratInMazeHelper(int **arr, int n, int **sol, int row, int col)
{

    // Rat to its destination--
    if (row == n - 1 && col == n - 1)
    {
        sol[row][col] = 1;
        // Print Solution Path--
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << sol[i][j] << " ";
            }
        }
        cout << endl;
        sol[row][col]=0;
        return;
    }

    // Kab Kab Include nahi karna--
    if (row >= n || row < 0 || col >= n || col < 0 || arr[row][col] == 0 || sol[row][col] == 1)
    {
        return;
    }

    sol[row][col] = 1;
    ratInMazeHelper(arr, n, sol, row - 1, col);
    ratInMazeHelper(arr, n, sol, row + 1, col);
    ratInMazeHelper(arr, n, sol, row, col - 1);
    ratInMazeHelper(arr, n, sol, row, col + 1);
    sol[row][col] = 0;

    return;

    // sol[row][col] = 1;
    // // Rat comes to its destination--
    // if (row == n - 1 && col == n - 1)
    // {
    //     // Print Solution Path--
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             cout << sol[i][j];
    //         }
    //     }
    //     cout << endl;
    //     return;
    // }

    // // Rat Travels to all the direction--
    // // Up Side--
    // if (arr[row - 1][col] != 0 && row - 1 >= 0 && col >= 0 && row - 1 < n && col < n)
    // {
    //     if (sol[row - 1][col] != 1)
    //     {
    //         // sol[row - 1][col] = 1;
    //         ratInMazeHelper(arr, n, sol, row - 1, col);
    //         sol[row - 1][col] = 0;
    //     }
    // }

    // // Down Side--
    // if (arr[row + 1][col] != 0 && row + 1 >= 0 && col >= 0 && row + 1 < n && col < n)
    // {
    //     if (sol[row + 1][col] != 1)
    //     {
    //         // sol[row + 1][col] = 1;
    //         ratInMazeHelper(arr, n, sol, row + 1, col);
    //         sol[row + 1][col] = 0;
    //     }
    // }

    // // Left Side--
    // if (arr[row][col - 1] != 0 && row >= 0 && col - 1 >= 0 && row < n && col - 1 < n)
    // {
    //     if (sol[row][col - 1] != 1)
    //     {
    //         // sol[row][col - 1] = 1;
    //         ratInMazeHelper(arr, n, sol, row, col - 1);
    //         sol[row][col - 1] = 0;
    //     }
    // }

    // // Right Side--
    // if (arr[row][col + 1] != 0 && row >= 0 && col + 1 >= 0 && row < n && col + 1 < n)
    // {
    //     if (sol[row][col + 1] != 1)
    //     {
    //         // sol[row][col + 1] = 1;
    //         ratInMazeHelper(arr, n, sol, row, col + 1);
    //         sol[row][col + 1] = 0;
    //     }
    // }

    // return;
}

void ratInTheMaze(int **arr, int n)
{
    // Solution Path Matrix--
    int **sol = new int *[n];
    for (int i = 0; i < n; i++)
    {
        sol[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            sol[i][j] = 0;
        }
    }
    ratInMazeHelper(arr, n, sol, 0, 0);
    return;
}

int main()
{
    int n;
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    ratInTheMaze(arr, n);

    return 0;
}