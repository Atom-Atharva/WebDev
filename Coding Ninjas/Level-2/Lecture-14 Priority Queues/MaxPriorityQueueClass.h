#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMax()
    {
        if (isEmpty())
        {
            return INT_MAX;
        }
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        // Up-Heapify--
        int childIndex = pq.size() - 1;
        while (childIndex >= 0)
        {
            int parent = (childIndex - 1) / 2;
            if (pq[childIndex] > pq[parent])
            {
                int temp = pq[parent];
                pq[parent] = pq[childIndex];
                pq[childIndex] = temp;
                childIndex = parent;
            }
            else
            {
                break;
            }
        }
    }

    int removeMax()
    {
        if (isEmpty())
        {
            return INT_MAX;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        // Down-Heapify--
        int parent = 0;
        int lchild = 2 * parent + 1;
        int rchild = 2 * parent + 2;
        while (lchild < pq.size())
        {
            int maxIndex = parent;
            if (pq[maxIndex] < pq[lchild])
            {
                maxIndex = lchild;
            }
            if (pq[maxIndex] < pq[rchild])
            {
                maxIndex = rchild;
            }
            if (maxIndex == parent)
            {
                break;
            }

            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parent];
            pq[parent] = temp;

            parent = maxIndex;
            lchild = 2 * parent + 1;
            rchild = 2 * parent + 2;
        }
        return ans;
    }
};