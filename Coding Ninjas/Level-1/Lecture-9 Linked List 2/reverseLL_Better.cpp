#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

/*To decrease the Time Complexity of code we have created a tail pointer
The new Time Complexity of the code is O(n) */

class Pair
{
public:
    Node *head;
    Node *tail;
};

Pair reverseLL2(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallans = reverseLL2(head);

    smallans.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.tail = head;
    ans.head = smallans.head;
    return ans;
}

// As the maincode contains the return type as Node*
// so a converted function is created for required results

Node *reveseLL_Better(Node *head)
{
    return reverseLL2(head).head;
}

int main()
{
    return 0;
}