#include <iostream>
using namespace std;

int firstIndex(int arr[], int n, int x)
{
    if (n == 0)
    {
        return -1;
    }
    if (arr[0] == x)
    {
        return 0;
    }
    else
    {
        int smallout = firstIndex(arr + 1, n - 1, x);
        if (smallout == -1)
        {
            return -1;
        }
        else
        {
            return smallout + 1;
        }
    }
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

    int ans = firstIndex(arr, n, x);
    cout << ans << endl;

    delete[] arr;

    return 0;
}