#include <iostream>
using namespace std;
#include <queue>

int main()
{

    // TO CREATE MAX PRIORITY QUEUE--
    priority_queue<int> pq;

    // To Create MIN PRIORITY QUEUE--
    // priority_queue<int,vector<int>,greater<int>> pq;

    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);
    pq.push(6);

    cout << pq.size() << endl;
    cout << pq.top() << endl;

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}