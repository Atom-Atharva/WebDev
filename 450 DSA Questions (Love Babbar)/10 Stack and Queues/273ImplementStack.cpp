// https://www.tutorialspoint.com/javaexamples/data_stack.htm

// How to implement stack?

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

class Stack
{
    vector<int> arr;

public:
    void push(int element)
    {
        arr.push_back(element);
        return;
    }

    int top()
    {
        if (arr.size() == 0)
        {
            return INT_MIN;
        }
        return arr[arr.size() - 1];
    }

    int pop()
    {
        if (arr.size() == 0)
        {
            return INT_MIN;
        }
        int element = arr[arr.size() - 1];
        arr.pop_back();
        return element;
    }
};

int main()
{
    Stack s;
    s.push(1);
    cout << s.top() << endl;
    s.push(2);
    s.push(3);

    s.pop();
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    return 0;
}