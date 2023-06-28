// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

// Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

// Note :-  l and r denotes the starting and ending index of the array.

#include <iostream>
using namespace std;
#include <queue>

// Method 2: Quick Select--
// TODO: DO THIS AGAIN--
class Solution
{
    int pivot(int arr[], int l, int r)
    {
        int count = 0;
        for (int i = l + 1; i <= r; i++)
        {
            if (arr[i] < arr[l])
            {
                count++;
            }
        }

        int P = count + l;

        int temp = arr[P];
        arr[P] = arr[l];
        arr[l] = temp;

        int i = l, j = r;
        while (i < P && j > P)
        {
            if (arr[i] < arr[P])
            {
                i++;
            }
            else if (arr[j] >= arr[P])
            {
                j--;
            }
            else
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                i++;
                j--;
            }
        }
        return P;
    }

    void quick(int arr[], int l, int r, int k)
    {
        if (l >= r)
        {
            return;
        }

        int P = pivot(arr, l, r);

        if (P - l == k - 1)
        {
            return;
        }
        else if (P - l > k - 1)
        {
            quick(arr, l, P - 1, k);
        }
        else
        {
            quick(arr, P + 1, r, k - P + l - 1);
        }

        return;
    }

public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        quick(arr, l, r, k);

        return arr[k];
    }
};

// Time Complexity Exceeded
// Method 1: Priority Queue
//  class Solution
//  {
//  public:
//      // arr : given array
//      // l : starting index of the array i.e 0
//      // r : ending index of the array i.e size-1
//      // k : find kth smallest element and return using this function
//      int kthSmallest(int arr[], int l, int r, int k)
//      {
//          // Insert into minHeap--
//          priority_queue<int, vector<int>, greater<int>> minHeap;
//          for (int i = l; i <= r; i++)
//          {
//              minHeap.push(arr[i]);
//          }

//         // Remove k-1 elements from heap--
//         for (int i = k; i > 0; i--)
//         {
//             minHeap.pop();
//         }

//         // Return top element--
//         return minHeap.top();
//     }
// };