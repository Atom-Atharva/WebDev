#include <iostream>
using namespace std;

void merge(int *arr, int n, int st, int en, int mid)
{
    int i = st, j = mid + 1;
    int k = 0;
    int *temp = new int[n];

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
        for (; k < n; k++, i++)
        {
            temp[k] = arr[i];
        }
    }
    if (j <= en)
    {
        for (; k < n; k++, j++)
        {
            temp[k] = arr[j];
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

int pairSum(int arr[], int n, int num)
{
    sort(arr, 0, n - 1);
    int ans = 0;
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] > num)
        {
            j--;
        }
        else if (arr[i] + arr[j] < num)
        {
            i++;
        }
        else
        {
            int elementAtStart = arr[i];
            int elementAtEnd = arr[j];
            if (elementAtStart == elementAtEnd)
            {
                int totalElementFormStartToEnd = (j - i) + 1;
                ans = ans + (totalElementFormStartToEnd * (totalElementFormStartToEnd - 1) / 2);
                return ans;
            }

            int tempstart = i + 1;
            int tempend = j - 1;
            while (tempstart <= tempend && arr[tempstart] == elementAtStart)
            {
                tempstart += 1;
            }
            while (tempend >= tempstart && arr[tempend] == elementAtEnd)
            {
                tempend -= 1;
            }
            int totaElementFromStart = tempstart - i;
            int totalElementFromEnd = j - tempend;

            ans = ans + (totaElementFromStart * totalElementFromEnd);
            i = tempstart;
            j = tempend;
        }
    }
    return ans;
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

    cout << pairSum(arr, n, x) << endl;

    delete[] arr;
    return 0;
}
