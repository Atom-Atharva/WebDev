#include <iostream>
using namespace std;

// Class of NODE LINKLIST

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

// Find Node in LL

int findNode(Node *head, int n)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->data == n)
    {
        return 0;
    }
    int ans = findNode(head->next, n);
    if (ans == -1)
    {
        return -1;
    }
    return ans + 1;
}

// Append Last N to First

Node *appendLastNToFirst(Node *head, int n)
{
    if (head == NULL || n == 0)
    {
        return head;
    }

    Node *temp = head;
    Node *pos = head;

    int len = length(head);
    n = len - n;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;

    int i = 1;
    while (i < n)
    {
        pos = pos->next;
        i++;
    }
    head = pos->next;
    pos->next = NULL;
    return head;
}

// Remove Dublicate LL
Node *removeDublicates(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *diff = head;
    Node *temp = head->next;
    while (temp != NULL)
    {
        if (temp->data == diff->data)
        {
            diff->next = temp->next;
            Node *t = temp;
            temp = temp->next;
            delete t;
        }
        else
        {
            diff = temp;
            temp = temp->next;
        }
    }
    return head;
}

// Print Reverse LL
void printReverse(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        cout << head->data << " ";
        return;
    }
    printReverse(head->next);
    cout << head->data << " ";
    return;
}

// Palindrome LL

Node *reverseLL(Node *head)
{
    Node *curr = head;
    Node *first = NULL;
    Node *last = NULL;

    while (curr != NULL)
    {
        first = curr->next;
        curr->next = last;
        last = curr;
        curr = first;
    }
    return last;
}

bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return 1;
    }
    // FIND THE MIDDLE

    Node *fast = head;
    Node *slow = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *secondhead = slow->next;
    slow->next = NULL;
    secondhead = reverseLL(secondhead);

    // COMPARE THE TWO PARTS

    Node *firstsubhead = head;
    Node *secondsubhead = secondhead;

    bool ans = 1;
    while (secondsubhead != NULL)
    {
        if (firstsubhead->data != secondsubhead->data)
        {
            ans = 0;
            break;
        }
        firstsubhead = firstsubhead->next;
        secondsubhead = secondsubhead->next;
    }

    // REJOIN THE TWO PARTS

    firstsubhead = head;
    secondsubhead = reverseLL(secondhead);

    while (firstsubhead->next != NULL)
    {
        firstsubhead = firstsubhead->next;
    }
    firstsubhead->next = secondsubhead;

    return ans;
}

// Print all ELEMENTS of NODE

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

// Insert Ith ELEMENT in NODE

Node *insertionIthElement(Node *head, int i, int data)
{
    Node *newNode = new Node(data);
    Node *temp = head;

    int count = 0;
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    while (count < i - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        Node *tempp = temp->next;
        temp = newNode;
        newNode->next = tempp;
    }
    return head;
}

// Delete Node at Ith Position
Node *deleteNode(Node *head, int pos)
{
    if (head == NULL)
    {
        return head;
    }
    if (pos == 0)
    {
        Node *a = head;
        head = head->next;
        delete a;
        return head;
    }
    Node *temp = head;
    int count = 0;
    while (count < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL && temp->next != NULL)
    {
        Node *a = temp->next;
        Node *b = a->next;
        temp->next = b;
        delete a;
    }
    return head;
}

// Length of LL(RECURSIVELY)

int length(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int ans = length(head->next);
    return ans + 1;
}

// Insert Node (RECURSIVELY)

Node *insertNode(Node *head, int i, int data)
{
    if (head == NULL)
    {
        return head;
    }
    if (i == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node *x = insertNode(head->next, i - 1, data);
    head->next = x;
    return head;
}

// Delete Node (RECURSIVELY)

Node *deleteNodeRec(Node *head, int i)
{
    if (head == NULL)
    {
        return head;
    }
    if (i == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *x = deleteNodeRec(head->next, i - 1);
    head->next = x;
    return head;
}

// Print Ith NODE

void printIthNode(Node *head, int i)
{
    Node *temp = head;
    while (i-- && temp != NULL)
    {
        temp = temp->next;
    }
    if (temp != NULL)
        cout << temp->data;
    return;
}

// Calculate Length of NODE

int length(Node *head)
{
    Node *temp = head;
    int ans = 0;
    while (temp != NULL)
    {
        ans++;
        temp = temp->next;
    }
    return ans;
}

// Taking input of NODE

Node *takeInput()
{
    int data;
    cin >> data;

    Node *head = NULL; // Store ADDRESS OF FIRST ELEMENT
    Node *tail = NULL; // Store ADDRESS OF LAST ELEMENT
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }

        // FINDING OUT LAST ELEMENT;

        /*else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }*/

        else
        {
            tail->next = newNode;
            tail = tail->next;
        }

        cin >> data;
    }
    return head;
}

int main()
{

    return 0;
}