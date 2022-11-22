#include <iostream>
using namespace std;
#include <queue>

int buyTicket(int *arr, int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    int time = 1;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        q.push(i);
    }

    while (!q.empty())
    {
        if (arr[q.front()] == pq.top())
        {
            if (q.front() == k)
            {
                return time;
            }
            else
            {
                time++;
                q.pop();
                pq.pop();
            }
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }
    return -1;
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

    int index;
    cin >> index;

    cout << buyTicket(arr, n, index);

    return 0;
}