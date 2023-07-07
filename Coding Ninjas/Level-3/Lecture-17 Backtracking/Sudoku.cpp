#include <iostream>
using namespace std;

bool findEmptyLocation(int **board, int &row, int &col)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool isSafeRow(int **board, int row, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
        {
            return false;
        }
    }
    return true;
}

bool isSafeColumn(int **board, int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
        {
            return false;
        }
    }
    return true;
}

bool isSafeGrid(int **board, int row, int col, int num)
{
    int rowst = row - row % 3, rowen = rowst + 3;
    int colst = col - col % 3, colen = colst + 3;

    for (int i = rowst; i < rowen; i++)
    {
        for (int j = colst; j < colen; j++)
        {
            if (board[i][j] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int **board, int row, int col, int num)
{
    if (isSafeRow(board, row, num) && isSafeColumn(board, col, num) && isSafeGrid(board, row, col, num))
    {
        return true;
    }
    return false;
}

bool solveSudoku(int **board)
{
    int row, col;
    if (!findEmptyLocation(board, row, col))
    {
        return true;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (isSafe(board, row, col, i))
        {
            board[row][col] = i;
            if (solveSudoku(board))
            {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    int **board = new int *[9];
    for (int i = 0; i < 9; i++)
    {
        board[i] = new int[9];
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }

    bool solvable = solveSudoku(board);
    if (solvable)
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}