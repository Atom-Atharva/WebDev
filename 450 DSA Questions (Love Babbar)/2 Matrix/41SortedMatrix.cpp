// https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1

// Given an NxN matrix Mat. Sort all elements of the matrix.

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    /*
        Method 1: Naive sol--
        1. Make an 1D array and store all elements in the array
        2. Sort the 1D array
        3. Insert back in matrix
    */
    vector<vector<int>> sortedMatrix(int n, vector<vector<int>> mat)
    {
        // Make 1D Array--
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr.push_back(mat[i][j]);
            }
        }

        // Sort the 1D array--
        sort(arr.begin(), arr.end());

        // Insert back into matrix;
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = arr[k++];
            }
        }

        return mat;
    }
};