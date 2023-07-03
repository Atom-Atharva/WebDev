// https://leetcode.com/problems/n-queens/

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    // Check Validity--
    bool valid(int n, vector<vector<char>> &board, int i, int j)
    {

        // Check Row--
        for (int row = 0; row < i; row++)
        {
            if (board[row][j] == 'Q')
            {
                return false;
            }
        }

        // Check Column--
        for (int col = 0; col < j; col++)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }

        // Check Diagonals--
        for (int row = i - 1, col = j - 1; row >= 0 && col >= 0; row--, col--)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
        }
        for (int row = i - 1, col = j + 1; row >= 0 && col < n; row--, col++)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
        }

        return true;
    }

    void queens(int n, vector<vector<char>> &board, int i, int j, vector<vector<string>> &combinations)
    {
        // Base Case--
        if (i == n)
        {
            // Insert into combinations--
            vector<string> comb;
            for (int i = 0; i < n; i++)
            {
                string str = "";
                for (int j = 0; j < n; j++)
                {
                    str += board[i][j];
                }
                comb.push_back(str);
            }
            combinations.push_back(comb);

            return;
        }
        if (j == n)
        {
            return;
        }

        // If Postion of Queen is Valid--
        if (valid(n, board, i, j))
        {
            // Place Queen--
            board[i][j] = 'Q';

            // Recursive Call--
            queens(n, board, i + 1, 0, combinations);

            // Remove Queen--
            board[i][j] = '.';
        }
        queens(n, board, i, j + 1, combinations);

        return;
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        // Initialize Board--
        vector<vector<char>> board(n, vector<char>(n, '.'));

        // Combinations--
        vector<vector<string>> combinations;

        // Place Queens--
        queens(n, board, 0, 0, combinations);

        return combinations;
    }
};