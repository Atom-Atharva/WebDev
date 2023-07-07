// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

// Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

// Note :-  l and r denotes the starting and ending index of the array.

/***********************IMPORTANT QUESTION********************************/


#include <iostream>
using namespace std;

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function

    // Using Quick-Select Algorithm (Similar to Quick Sort)--
    // Average Time Complexity O(n)--
    // Best Time Complexity O(n)--
    // Worst Time Complexity O(n^2)--
    int kthSmallest(int arr[], int l, int r, int k)
    {
        // Step-1: Make a pivot
        int piv = arr[r];

        // Step-2: Make 2 pointers:
        //  j itterate over each element and i find correct place for pivot
        int i = l - 1, j = l;
        while (j <= r)
        {
            if (arr[j] <= piv)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }

        // Base Case--
        if (i + 1 == k)
        {
            return arr[i];
        }

        // Step-3: Reccursive calls--

        // If Left Part is IMP--
        if (i + 1 > k)
        {
            return kthSmallest(arr, l, i - 1, k);
        }
        // If Right Part is IMP--
        else
        {
            return kthSmallest(arr, i + 1, r, k);
        }
    }

    // Time Limit Exceeded O(n^2)--
    //  int kthSmallest(int arr[], int l, int r, int k)
    //  {
    //      // Base Case--
    //      if (k == 0 || l == r + 1)
    //      {
    //          return arr[l - 1];
    //      }

    //     // Search Smallest in between l and r--
    //     int smallest = arr[l];
    //     int index = l;
    //     for (int i = l; i <= r; i++)
    //     {
    //         if (arr[i] < smallest)
    //         {
    //             smallest = arr[i];
    //             index = i;
    //         }
    //     }

    //     // Swap with lth element--
    //     int ele = arr[l];
    //     arr[l]=arr[index];
    //     arr[index]=ele;

    //     //Reccursive Call--
    //     int ksmall=kthSmallest(arr,l+1,r,k-1);

    //     return ksmall;
    // }
};
