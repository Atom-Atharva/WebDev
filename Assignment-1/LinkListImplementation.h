// P1.. Write a program to implement a link list with following operations :
// void addbeg (int data)
// void addatend ( int data)
// int removefront ()
// int removelast()
// int getlenght()
// void addatpos(int data , int pos) // 0 <pos <= length of link list
// void addatmiddle(int data)
// int removepos(int pos) // 0< pos <= length of link list

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
    Node *head, *tail;
    int size;

public:
    LinkList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getlength()
    {
        return size;
    }

    void addbeg(int data)
    {
        Node *newNode = new Node(data);
        if (tail == NULL)
        {
            head = newNode;
            tail = newNode;
            size++;
            return;
        }
        newNode->next = head;
        head = newNode;
        size++;
        return;
    }

    void addatend(int data)
    {
        Node *newNode = new Node(data);
        if (tail == NULL)
        {
            head = newNode;
            tail = newNode;
            size++;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        size++;
        return;
    }

    int removefront()
    {
        if (size == 0)
        {
            cout << "List Empty!" << endl;
            return -1; // Denotes the Link List is Empty!
        }
        Node *front = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        int ans = front->data;
        delete front;
        size--;
        return ans;
    }

    int removelast()
    {
        if (size == 0)
        {
            cout << "List Empty!" << endl;
            return -1;
        }
        if (size == 1)
        {
            int ans = head->data;
            delete head;
            head = NULL;
            tail = NULL;
            size--;
            return ans;
        }
        Node *last = tail;
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        tail = temp;
        int ans = last->data;
        delete last;
        size--;
        return ans;
    }

    void addatpos(int data, int pos)
    {
        if (pos == 1)
        {
            addbeg(data);
            return;
        }
        Node *newNode = new Node(data);
        int i = 1;
        Node *temp = head;
        while (i < pos || temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
        return;
    }

    void addatmiddle(int data)
    {
        if (head == NULL || size == 1)
        {
            addbeg(data);
            return;
        }
        Node *newNode = new Node(data);
        int mid = (size + 1) / 2;
        Node *temp = head;
        for (int i = 1; i < mid; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
        return;
    }

    int removepos(int pos)
    {
        if (head == NULL)
        {
            cout << "List Empty!" << endl;
            return -1;
        }
        if (pos == 1)
        {
            return removefront();
        }
        Node *temp = head;
        for (int i = 1; i < pos || temp->next != NULL; i++)
        {
            temp = temp->next;
        }
        Node *store = temp->next;
        temp->next = store->next;
        if (store->next == NULL)
        {
            tail = temp;
        }
        int ans = store->data;
        delete store;
        size--;
        return ans;
    }
};