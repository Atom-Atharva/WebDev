#include <iostream>
#include "NodeClass.h"
using namespace std;

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
    return;
}