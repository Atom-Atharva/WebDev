#include <vector>
#include <iostream>
#include <climits>
using namespace std;

class PriorityQueue
{
    // Stored in array but visualize as CBT(Complete Binary Tree).
    vector<int> pq;

public:
    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int size()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
        {
            return INT_MIN; // Represents Priority Queue is Empty.
        }
        return pq[0];
    }

    // Insertion and deletion of the element in Priority Queue is the example of HEAP SORT--
    // Time Complexity--O(nlogn)
    // Space Complexity--O(n)
    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
        if (isEmpty())
        {
            return INT_MIN;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        // Down-heapify--

        int parent = 0;
        int lchild = 2 * parent + 1;
        int rchild = 2 * parent + 2;

        while (lchild < pq.size())
        {
            int minIndex = parent;

            if (pq[minIndex] > pq[lchild])
            {
                minIndex = lchild;
            }
            if (rchild < pq.size() && pq[minIndex] > pq[rchild])
            {
                minIndex = rchild;
            }
            if (minIndex == parent)
            {
                break;
            }

            int temp = pq[minIndex];
            pq[minIndex] = pq[parent];
            pq[parent] = temp;

            parent = minIndex;
            lchild = 2 * parent + 1;
            rchild = 2 * parent + 2;
        }
        return ans;
    }
};