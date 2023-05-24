// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

// Given a matrix of size r*c. Traverse the matrix in spiral form.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        int rs = 0, re = r - 1;
        int cs = 0, ce = c - 1;

        vector<int> spiral;

        while (rs <= re || cs <= ce)
        {
            // As r and c are not equal thus we need to check every time for out of bound--

            // First Row--
            for (int i = cs; i <= ce && rs <= re; i++)
            {
                spiral.push_back(matrix[rs][i]);
            }
            rs++;

            // Last Column--
            for (int i = rs; i <= re && cs <= ce; i++)
            {
                spiral.push_back(matrix[i][ce]);
            }
            ce--;

            // Last Row--
            for (int i = ce; i >= cs && rs <= re; i--)
            {
                spiral.push_back(matrix[re][i]);
            }
            re--;

            // First Column--
            for (int i = re; i >= rs && cs <= ce; i--)
            {
                spiral.push_back(matrix[i][cs]);
            }
            cs++;
        }
        return spiral;
    }
};