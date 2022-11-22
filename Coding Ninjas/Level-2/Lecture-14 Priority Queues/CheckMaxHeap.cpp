#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n)
{
    if (n == 0)
    {
        return true;
    }

    for (int i = 0; 2 * i + 1 < n; i++)
    {
        int lchild = 2 * i + 1;
        int rchild = lchild + 1;

        if (arr[i] < lchild || arr[i] < rchild)
        {
            return false;
        }
    }
    return true;
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
    bool check = isMaxHeap(arr, n);
    if (check)
    {
        cout << "TRUE\n";
    }
    else
    {
        cout << "FALSE\n";
    }

    return 0;
}