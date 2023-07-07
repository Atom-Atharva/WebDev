#include <iostream>
using namespace std;

int findSubSets(int *arr, int n, int k, int st)
{
    if (st == n)
    {
        if (k == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int count = 0;
    if (k - arr[st] >= 0)
    {
        count = count + findSubSets(arr, n, k - arr[st], st + 1);
    }
    count = count + findSubSets(arr, n, k, st + 1);
    return count;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int ans = findSubSets(arr, n, k, 0);
        cout << ans << endl;
    }

    return 0;
}