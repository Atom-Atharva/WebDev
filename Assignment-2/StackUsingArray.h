// P11.. Write a program to implement a stack with push, pop, peek and getLength
// operations. Use an array as the container of stack elements.

#include <iostream>
#include <climits>
using namespace std;

class StackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray(int totalSize)
    {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
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
            cout << "Stack Is FULL\n";
            return;
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
