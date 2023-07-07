#include <iostream>
using namespace std;

int binary_Search(int arr[], int n, int x, int st, int en)
{
    if (st > en)
    {
        return -1;
    }
    int mid = (st + en) / 2;
    if (x > arr[mid])
    {
        int smallans = binary_Search(arr, n, x, mid + 1, en);
    }
    else if (x < arr[mid])
    {
        int smallans = binary_Search(arr, n, x, st, mid - 1);
    }
    else
    {
        return mid;
    }
}

int binarySearch(int arr[], int n, int x)
{
    int st = 0, en = n - 1;
    return binary_Search(arr, n, x, st, en);
}

int main()
{

    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;

    int ans = binarySearch(arr, n, x);
    cout << ans << endl;

    delete[] arr;

    return 0;
}