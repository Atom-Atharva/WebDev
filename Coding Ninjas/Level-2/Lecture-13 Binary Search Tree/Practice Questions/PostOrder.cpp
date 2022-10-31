#include <iostream>
#include "NodeClass.h"
using namespace std;

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
    return;
}