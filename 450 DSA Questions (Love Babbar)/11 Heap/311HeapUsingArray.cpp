// https://www.codingninjas.com/studio/problems/build-heap_975375

// Build Heap from Array--

#include <iostream>
using namespace std;
#include <vector>

// *IMPORTANT* Time Complexity: O(n) (But Seems like O(NlogN))--
class Solution
{
public:
    vector<int> buildHeap(vector<int> arr, int n)
    {
        // Base Case--
        if (n <= 1)
        {
            return arr;
        }

        // Starts from non-leaf node--
        for (int i = ((n - 1) - 1) / 2; i >= 0; i--)
        {
            // Arrange Heap--
            int parent = i;
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
        }

        return arr;
    }
};