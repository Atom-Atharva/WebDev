#include <iostream>
using namespace std;

// Method-1--
//  #include <climits>

// void insertInHeap(int arr[], int n, int en)
// {
//     if (en == n)
//     {
//         return;
//     }

//     // Up-Heapify of new Element ADDED--
//     int child = en;
//     while (child > 0)
//     {
//         int parent = (child - 1) / 2;
//         if (arr[parent] > arr[child])
//         {
//             int temp = arr[parent];
//             arr[parent] = arr[child];
//             arr[child] = temp;
//             child = parent;
//         }
//         else
//         {
//             break;
//         }
//     }

//     // Function Call--
//     insertInHeap(arr, n, en + 1);
//     return;
// }

// void removeFromHeap(int arr[], int n, int en)
// {
//     if (en == 1)
//     {
//         int temp = arr[0];
//         arr[0] = arr[1];
//         arr[1] = temp;
//         return;
//     }
//     int temp = arr[0];
//     arr[0] = arr[en];
//     arr[en] = temp;

//     // Down-Heapify--
//     int parent = 0;
//     while (2 * parent + 1 <= en)
//     {
//         int lchild = INT_MAX;
//         if (2 * parent + 1 < en)
//         {
//             lchild = 2 * parent + 1;
//         }
//         int rchild = INT_MAX;
//         if (2 * parent + 2 < en)
//         {
//             rchild = 2 * parent + 2;
//         }

//         int minchild;
//         if (rchild == INT_MAX)
//         {
//             minchild = lchild;
//         }
//         else if (arr[lchild] < arr[rchild])
//         {
//             minchild = lchild;
//         }
//         else
//         {
//             minchild = rchild;
//         }

//         if (arr[parent] > arr[minchild])
//         {
//             int temp = arr[parent];
//             arr[parent] = arr[minchild];
//             arr[minchild] = temp;
//             parent = minchild;
//         }
//         else
//         {
//             break;
//         }
//     }

//     // Function Call--
//     removeFromHeap(arr, n, en - 1);
//     return;
// }

// void heapSort(int arr[], int n)
// {
//     if (n == 0 || n == 1)
//     {
//         return;
//     }

//     insertInHeap(arr, n, 1);
//     removeFromHeap(arr, n, n - 1);

//     return;
// }

// Method-2--
void heapSort(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }

    // Insert in Heap--
    int nextIndex = 1;
    while (nextIndex < n)
    {
        int child = nextIndex;
        while (child > 0)
        {
            int parent = (child - 1) / 2;
            if (arr[parent] > arr[child])
            {
                int temp = arr[parent];
                arr[parent] = arr[child];
                arr[child] = temp;
            }
            else
            {
                break;
            }
            child = parent;
        }

        nextIndex++;
    }

    // Removing from Heap--
    int lastIndex = n - 1;
    while (lastIndex > 0)
    {
        int temp = arr[lastIndex];
        arr[lastIndex] = arr[0];
        arr[0] = temp;

        lastIndex--;

        int parent = 0;
        while (2 * parent + 1 <= lastIndex)
        {
            int lchild = 2 * parent + 1;
            int rchild = 2 * parent + 2;
            int minChild = parent;
            if (arr[parent] > arr[lchild])
            {
                minChild = lchild;
            }
            if (rchild <= lastIndex && arr[minChild] > arr[rchild])
            {
                minChild = rchild;
            }
            if (minChild == parent)
            {
                break;
            }

            int temp = arr[minChild];
            arr[minChild] = arr[parent];
            arr[parent] = temp;

            parent = minChild;
        }
    }
    return;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    heapSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}