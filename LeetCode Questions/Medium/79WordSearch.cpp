// https://leetcode.com/problems/word-search/

// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    bool exist(vector<vector<char>> &board, string word, int n, int m, int i, int j, int k)
    {
        // Base Case--
        if (word.size() == k)
        {
            return true;
        }
        if (i < 0 || j < 0 || i >= n || j >= m)
        {
            return false;
        }
        if (word[k] != board[i][j])
        {
            return false;
        }
        // if (word.size() == 1 && word[k] == board[i][j])
        // {
        //     return true;
        // }

        board[i][j] = '.';
        int x[4] = {-1, 0, 0, +1};
        int y[4] = {0, 1, -1, 0};

        bool ans = false;
        for (int index = 0; index < 4; index++)
        {
            ans = ans || exist(board, word, n, m, i + x[index], j + y[index], k + 1);
        }

        board[i][j] = word[k];
        return ans;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();

        // First letter--
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (exist(board, word, n, m, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
};

// Run time Error--
//  class Solution
//  {
//      bool exist(vector<vector<char>> &board, string word, int i, int j, int w, vector<vector<bool>> &visited)
//      {
//          // Base Case--
//          if (w == word.size())
//          {
//              return true;
//          }
//          if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
//          {
//              return false;
//          }
//          if (visited[i][j] || word[w] != board[i][j])
//          {
//              return false;
//          }

//         // Position Marked True--
//         visited[i][j] = true;

//         bool ans = false;
//         ans = exist(board, word, i + 1, j, w + 1, visited);
//         ans = ans || exist(board, word, i, j + 1, w + 1, visited);
//         ans = ans || exist(board, word, i - 1, j, w + 1, visited);
//         ans = ans || exist(board, word, i, j - 1, w + 1, visited);

//         visited[i][j] = false;

//         return ans;
//     }

// public:
//     bool exist(vector<vector<char>> &board, string word)
//     {
//         vector<vector<bool>> visited;
//         for (int i = 0; i < board.size(); i++)
//         {
//             for (int j = 0; j < board[0].size(); j++)
//             {
//                 visited[i][j] = false;
//             }
//         }

//         for (int i = 0; i < board.size(); i++)
//         {
//             for (int j = 0; j < board[0].size(); j++)
//             {
//                 if (board[i][j] == word[0])
//                 {
//                     if (exist(board, word, i, j, 0, visited))
//                     {
//                         return true;
//                     }
//                 }
//             }
//         }
//         return false;
//     }
// };