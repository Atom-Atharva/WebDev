// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

// Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

/**********Important Question***********/

#include <iostream>
using namespace std;
#include <vector>

// Method: 1(Naive Solution)
// 1. Place All element in new array- O(r*c)
// 2. Sort the new array- O(r*c*log(r*c))
// 3. Find the median of the array- O(1)
// Time Complexity: O(r*c*log(r*c))

// Method: 2(Binary Search)
class Solution
{
    int findLessOrEqual(vector<vector<int>> &matrix, int R, int C, int target)
    {
        int sum = 0;
        for (int i = 0; i < R; i++)
        {
            int st = 0, en = C - 1;
            while (st <= en)
            {
                int mid = (st + en) / 2;
                if (matrix[i][mid] <= target)
                {
                    st = mid + 1;
                }
                else
                {
                    en = mid - 1;
                }
            }
            sum += st;
        }
        return sum;
    }

public:
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        int st = matrix[0][0], en = matrix[R - 1][C - 1];

        // Find max and min element in matrix--
        for (int i = 0; i < R; i++)
        {
            st = min(st, matrix[i][0]);
            en = max(en, matrix[i][C - 1]);
        }

        // In the [st,en] range find median with Binary Search--
        while (st <= en)
        {
            int mid = (st + en) / 2;

            // Find no. of elements <= mid in matrix--
            int elements = findLessOrEqual(matrix, R, C, mid);

            // Relation Between Elements Less or Equal present and required for median(i.e, n/2)--
            if (elements <= (R * C) / 2)
            {
                st = mid + 1;
            }
            else
            {
                en = mid - 1;
            }
        }

        return st;
    }
};