#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra)
{
    // BASE CASE--
    if (input.size() == 1 || input.size() == 0)
    {
        return;
    }

    // RECURSION CALL--
    int ans = input.top();
    input.pop();

    reverseStack(input, extra);

    // SMALL CALCULATION--

    // MOVING TO EXTRA--
    while (!input.empty())
    {
        int out = input.top();
        extra.push(out);
        input.pop();
    }

    // INSERT TOP ELEMENT IN INPUT--
    input.push(ans);

    // MOVING TO INSERT--
    while (!extra.empty())
    {
        int out = extra.top();
        input.push(out);
        extra.pop();
    }

    return;
}

int main()
{
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++)
    {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty())
    {
        cout << input.top() << " ";
        input.pop();
    }
}