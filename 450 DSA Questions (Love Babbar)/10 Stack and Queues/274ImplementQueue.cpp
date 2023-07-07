// https://www.geeksforgeeks.org/introduction-and-array-implementation-of-queue/

// Implement a Queue using an Array. Queries in the Queue are of the following type:
// (i) 1 x   (a query of this type means  pushing 'x' into the queue)
// (ii) 2     (a query of this type means to pop element from queue and print the poped element)

#include <iostream>
using namespace std;

// The structure of the class is
class MyQueue
{
private:
    int arr[100005];
    int front;
    int rear;

public:
    MyQueue()
    {
        front = 0;
        rear = 0;
    }
    void push(int);
    int pop();
};

// Function to push an element x in a queue.
void MyQueue ::push(int x)
{
    arr[rear++] = x;
    return;
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop()
{
    if (front == rear)
    {
        return -1;
    }
    return arr[front++];
}

int main()
{
    MyQueue que;
    que.push(1);
    que.push(2);
    cout << que.pop() << endl;
    que.push(3);
    cout << que.pop() << endl;
    que.push(4);
    cout << que.pop() << endl;
    cout << que.pop() << endl;
    cout << que.pop() << endl;

    return 0;
}