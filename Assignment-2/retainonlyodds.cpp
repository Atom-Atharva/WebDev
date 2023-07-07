// P14. Given a stack, write a function to retain only the elements in the odd position of
// the stack and pop out all even positioned elements.
// Example:
// Stack S top
// a b c d e f
// Output Stack S top
// a c e

#include <iostream>
using namespace std;
#include "StackUsingLL.h"

void retainOdds(StackUsingLL<int> *s)
{
    int size = s->getSize();
    StackUsingLL<int> *helper = new StackUsingLL<int>();
    int i = 1;
    while (i <= size)
    {
        if (i % 2 == 0)
        {
            s->pop();
        }
        else
        {
            helper->push(s->pop());
        }
        i++;
    }
    while (!helper->isEmpty())
    {
        s->push(helper->pop());
    }
    return;
}

int main()
{
    int n;
    cin >> n;

    StackUsingLL<int> *s = new StackUsingLL<int>();
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        s->push(element);
    }

    retainOdds(s);

    while (!s->isEmpty())
    {
        cout << s->pop() << " ";
    }
    cout << endl;

    return 0;
}