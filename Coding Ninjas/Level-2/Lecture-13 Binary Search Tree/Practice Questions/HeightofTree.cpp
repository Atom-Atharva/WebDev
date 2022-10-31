#include <iostream>
#include "NodeClass.h"
using namespace std;

int height(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int leftH=height(root->left);
    int rightH=height(root->right);

    return (max(leftH,rightH) + 1);
}       