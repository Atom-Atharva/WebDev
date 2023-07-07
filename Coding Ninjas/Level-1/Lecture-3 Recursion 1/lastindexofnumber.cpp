#include <iostream>
using namespace std;

// Method-1:

int lastIndex(int arr[], int n, int x)
{
    if (n == 0)
    {
        return -1;
    }

    int smallout = lastIndex(arr + 1, n - 1, x);
    if (smallout == -1)
    {
        if (arr[0] == x)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return smallout + 1;
    }
}

/*
//Method-2:

int lastIndex(int arr[], int n, int x)
{
    if (n == 0)
    {
        return -1;
    }
    if (arr[n - 1] == x)
    {
        return n - 1;
    }
    else
    {
        int smallout = lastIndex(arr, n - 1, x);
        if (smallout == -1)
        {
            return -1;
        }
        else
        {
            return smallout;
        }
    }
}
*/

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

    int ans = lastIndex(arr, n, x);

    cout << ans << endl;

    delete[] arr;
    return 0;
}