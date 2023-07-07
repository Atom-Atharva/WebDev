#include <iostream>
#include "NodeClass.h"
using namespace std;

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}