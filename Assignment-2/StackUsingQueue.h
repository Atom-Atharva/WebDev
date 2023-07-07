// P20. Write a program to implement Stack using Queue data structure.

#include <iostream>
using namespace std;
#include <queue>

class Stack
{
    queue<int> q;

public:
    void push(int x)
    {
        q.push(x);
        return;
    }

    int pop()
    {
        if (q.empty())
        {
            cout << "Stack Empty!" << endl;
            return -1;
        }
        int len = q.size();
        for (int i = 1; i < len; i++)
        {
            q.push(q.front());
            q.pop();
        }
        int ans = q.front();
        q.pop();
        return ans;
    }
};
