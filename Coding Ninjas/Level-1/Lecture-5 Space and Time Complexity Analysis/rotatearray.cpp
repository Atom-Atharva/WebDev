#include <iostream>
using namespace std;

void rotate(int *arr, int d, int n)
{
    if (d == 0)
    {
        return;
    }
    int *temp = new int[n];
    int k = 0;
    for (int i = 0; i < n - d; i++, k++)
    {
        temp[k] = arr[i + d];
    }
    for (int i = 0; i < d; i++, k++)
    {
        temp[k] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }

    delete[] temp;
    return;
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

    rotate(arr, x, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}