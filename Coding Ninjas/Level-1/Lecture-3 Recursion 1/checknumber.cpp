#include <iostream>
using namespace std;

bool checkNumber(int arr[], int n, int x)
{
    if (n == 0)
    {
        return false;
    }
    if (arr[0] == x)
    {
        return true;
    }
    else
    {
        if (checkNumber(arr + 1, n - 1, x))
        {
            return true;
        }
        else
        {
            return false;
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

    if (checkNumber(arr, n, x))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    delete[] arr;

    return 0;
}