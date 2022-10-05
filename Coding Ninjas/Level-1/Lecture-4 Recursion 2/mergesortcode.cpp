#include <iostream>
using namespace std;

void merge(int arr[], int n, int st, int en, int mid)
{
    int i = st, j = mid + 1;
    int *temp = new int[n];
    int k = 0;
    for (; i <= mid && j <= en; k++)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            continue;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            continue;
        }
    }
    if (i <= mid)
    {
        for (; k < n; k++)
        {
            temp[k] = arr[i];
            i++;
        }
    }
    if (j <= en)
    {
        for (; k < n; k++)
        {
            temp[k] = arr[j];
            j++;
        }
    }

    for (int l = 0, m = st; l < n; l++, m++)
    {
        arr[m] = temp[l];
    }
    delete[] temp;
    return;
}

void sort(int arr[], int st, int en)
{
    if (st >= en)
    {
        return;
    }
    int mid = (st + en) / 2;
    sort(arr, st, mid);
    sort(arr, mid + 1, en);
    return merge(arr, (en - st + 1), st, en, mid);
}

void mergeSort(int arr[], int n)
{
    int st = 0, en = n - 1;
    sort(arr, st, en);
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

    mergeSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}