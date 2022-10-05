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

int length(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int ans = length(head->next);
    return ans + 1;
}

Node *bubbleSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    int len = length(head);
    for (int i = 0; i < len; i++)
    {
        Node *prev = NULL;
        Node *curr = head;
        // Node *nxt = head->next;

        for (int j = 0; j < len - i - 1; j++)
        {
            if (curr->data > curr->next->data)
            {
                if (prev == NULL)
                {
                    head = curr->next;
                    curr->next = head->next;
                    head->next = curr;
                    prev = head;

                    // head = nxt;
                    // curr->next = nxt->next;
                    // nxt->next = curr;
                }
                else
                {
                    Node *temp = curr->next->next;
                    curr->next->next = curr;
                    prev->next = curr->next;
                    curr->next = temp;
                    prev = prev->next;

                    // prev->next = nxt;
                    // curr->next = nxt->next;
                    // nxt->next = curr;
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;

            }
        }
    }
    return head;
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
    Node *head = takeinput();
    head = bubbleSort(head);
    print(head);
}