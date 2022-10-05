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

Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *subhead = reverseLL(head->next);
    Node *tail = head->next;
    head->next = NULL;
    tail->next = head;

    return subhead;
}

Node *kReverse(Node *head, int k)
{
    if (k == 0 || head == NULL || head->next == NULL)
    {
        return head;
    }

    int count = 1;
    Node *h1 = head, *t1 = head;
    while (count < k && t1->next != NULL)
    {
        count++;
        t1 = t1->next;
    }
    Node *h2 = kReverse(t1->next, k);
    t1->next = NULL;
    Node *newhead = reverseLL(h1);
    t1 = h1;
    t1->next = h2;
    return newhead;
}

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        int k;
        cin >> k;
        head = kReverse(head, k);
        print(head);
    }

    return 0;
}