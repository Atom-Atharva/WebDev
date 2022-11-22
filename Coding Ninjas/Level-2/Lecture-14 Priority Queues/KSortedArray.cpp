#include <iostream>
using namespace std;
#include <queue>

// Time Complexity = O(n)
void kSortedArray(int arr[], int n, int k)
{
    priority_queue<int> pq;

    // Time Complextiy = O(klogk)
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // Time Complexity = O((n-k)logk)
    int j = 0;
    for (int i = k; i < n; i++)
    {
        arr[j++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    // Time Complexity = O(klogk)
    while (!pq.empty())
    {
        arr[j++] = pq.top();
        pq.pop();
    }

    // Total Time Complexity = O((n+k)logk) == O(n)

    return;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    kSortedArray(arr, n, k);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}