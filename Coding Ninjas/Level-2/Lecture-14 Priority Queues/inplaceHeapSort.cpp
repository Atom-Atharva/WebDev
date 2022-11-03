#include <iostream>
using namespace std;

void heapSort(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    int hst = 0, hen = 1;
    int child = hen;
    while (hen < n)
    {
        if (child == hst)
        {
            hen++; // Adding into heap.
            child = hen;
            continue;
        }
        int parent = (child - 1) / 2;
        if (arr[child] > arr[parent])
        {
            int temp = arr[child];
            arr[child] = arr[parent];
            arr[parent] = temp;
            if (arr[child] > arr[2 * parent + 1])
            {
                int temp = arr[child];
                arr[child] = arr[2 * parent + 1];
                arr[2 * parent + 1] = temp;
                child = 2 * parent + 1;
            }
            child = parent;
        }
        else
        {
            hen++; // Adding into heap.
            child = hen;
        }
    }
    return;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;

    heapSort(arr, n);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}