// https://leetcode.com/problems/uncrossed-lines/

// You are given two integer arrays nums1 and nums2. We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.

// We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:

// nums1[i] == nums2[j], and
// the line we draw does not intersect any other connecting (non-horizontal) line.
// Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).

// Return the maximum number of connecting lines we can draw in this way.

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

/*********************IMPORTANT QUESTION***************************/

// Dynammic Programming--
class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        // n+1,m+1 denotes lenght of nums (including 0)
        int arr[n + 1][m + 1];

        // First Cell--
        arr[0][0] = 0;

        // First Row--
        for (int i = 1; i <= m; i++)
        {
            arr[0][i] = 0;
        }

        // First Coloumn--
        for (int i = 1; i <= n; i++)
        {
            arr[i][0] = 0;
        }

        // Fill Remaining cells--
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // If character are same,
                // nums ka i-1 barabar arr[i] because arr[n+1] ka banaya hai--
                if (nums1[i - 1] == nums2[j - 1])
                {
                    arr[i][j] = 1 + arr[i - 1][j - 1];
                }
                else
                {
                    arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
                }
            }
        }

        return arr[n][m];
    }
};

// Reccursion--
// class Solution
// {
//  //More Optimized Method--
//     int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2, int i, int j)
//     {
//         // Base Case--
//         if (j == nums2.size() || i == nums1.size())
//         {
//             return 0;
//         }

//         // Small Calculation--
//         int ans = 0;
//         if (nums1[i] == nums2[j])
//         {
//             ans++;
//             // Reccursion Call--
//             ans += maxUncrossedLines(nums1, nums2, i + 1, j + 1);
//         }
//         else
//         {
//             // Reccursion Call--
//             ans += max(maxUncrossedLines(nums1, nums2, i + 1, j), maxUncrossedLines(nums1, nums2, i, j + 1));
//         }

//         return ans;
//     }

//     // int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2, int i, int j)
//     // {
//     //     // Base Case--
//     //     if (j == nums2.size() || i == nums1.size())
//     //     {
//     //         return 0;
//     //     }

//     //     // Small Connection--
//     //     int maxans = 0;
//     //     for (int k = j; k < nums2.size(); k++)
//     //     {
//     //         int ans = 0;
//     //         if (nums1[i] == nums2[k])
//     //         {
//     //             ans++;
//     //             // Reccursive Calls--
//     //             ans += maxUncrossedLines(nums1, nums2, i + 1, k + 1);
//     //             maxans = max(maxans, ans);
//     //         }
//     //     }

//     //     // Not included--
//     //     maxans = max(maxans, maxUncrossedLines(nums1, nums2, i + 1, j));

//     //     return maxans;
//     // }

// public:
//     int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
//     {
//         return maxUncrossedLines(nums1, nums2, 0, 0);
//     }
// };