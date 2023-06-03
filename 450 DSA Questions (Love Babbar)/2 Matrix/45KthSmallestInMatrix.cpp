// https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1

// Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

// Input:
// N = 4
// mat[][] =     {{16, 28, 60, 64},
//                    {22, 41, 63, 91},
//                    {27, 50, 87, 93},
//                    {36, 78, 87, 94 }}
// K = 3
// Output: 27
// Explanation: 27 is the 3rd smallest element.

#include <iostream>
using namespace std;
#include <queue>

#define MAX 100

class Solution
{
public:
    // Using Min Heap--
    // Time Complexity: O(n^2).
    int kthSmallest(int mat[MAX][MAX], int n, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Submit All Elements in Heap--
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                minHeap.push(mat[i][j]);
            }
        }

        // Remove k-1 elements from head--
        for (int i = 0; i < k - 1; i++)
        {
            minHeap.pop();
        }

        return minHeap.top();
    }
};