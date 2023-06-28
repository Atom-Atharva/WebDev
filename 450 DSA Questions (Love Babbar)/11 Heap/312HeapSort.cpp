// https://practice.geeksforgeeks.org/problems/heap-sort/1

// Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to implement Heap Sort.

// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

#include <iostream>
using namespace std;

class Solution
{
public:
    // Heapify function to maintain heap property.
    void heapify(int arr[], int n, int parent)
    {
        while (2 * parent + 1 < n)
        {
            int lchild = 2 * parent + 1;
            int rchild = 2 * parent + 2;

            // Check for child--
            int child;
            if (lchild < n && rchild < n)
            {
                child = (arr[lchild] > arr[rchild]) ? lchild : rchild;
            }
            else
            {
                child = lchild;
            }

            // Break Case--
            if (arr[parent] > arr[child])
            {
                break;
            }

            // Swapping with Child--
            int temp = arr[parent];
            arr[parent] = arr[child];
            arr[child] = temp;

            // Update Parent--
            parent = child;
        }
        return;
    }

public:
    // Function to build a Heap from array.
    void buildHeap(int arr[], int n)
    {
        // Base Case--
        if (n <= 1)
        {
            return;
        }

        // Starts from non-leaf node--
        for (int i = ((n - 1) - 1) / 2; i >= 0; i--)
        {
            // Arrange Heap--
            heapify(arr, n, i);
        }

        return;
    }

public:
    // Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        // Build Heap--
        buildHeap(arr, n);

        // Sort--
        while (n > 1)
        {
            // Largest to Last--
            int temp = arr[0];
            arr[0] = arr[n - 1];
            arr[n - 1] = temp;

            // Heapify Remaining Array--
            n--;
            heapify(arr, n, 0);
        }

        return;
    }
};