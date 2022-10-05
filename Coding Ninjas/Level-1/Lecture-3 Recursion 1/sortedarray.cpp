#include <iostream>
using namespace std;

bool checksort(int arr[], int n)
{
    if (n == 1)
    {
        return true;
    }
    if (arr[0] <= arr[1] && checksort(arr + 1, n - 1))
    {
        return true;
    }
    else
    {
        return false;
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

    if (checksort(arr, n))
    {
        cout << "True\n";
    }
    else
    {
        cout << "False\n";
    }

    delete[] arr;
    return 0;
}