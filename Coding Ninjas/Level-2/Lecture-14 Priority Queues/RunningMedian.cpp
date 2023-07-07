#include <iostream>
using namespace std;
#include <queue>

void findMedian(int arr[], int n)
{
    if (n == 0)
    {
        return;
    }
    priority_queue<int> maxQueue;
    priority_queue<int, vector<int>, greater<int>> minQueue;

    maxQueue.push(arr[0]);
    cout << maxQueue.top() << " ";

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxQueue.top())
        {
            minQueue.push(arr[i]);
        }
        else
        {
            maxQueue.push(arr[i]);
        }

        if (maxQueue.size() - minQueue.size() == 2)
        {
            minQueue.push(maxQueue.top());
            maxQueue.pop();
        }
        else if (minQueue.size() - maxQueue.size() == 2)
        {
            maxQueue.push(minQueue.top());
            minQueue.pop();
        }

        if (maxQueue.size() == minQueue.size())
        {
            cout << (maxQueue.top() + minQueue.top()) / 2 << " ";
        }
        else
        {
            if (maxQueue.size() > minQueue.size())
            {
                cout << maxQueue.top() << " ";
            }
            else
            {
                cout << minQueue.top() << " ";
            }
        }
    }
    cout << endl;
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

    findMedian(arr, n);

    return 0;
}