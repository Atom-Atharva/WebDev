#include <iostream>
using namespace std;
#include <cmath>

// Method 1: Reccursion (Take or Refuse)--
class Solution
{
    int find(int a, int b, int n)
    {
        // Base Case--
        if (a == 0)
        {
            return 1;
        }
        if (n == 0 || a < 0)
        {
            return 0;
        }

        // Reccursive Calls--
        // Taken--
        int take = find(a - pow(n, b), b, n - 1);

        // Not Taken--
        int refuse = find(a, b, n - 1);

        return take + refuse;
    }

public:
    int getAllWays(int a, int b)
    {
        int n = pow(a, (double)1 / b);
        return find(a, b, n);
    }
};

// Wrong Method: Its finding sum of 2 unique numbers--
//  class Solution
//  {
//  public:
//      int getAllWays(int a, int b)
//      {
//          // Create DP Array--
//          int n = pow(a, (double)1 / b);
//          int **arr = new int *[n + 1];
//          for (int i = 0; i <= n; i++)
//          {
//              arr[i] = new int[n + 1];
//          }

//         // Fill Initial Cell--
//         arr[0][0] = 0;

//         // Fill First Row--
//         for (int i = 1; i <= n; i++)
//         {
//             if (pow(i, b) == a)
//             {
//                 arr[0][i] = 1;
//             }
//             else
//             {
//                 arr[0][i] = 0;
//             }
//         }

//         // Fill Rest of the cells--
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= n; j++)
//             {
//                 arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//                 if (i == j)
//                 {
//                     continue;
//                 }
//                 if (pow(i, b) + pow(j, b) == a)
//                 {
//                     arr[i][j]++;
//                 }
//             }
//         }

//         return arr[n][n];
//     }
// };