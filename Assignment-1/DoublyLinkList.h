// P3. Write a program to implement a doubly link list with following operations :
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
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLL
{
    Node *head, *tail;
    int size;

public:
    DoublyLL()
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
            newNode = head;
            newNode = tail;
            size++;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        size++;
        return;
    }

    void addatlast(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            newNode = head;
            newNode = tail;
            size++;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        size++;
        return;
    }

    int removefront()
    {
        if (head == NULL)
        {
            cout << "List Empty!" << endl;
            return -1; // Denotes List is Empty!
        }
        int ans = head->data;
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        size--;
        return ans;
    }

    int removelast()
    {
        if (head == NULL)
        {
            cout << "List Empty!" << endl;
            return -1; // Denotes List is Empty!
        }
        int ans = tail->data;
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
        size--;
        return ans;
    }

    int getlength()
    {
        return size;
    }

    void addatpos(int data, int pos)
    {
        if (pos == 1)
        {
            addbeg(data);
            return;
        }
        Node *temp = head;
        Node *newNode = new Node(data);
        for (int i = 1; i < pos || temp->next != NULL; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
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
        int mid = (size + 1) / 2;
        Node *temp = head;
        Node *newNode = new Node(data);
        for (int i = 1; i < mid; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
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
        if (store == tail)
        {
            tail = tail->prev;
        }
        int ans = store->data;
        temp->next = store->next;
        store->next->prev = temp;
        delete store;
        size--;
        return ans;
    }
};