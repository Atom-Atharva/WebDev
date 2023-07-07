// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    void path(vector<vector<int>> &m, int n, int i, int j, vector<string> &ans, string p)
    {
        // Base Case--
        if (i == n || j == n || i < 0 || j < 0)
        {
            return;
        }
        if (m[i][j] == 0)
        {
            return;
        }
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(p);
            return;
        }

        // Set--
        m[i][j] = 0;

        // Recursive Calls--
        path(m, n, i + 1, j, ans, p + "D");
        path(m, n, i, j + 1, ans, p + "R");
        path(m, n, i - 1, j, ans, p + "U");
        path(m, n, i, j - 1, ans, p + "L");

        // Reset--
        m[i][j] = 1;

        return;
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        path(m, n, 0, 0, ans, "");
        if (ans.size() == 0)
        {
            ans.push_back("-1");
        }

        return ans;
    }
};