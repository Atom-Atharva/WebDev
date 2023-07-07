// https://leetcode.com/problems/merge-sorted-array/

// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

#include <iostream>
using namespace std;
#include <vector>

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    if (n == 0)
    {
        return;
    }
    vector<int> ans;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            ans.push_back(nums1[i]);
            i++;
        }
        else
        {
            ans.push_back(nums2[j]);
            j++;
        }
    }
    while (i < m)
    {
        ans.push_back(nums1[i]);
        i++;
    }
    while (j < n)
    {
        ans.push_back(nums2[j]);
        j++;
    }

    for (int i = 0; i < m + n; i++)
    {
        nums1[i] = ans[i];
    }
    return;
}

int main()
{
    int m;
    cin >> m;

    vector<int> nums1;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        nums1.push_back(a);
    }

    int n;
    cin >> n;

    vector<int> nums2;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        nums2.push_back(a);
    }

    for (int i = 0; i < m - n; i++)
    {
        nums1.push_back(0);
    }

    merge(nums1, m, nums2, n);

    for (int i = 0; i < n + m; i++)
    {
        cout << nums1[i] << " ";
    }

    return 0;
}
