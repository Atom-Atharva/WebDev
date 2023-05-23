// https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/

// Design a stack with operations on middle element
// How to implement a stack which will support the following operations in O(1) time complexity?
// 1) push() which adds an element to the top of stack.
// 2) pop() which removes an element from top of stack.
// 3) findMiddle() which will return middle element of the stack.
// 4) deleteMiddle() which will delete the middle element.
// Push and pop are standard stack operations.

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

    int findMiddle()
    {
        int len = arr.size();
        Stack s;

        // Push elements till middle in new stack s--
        for (int i = 0; i < ((len - 1) / 2); i++)
        {
            s.push(this->pop());
        }

        // Store middle element--
        int element = this->top();

        // Push elements again in main stack--
        for (int i = 0; i < ((len - 1) / 2); i++)
        {
            this->push(s.pop());
        }

        return element;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    cout << s.findMiddle() << endl;
    return 0;
}