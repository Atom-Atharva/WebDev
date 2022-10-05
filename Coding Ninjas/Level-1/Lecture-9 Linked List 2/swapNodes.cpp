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

Node *swapNodes(Node *head, int i, int j)
{
    if (i == j)
    {
        return head;
    }
    if (i > j)
    {
        int temp = i;
        i = j;
        j = temp;
    }
    if (i == 0)
    {
        if (j == 1)
        {
            Node *temp = head;
            head = head->next;
            temp->next = head->next;
            head->next = temp;
        }
        else
        {
            Node *curr1 = head;
            Node *curr2 = head;
            Node *prev2 = NULL;

            int pos = 0;
            while (pos < j)
            {
                pos++;
                prev2 = curr2;
                curr2 = curr2->next;
            }
            prev2->next = curr1;
            head = curr2;
            Node *temp = head->next;
            curr2->next = curr1->next;
            curr1->next = temp;
        }
        return head;
    }

    if ((j - i) == 1)
    {
        Node *curr1 = head;
        Node *curr2 = head;
        Node *prev1 = head;

        int pos = 0;
        while (pos < i)
        {
            pos++;
            prev1 = curr1;
            curr1 = curr1->next;
        }
        curr2 = curr1->next;

        prev1->next = curr2;
        curr1->next = curr2->next;
        curr2->next = curr1;

        return head;
    }

    Node *curr1 = head;
    Node *curr2 = head;
    Node *prev1 = head;
    Node *prev2 = head;

    int pos = 0;
    while (pos < i)
    {
        pos++;
        prev1 = curr1;
        curr1 = curr1->next;
    }
    pos = 0;
    while (pos < j)
    {
        pos++;
        prev2 = curr2;
        curr2 = curr2->next;
    }
    prev2->next = curr1;
    prev1->next = curr2;
    Node *temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;

    return head;

    // if (head == NULL || head->next == NULL)
    // {
    //     return head;
    // }
    // if (i == j)
    // {
    //     return head;
    // }

    // if ((i == 0 || j == 0) && abs(i - j) == 1)
    // {
    //     Node *c1 = head;
    //     Node *c2 = head->next;

    //     head = head->next;
    //     c1->next = c2->next;
    //     c2->next = c1;
    //     return head;
    // }

    // if (i == 0 || j == 0)
    // {
    //     Node *c1 = head;
    //     Node *c2 = head;
    //     Node *f1 = head->next;
    //     Node *p2 = head;
    //     int sec = 0;

    //     if (j == 0)
    //     {
    //         int temp = i;
    //         i = j;
    //         j = temp;
    //     }

    //     while (sec < j)
    //     {
    //         sec++;
    //         p2 = c2;
    //         c2 = c2->next;
    //     }
    //     head = c2;
    //     p2->next = c1;
    //     c1->next = c2->next;
    //     c2->next = f1;
    //     return head;
    // }

    // if (abs(i - j) == 1)
    // {
    //     if (i > j)
    //     {
    //         int temp = i;
    //         i = j;
    //         j = temp;
    //     }
    //     Node *p1 = head;
    //     Node *c1 = head;
    //     Node *c2 = head;
    //     int fir = 0;

    //     while (fir < i)
    //     {
    //         fir++;
    //         p1 = c1;
    //         c1 = c1->next;
    //     }
    //     c2 = c1->next;

    //     p1->next = c2;
    //     c1->next = c2->next;
    //     c2->next = c1;
    //     return head;
    // }

    // if (i > j)
    // {
    //     int temp = i;
    //     i = j;
    //     j = temp;
    // }

    // Node *p1 = head;
    // Node *p2 = head;
    // Node *c1 = head;
    // Node *c2 = head;

    // int fir = 0, sec = 0;

    // while (fir < i)
    // {
    //     fir++;
    //     p1 = c1;
    //     c1 = c1->next;
    // }

    // while (sec < j)
    // {
    //     sec++;
    //     p2 = c2;
    //     c2 = c2->next;
    // }
    // p1->next = c2;
    // p2->next = c1;
    // c1->next = c2->next;
    // c2->next = p2;
    // return head;
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
        int i, j;
        Node *head = takeinput();
        cin >> i;
        cin >> j;
        head = swapNodes(head, i, j);
        print(head);
    }

    return 0;
}