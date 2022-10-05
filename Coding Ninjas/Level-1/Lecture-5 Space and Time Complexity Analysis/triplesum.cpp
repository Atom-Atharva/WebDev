#include <iostream>
using namespace std;

void merge(int *arr, int n, int st, int en, int mid)
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

void sort(int *arr, int st, int en)
{
    if (st >= en)
    {
        return;
    }
    int mid = (st + en) / 2;
    sort(arr, st, mid);
    sort(arr, mid + 1, en);

    return merge(arr, en - st + 1, st, en, mid);
}

int pairSum(int *arr, int st, int en, int smallnum)
{
    int ans = 0;
    while (st < en)
    {
        if (arr[st] + arr[en] > smallnum)
        {
            en--;
        }
        else if (arr[st] + arr[en] < smallnum)
        {
            st++;
        }
        else
        {
            int elementAtStart = arr[st];
            int elementAtEnd = arr[en];
            if (elementAtStart == elementAtEnd)
            {
                int totalElementFormStartToEnd = (en - st) + 1;
                ans = ans + (totalElementFormStartToEnd * (totalElementFormStartToEnd - 1) / 2);
                return ans;
            }

            int tempstart = st + 1;
            int tempend = en - 1;
            while (tempstart <= tempend && arr[tempstart] == elementAtStart)
            {
                tempstart += 1;
            }
            while (tempend >= tempstart && arr[tempend] == elementAtEnd)
            {
                tempend -= 1;
            }
            int totaElementFromStart = tempstart - st;
            int totalElementFromEnd = en - tempend;

            ans = ans + (totaElementFromStart * totalElementFromEnd);
            st = tempstart;
            en = tempend;
        }
    }
    return ans;
}

int tripleSum(int *arr, int n, int num)
{
    sort(arr, 0, n - 1);
    int triplenum = 0;

    for (int i = 0; i < n; i++)
    {
        int smallnum = num - arr[i];
        int pairnum = pairSum(arr, i + 1, n - 1, smallnum);
        triplenum += pairnum;
    }
    return triplenum;
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

    int num;
    cin >> num;

    cout << tripleSum(arr, n, num) << endl;

    delete[] arr;

    return 0;
}