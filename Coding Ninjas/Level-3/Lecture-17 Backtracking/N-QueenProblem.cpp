#include <iostream>
using namespace std;

bool isPossible(int **arr, int n, int row, int col)
{
    // Same Coloumn--
    for (int i = row - 1; i >= 0; i--)
    {
        if (arr[i][col] == 1)
        {
            return false;
        }
    }

    // Upper-Right Diagonal--
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (arr[i][j] == 1)
        {
            return false;
        }
    }

    // Upper-Left Diagonal--
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (arr[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

void printConfigurationHelper(int **arr, int n, int row)
{
    if (row == n)
    {
        // Print Configuration--
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }

    // Place in Correct position--
    for (int j = 0; j < n; j++)
    {
        // Check at a position--
        if (isPossible(arr, n, row, j))
        {
            // Place and Call for smaller problem--
            arr[row][j] = 1;
            printConfigurationHelper(arr, n, row + 1);

            // Backtracked--
            arr[row][j] = 0;
        }
    }
    return;
}

void printAllConfiguration(int **arr, int n)
{
    printConfigurationHelper(arr, n, 0);
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
            arr[i][j] = 0;
        }
    }

    printAllConfiguration(arr, n);

    return 0;
}
