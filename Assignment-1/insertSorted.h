// P2. Write a function to insert a new node (with given data value) in a sorted position of a
// sorted link list.
// void insertatsorted(int data)

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

class LinkList
{
    Node *head;

public:
    LinkList()
    {
        head = NULL;
    }

    void insertatsorted(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        if (head->data > data)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next->data <= data || temp->next != NULL)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        return;
    }
};