// https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/

// Given an m x n matrix, find all common elements present in all rows in O(mn) time and one traversal of matrix.

#include <iostream>
using namespace std;
#include <unordered_map>

#define M 5
#define N 4

class Solution
{
public:
    void printCommonElements(int mat[M][N])
    {
        unordered_map<int, int> common;
        for (int i = 0; i < M; i++)
        {
            unordered_map<int, int> row;
            for (int j = 0; j < N; j++)
            {
                // Insert First Row As reference--
                if (i == 0)
                {
                    common[mat[i][j]] = 1;
                    continue;
                }

                // Increase Occurance of each non-dublicate element--
                row[mat[i][j]]++;
                if (row[mat[i][j]] == 1)
                {
                    common[mat[i][j]++];
                }
            }
        }

        // Cout All elements with occurance == rows.
        for (auto itr : common)
        {
            if (itr.second == M)
            {
                cout << itr.first << " ";
            }
        }

        return;
    }
};