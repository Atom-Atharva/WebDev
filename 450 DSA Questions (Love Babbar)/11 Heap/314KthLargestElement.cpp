// https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1

// Given an array Arr of N positive integers and an integer K, find K largest elements from the array.  The output elements should be printed in decreasing order.

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

// User function template for C++
class Solution
{
public:
    vector<int> kLargest(int arr[], int n, int k)
    {
        // Insert into heap--
        priority_queue<int> maxHeap;
        for (int i = 0; i < n; i++)
        {
            maxHeap.push(arr[i]);
        }

        // Takeout k elements from heap--
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(maxHeap.top());
            maxHeap.pop();
        }

        return ans;
    }
};