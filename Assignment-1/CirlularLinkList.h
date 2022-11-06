// P5. Write a program to implement a circular single link list with following operations :
// void addbeg (int data)
// void addatend ( int data)
// int removefront ()
// int removelast()
// int getlenght()
// void addatmiddle(int data)

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

class CirlularLL
{
    Node *head, *tail;
    int size;

public:
    CirlularLL()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void addbeg(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
            size++;
            return;
        }
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
        size++;
        return;
    }

    void addatend(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
            size++;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
        size++;
        return;
    }

    int removefront()
    {
        if (head == NULL)
        {
            cout << "List Empty!";
            return -1; // Denotes List is Empty.
        }
        if (size == 1)
        {
            size--;
            int ans = head->data;
            delete head;
            head = NULL;
            tail = NULL;
            return ans;
        }
        size--;
        int ans = head->data;
        head = head->next;
        Node *temp = tail->next;
        delete temp;
        tail->next = head;
        return ans;
    }

    int removelast()
    {
        if (head == NULL)
        {
            cout << "List Empty!";
            return -1; // Denotes List is Empty.
        }
        if (size == 1)
        {
            size--;
            int ans = head->data;
            delete head;
            head = NULL;
            tail = NULL;
            return ans;
        }
        size--;
        int ans = tail->data;
        Node *temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        temp->next = head;
        delete tail;
        tail = temp;
        return ans;
    }

    int getlength()
    {
        return size;
    }

    void addatmiddle(int data)
    {
        if (size == 1 || size == 0)
        {
            addbeg(data);
        }
        int middle = (size + 1) / 2;
        Node *newNode = new Node(data);
        Node *temp = head;
        for (int i = 1; i < middle; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
        return;
    }
};