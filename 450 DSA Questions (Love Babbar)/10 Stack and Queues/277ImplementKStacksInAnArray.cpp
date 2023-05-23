// https://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/

// How to efficiently implement k stacks in a single array?

#include <iostream>
using namespace std;

class kStacks
{
    int *arr;
    int size;
    int k;
    int *ksize;

public:
    kStacks(int n, int k)
    {
        size = n;
        arr = new int[n];
        this->k = k;

        // Stores Top of each stack--
        ksize = new int[k];

        int j = 0;
        for (int i = 0; i < k; i++)
        {
            j = i * (size / k);
            ksize[i] = j - 1;
        }
    }

    void push(int x, int sn);
    int pop(int sn);
};

// Function to push an integer into the stack.
void kStacks ::push(int x, int sn)
{
    // Find the top of sn stack--
    int top = ksize[sn - 1];
    top++;

    // Check if Stack full?
    if (top == (size / k) * sn)
    {
        cout << "Full Stack!" << endl;
        return;
    }

    arr[top] = x;
    ksize[sn - 1] = top;

    return;
}

// Function to remove an element from top of the stack.
int kStacks ::pop(int sn)
{
    // Find the top of sn stack;
    int top = ksize[sn - 1];

    // Check if stack is empty?
    if (top == ((size / k) * (sn - 1)) - 1)
    {
        return -1; // Stack Empty!
    }

    int element = arr[top];
    top--;
    ksize[sn - 1] = top;

    return element;
}

int main()
{
    kStacks s(100, 2);
    s.push(1, 1);
    s.push(1, 2);
    s.push(2, 1);
    s.push(2, 2);
    s.push(3, 1);
    s.push(3, 2);
    s.push(4, 1);

    cout << s.pop(1) << endl;
    cout << s.pop(1) << endl;
    cout << s.pop(1) << endl;
    cout << s.pop(1) << endl;
    cout << s.pop(1) << endl;

    cout << s.pop(2) << endl;
    cout << s.pop(2) << endl;
    cout << s.pop(2) << endl;
    cout << s.pop(2) << endl;

    return 0;
}