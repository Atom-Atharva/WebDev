#include <iostream>
using namespace std;

int arrayRotateCheck(int *arr, int n)
{
    int k = 1;
    for (int i = 1; i < n; i++, k++)
    {
        if (arr[i] < arr[i - 1])
        {
            return k;
        }
    }
    return 0;
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

    int ans = arrayRotateCheck(arr, n);
    cout << ans << endl;

    return 0;
}