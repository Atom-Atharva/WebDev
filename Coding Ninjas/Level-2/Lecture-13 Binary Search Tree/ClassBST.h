#include "BinaryTreeNode.h"
#include <iostream>
using namespace std;

class BST
{
public:
    BinaryTreeNode<int> *root;

    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    // Helper Function which takes a node and do the task privately declared and only be called by public functions
    // Example of Function Overloading
    bool hasData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }
        else if (node->data > data)
        {
            return hasData(data, node->left);
        }
        else
        {
            return hasData(data, node->right);
        }
    }

    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (node->data >= data)
        {
            node->left = insert(data, node->left);
            return node;
        }
        node->right = insert(data, node->right);
        return node;
    }

    void print(BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->data << ":";
        if (node->left != NULL)
        {
            cout << "L:" << node->left->data << ",";
        }
        if (node->right != NULL)
        {
            cout << "R:" << node->right->data;
        }
        cout << endl;

        print(node->left);
        print(node->right);
    }

    BinaryTreeNode<int> *remove(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (node->data > data)
        {
            node->left = remove(data, node->left);
            return node;
        }
        else if (node->data < data)
        {
            node->right = remove(data, node->right);
            return node;
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode<int> *temp = node->left;
                delete node;
                return temp;
            }
            else if (node->left == NULL)
            {
                BinaryTreeNode<int> *temp = node->right;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = node->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = remove(rightMin, node->right);
                return node;
            }
        }
    }

public:
    bool search(int data)
    {
        return hasData(data, root);
    }

    void insert(int data)
    {
        root = insert(data, root);
        return;
    }

    void print()
    {
        print(root);
        return;
    }

    void remove(int data)
    {
        root = remove(data, root);
        return;
    }
};