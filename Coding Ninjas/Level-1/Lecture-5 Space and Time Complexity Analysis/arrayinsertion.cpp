#include <iostream>
using namespace std;

// Long Method-

// void intersection(int *arr1, int *arr2, int n, int m)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (arr1[i] == arr2[j])
//             {
//                 arr2[j]=1000000;
//                 cout << arr1[i] << " ";
//                 break;
//             }
//         }
//     }
//     return;
// }

// Short Method-

void merge(int *arr, int size, int st, int en, int mid)
{
    int i = st, j = mid + 1;
    int *temp = new int[size];
    int k = 0;
    for (; i <= mid && j <= en; k++)
    {
        if (arr[i] < arr[j])
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
        for (; k < size; k++)
        {
            temp[k] = arr[i];
            i++;
        }
    }
    if (j <= en)
    {
        for (; k < size; k++)
        {
            temp[k] = arr[j];
            j++;
        }
    }
    for (int l = 0, m = st; l < size; l++, m++)
    {
        arr[m] = temp[l];
    }
    delete[] temp;
    return;
}

void sort(int *arr, int st, int en)
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

void intersection(int *arr1, int *arr2, int n, int m)
{

    sort(arr1, 0, n - 1);
    sort(arr2, 0, m - 1);

    for (int i = 0, j = 0; i < n && j < m;)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
            continue;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
            continue;
        }
        else if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int arr1[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int arr2[100];
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    intersection(arr1, arr2, n, m);

    return 0;
}