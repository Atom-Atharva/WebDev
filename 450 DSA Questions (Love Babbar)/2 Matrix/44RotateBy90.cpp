// https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/

// Given a square matrix, turn it by 90 degrees in a clockwise direction without using any extra space.

#include <iostream>
using namespace std;

#define N 100

class Solution
{
public:
    // To Rotate 90 Clockwise--
    // Step 1: Mirror From Right Diagonals
    // Step 2: Reverse Each Row--
    void rotate90ClockWise(int a[N][N])
    {
        // Mirror From Right Diagonal--
        for (int i = 0; i < N; i++)
        {
            for (int j = i; j < N; j++)
            {
                int temp = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = temp;
            }
        }

        // Reverse Row--
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N / 2; j++)
            {
                int temp = a[i][j];
                a[i][j] = a[i][N - j - 1];
                a[i][N - j - 1] = temp;
            }
        }

        return;
    }
};