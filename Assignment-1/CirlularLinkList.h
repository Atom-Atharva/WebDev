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

class CirlularLL{
    Node* head,*tail;
    int size;

    CirlularLL(){
        head=NULL;
        tail=NULL;
        size=0;
    }

    void addbeg(int data){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;

            
        }
    }
};