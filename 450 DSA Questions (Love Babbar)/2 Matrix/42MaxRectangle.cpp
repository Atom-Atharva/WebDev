// https://practice.geeksforgeeks.org/problems/max-rectangle/1

// Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

#include <iostream>
using namespace std;
#include <stack>

// #define MAX 1000

class Solution
{
public:
    int maxArea(int M[100][100], int n, int m)
    {
        int maxarea = 0;
        for (int i = 0; i < n; i++)
        {
            // Make Histogram of the current row--
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] == 1)
                {
                    (i > 0) ? M[i][j] += M[i - 1][j] : M[i][j] = M[i][j];
                }
            }

            // Store previous small index--
            stack<int> prev;
            int psmall[m];

            for (int j = 0; j < m; j++)
            {
                while (!prev.empty() && M[i][j] <= M[i][prev.top()])
                {
                    prev.pop();
                }

                if (prev.empty())
                {
                    psmall[j] = -1;
                }
                else
                {
                    psmall[j] = prev.top();
                }

                prev.push(j);
            }

            // Store next small index--
            stack<int> next;
            int nsmall[m];

            for (int j = m - 1; j >= 0; j--)
            {
                while (!next.empty() && M[i][j] <= M[i][next.top()])
                {
                    next.pop();
                }

                if (next.empty())
                {
                    nsmall[j] = m;
                }
                else
                {
                    nsmall[j] = next.top();
                }
                next.push(j);
            }

            // Find Max Area of the row--
            int area = 0;
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] != 0)
                {
                    int curarea = (nsmall[j] - psmall[j] - 1) * M[i][j];
                    area = max(area, curarea);
                }
            }

            // Update Max Area of Matrix so far--
            maxarea = max(maxarea, area);
        }

        return maxarea;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    int M[100][100];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends