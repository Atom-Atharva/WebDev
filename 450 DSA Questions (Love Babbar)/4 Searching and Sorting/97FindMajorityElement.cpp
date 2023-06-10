// https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1

// Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.

// Example 1:

// Input:
// N = 3
// A[] = {1,2,3}
// Output:
// -1
// Explanation:
// Since, each element in
// {1,2,3} appears only once so there
// is no majority element.

#include <iostream>
using namespace std;
#include <algorithm>
#include <unordered_map>

// Method 2: Maps
// Time Complexity O(n)--
class Solution
{
public:
    int majorityElement(int a[], int size)
    {
        unordered_map<int, int> seen;
        for (int i = 0; i < size; i++)
        {
            seen[a[i]]++;
        }

        for (auto itr : seen)
        {
            if (itr.second > size / 2)
            {
                return itr.first;
            }
        }
        return -1;
    }
};

// Method 1: Sorting
// Time Complexity O(nlogn)--
class Solution
{
public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        // Sort Array--
        sort(a, a + size);

        // Calculate Occurances--
        int occ = 1;
        int i;
        for (i = 1; i < size; i++)
        {
            if (occ > size / 2)
            {
                break;
            }
            if (a[i] == a[i - 1])
            {
                occ++;
            }
        }
        if (i != size)
        {
            return a[i];
        }

        return -1;
    }
};