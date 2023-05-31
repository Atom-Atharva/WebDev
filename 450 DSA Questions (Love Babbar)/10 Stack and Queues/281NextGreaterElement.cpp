// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

// Given an array arr[] of size N having elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
// Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
// If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    // Time Complexity: O(n) -- ON AVERAGE SENERIOS.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        // Stores next greater element--
        stack<long long> greater;

        vector<long long> ans(n);

        // Starts from back of array--
        for (int i = n - 1; i >= 0; i--)
        {
            // check if the topmost element is larger or not--
            while (!greater.empty() && greater.top() <= arr[i])
            {
                greater.pop();
            }

            // Stack empty --> -1
            if (greater.size() == 0)
            {
                ans[i] = -1;
            }

            // Instert in ans array--
            else
            {
                ans[i] = greater.top();
            }
            greater.push(arr[i]);
        }

        return ans;
    }
};