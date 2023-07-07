// P21. Write a program to implement Queue using Stack data structure.

#include <iostream>
using namespace std;
#include <stack>

class Queue
{
    stack<int> s;
    stack<int> t;

public:
    void enqueue(int x)
    {
        s.push(x);
        return;
    }

    int dequeue()
    {
        if (s.empty())
        {
            cout << "Queue Empty\n";
            return -1;
        }

        while (!s.empty())
        {
            t.push(s.top());
            s.pop();
        }

        int ans = t.top();
        t.pop();

        while (!t.empty())
        {
            s.push(t.top());
            t.pop();
        }
        return ans;
    }
};