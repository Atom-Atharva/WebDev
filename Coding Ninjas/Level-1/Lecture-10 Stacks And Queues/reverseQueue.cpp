#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &input)
{
    // BASE CASE--
    if (input.size() == 1 || input.size() == 0)
    {
        return;
    }

    // RECURSION CALL--
    int data = input.front();
    input.pop();
    reverseQueue(input);

    // SMALL CALCULATIONS--
    input.push(data);
    return;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++)
        {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}