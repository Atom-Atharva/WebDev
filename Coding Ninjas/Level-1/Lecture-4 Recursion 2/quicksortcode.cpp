#include <iostream>
using namespace std;

int partition(int arr[], int st, int en)
{
    int count = 0;
    for (int i = st + 1; i <= en; i++)
    {
        if (arr[st] > arr[i])
        {
            count++;
        }
    }

    int P = count + st;

    int temp = arr[P];
    arr[P] = arr[st];
    arr[st] = temp;

    int i = st, j = en;
    while (i < P && j > P)
    {

        if (arr[i] < arr[P])
        {
            i++;
        }
        else if (arr[j] >= arr[P])
        {
            j--;
        }
        else
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    return P;
}

void quick(int arr[], int st, int en)
{
    if (st >= en)
    {
        return;
    }
    int c = partition(arr, st, en);
    quick(arr, st, c - 1);
    quick(arr, c + 1, en);
    return;
}

void quickSort(int arr[], int n)
{
    int st = 0, en = n - 1;
    quick(arr, st, en);
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

    quickSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}