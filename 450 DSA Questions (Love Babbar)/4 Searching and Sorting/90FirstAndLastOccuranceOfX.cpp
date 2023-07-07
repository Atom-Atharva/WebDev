// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1

// Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    vector<int> find(int arr[], int n, int x)
    {
        // Finding First Occurance--
        int st = 0, en = n - 1;
        while (st <= en)
        {
            int mid = (st + en) / 2;
            if (arr[mid] < x)
            {
                st = mid + 1;
            }
            else
            {
                en = mid - 1;
            }
        }
        vector<int> ans;
        
        // Check if x doesnt exist in array--
        if (arr[st] != x)
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(st);
        }

        // Finding Last Occurance--
        st = 0, en = n - 1;
        while (st <= en)
        {
            int mid = (st + en) / 2;
            if (arr[mid] <= x)
            {
                st = mid + 1;
            }
            else
            {
                en = mid - 1;
            }
        }

        // Check if x doesnt exist in array--
        if (arr[en] != x)
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(en);
        }

        return ans;
    }
};