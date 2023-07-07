#include <iostream>
using namespace std;
#include <queue>
#include <vector>

vector<int> kLargest(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    vector<int> ans;
    for (int i = k; i < n; i++)
    {
        pq.push(arr[i]);
        pq.pop();
    }

    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
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

    vector<int> ans = kLargest(arr, n, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}