// https://leetcode.com/problems/valid-sudoku/

// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.

#include <iostream>
using namespace std;
#include <vector>

// Method-2
// Use HashMaps--
// Reduces Time Complexity but increases Space Complexity.

// Method-1
// Brute Force Approach--
// Itteration over each element.
class Solution
{
    bool checkRow(vector<vector<char>> &board, int row, int col)
    {
        for (int i = row + 1; i < 9; i++)
        {
            if (board[i][col] == '.')
            {
                continue;
            }
            if (board[i][col] == board[row][col])
            {
                return false;
            }
        }
        return true;
    }

    bool checkCol(vector<vector<char>> &board, int row, int col)
    {
        for (int j = col + 1; j < 9; j++)
        {
            if (board[row][j] == '.')
            {
                continue;
            }
            if (board[row][j] == board[row][col])
            {
                return false;
            }
        }
        return true;
    }

    bool checkBlock(vector<vector<char>> &board, int row, int col)
    {
        for (int i = row - (row % 3); i < row + (3 - (row % 3)); i++)
        {
            for (int j = col - (col % 3); j < col + (3 - (col % 3)); j++)
            {
                if (board[i][j] == '.' || (i == row && j == col))
                {
                    continue;
                }

                if (board[i][j] == board[row][col])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // Iterate over each valid element--
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }

                //      Check for row validity--
                bool row = checkRow(board, i, j);

                //      Check for coloumn validity--
                bool col = checkCol(board, i, j);

                //      Check for block validity--
                bool block = checkBlock(board, i, j);

                if (!row || !col || !block)
                {
                    return false;
                }
            }
        }
        return true;
    }
};