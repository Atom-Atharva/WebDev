// P10. Consider a link list having following node definition
// struct node {
// int rollno;
// char section;
// node *next;
// };
// Write link list implementation with void insert( int r , char s) which adds a new element
// (node) in the link list. New nodes should be placed in the link list in such a way that it
// contains nodes in ascending order of section value.

#include <iostream>
using namespace std;

struct Node
{
    int rollno;
    char section;
    Node *next;

    Node(int rollno, char section)
    {
        this->rollno = rollno;
        this->section = section;
        next = NULL;
    }
};

class LinkList
{
    Node *head, *tail;

public:
    LinkList()
    {
        head == NULL;
        tail == NULL;
    }

    void insert(int r, char s)
    {
        Node *newNode = new Node(r, s);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL || temp->next->section < s)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        return;
    }
};