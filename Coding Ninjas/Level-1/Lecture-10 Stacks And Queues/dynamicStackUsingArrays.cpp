#include <iostream>
#include <climits>
using namespace std;

class StackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    // Size of Array is Dynamic and it is not fix--
    StackUsingArray()
    {
        nextIndex = 0;
        data = new int[4];
        capacity = 4;
    }

    // SIZE OF ARRAY TILL NOW
    int size()
    {
        return nextIndex;
    }

    // Check Array is EMPTY OR NOT
    bool isEmpty()
    {
        /*
        if (nextIndex == 0)
        {
            return true;
        }
        else
        {
            return false;
        }*/

        // Agar nextIndex==0 hai toh true, else false.
        return nextIndex == 0;
    }

    // Insert An ELEMENT
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            // cout << "Stack Is FULL\n";
            // return;
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity = capacity * 2;
            delete[] data;
            data = newData;
        }

        data[nextIndex] = element;
        nextIndex++;
        return;
    }

    // To DELETE the ELEMENT
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    // TO ACCESS the TOP ELEMENT
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};

int main()
{
    StackUsingArray s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.size() << endl;

    cout << s.isEmpty() << endl;
}