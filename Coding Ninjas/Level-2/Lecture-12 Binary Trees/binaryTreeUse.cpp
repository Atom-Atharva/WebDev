#include <iostream>
using namespace std;
#include "binaryTree.h"
#include <queue>

// Taking Input Level Wise--
BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter Root Data:" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter data for Left Child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }

        cout << "Enter data for Right Child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

// Taking Input Using Recursion--
BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Root Data:" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

// Print Tree Recursively--
void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data << " ";
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data << " ";
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
    return;
}

// Print Tree Level Wise--
void printTreeLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << front->data << ":";
        if (front->left != NULL)
        {
            pendingNodes.push(front->left);
            cout << "L" << front->left->data << " ";
        }
        if (front->right != NULL)
        {
            pendingNodes.push(front->right);
            cout << "R" << front->right->data << " ";
        }
        cout << endl;
    }
    return;
}

// Count Nodes in Binary Tree--
int countNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = 1;
    ans = ans + countNodes(root->left);
    ans = ans + countNodes(root->right);
    return ans;
}

// Finding a Node--
bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    bool ans = isNodePresent(root->left, x);
    if (ans == false)
    {
        ans = isNodePresent(root->right, x);
    }
    return ans;
}

// Height of Tree--
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = 1;
    ans = ans + max(height(root->left), height(root->right));
    return ans;
}

// Mirror the Binary Tree--
void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    BinaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
    return;
}

// Inorder Tree Traversal--
void inorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    return;
}

// Preorder Tree Traversal--
void preOrder(BinaryTreeNode<int> *root)
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

// PostOrder Tree Traversal--
void postOrder(BinaryTreeNode<int> *root)
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

// Construct Tree from PreOrder and Inorder--
BinaryTreeNode<int> *buildTreeHelper(int *preorder, int prestart, int preend, int *inorder, int instart, int inend)
{
    if (prestart > preend || instart > inend)
    {
        return NULL;
    }
    int rootData = preorder[prestart];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    int k;
    for (int i = instart; i <= inend; i++)
    {
        if (inorder[i] == rootData)
        {
            k = i;
            break;
        }
    }
    BinaryTreeNode<int> *leftChild = buildTreeHelper(preorder, prestart + 1, prestart + (k - instart), inorder, instart, k - 1);
    BinaryTreeNode<int> *rightChild = buildTreeHelper(preorder, prestart + (k - instart) + 1, preend, inorder, k + 1, inend);

    root->left = leftChild;
    root->right = rightChild;

    return root;
}
BinaryTreeNode<int> *buildTree(int *preorder, int preLenght, int *inorder, int inLength)
{
    int prestart = 0;
    int preend = preLenght - 1;
    int instart = 0;
    int inend = inLength - 1;
    return buildTreeHelper(preorder, prestart, preend, inorder, instart, inend);
}

// Construct Tree from PostOrder and InOrder--
BinaryTreeNode<int> *buildTreeHelper2(int *postorder, int pst, int pen, int *inorder, int ist, int ien)
{
    if (pst > pen)
    {
        return NULL;
    }
    int rootData = postorder[pen];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    int rootIndex = -1;
    for (int i = ist; i <= ien; i++)
    {
        if (rootData == inorder[i])
        {
            rootIndex = i;
            break;
        }
    }
    int lpst = pst;
    int rpen = pen - 1;
    int list = ist;
    int lien = rootIndex - 1;
    int rist = rootIndex + 1;
    int rien = ien;
    int lpen = lpst + lien - list;
    int rpst = lpen + 1;
    root->left = buildTreeHelper2(postorder, lpst, lpen, inorder, list, lien);
    root->right = buildTreeHelper2(postorder, rpst, rpen, inorder, rist, rien);
    return root;
}
BinaryTreeNode<int> *buildTree2(int *postorder, int postLength, int *inorder, int inLength)
{
    return buildTreeHelper2(postorder, 0, postLength - 1, inorder, 0, inLength - 1);
}

// Diameter of Tree-- Time Complexity=O(n*h)
// (h is height of the tree and n is no. of Nodes)
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = max(height(root->left), height(root->right));
    return ans + 1;
}
int diameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int option1 = 1 + height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}

// Diameter and Height-- Time Complexity=O(n)
// Using Pair Template pair<int,int> jab multiple cheeze ek saath chaiye hoti hai toh yeh use karte hai.
pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> ans;
        ans.first = 0;
        ans.second = 0;
        return ans;
    }

    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int ld = leftAns.second;
    int rd = rightAns.second;
    int lh = leftAns.first;
    int rh = leftAns.second;

    int height = 1 + max(lh, rh);
    int diameter = max(ld + rd, max(ld, rd));
    pair<int, int> ans;
    ans.first = height;
    ans.second = diameter;
    return ans;
}

// Min and Max Element In the Tree using Pair Template
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> ans;
        ans.first = 9999999;
        ans.second = -1;
        return ans;
    }
    pair<int, int> leftAns = getMinAndMax(root->left);
    pair<int, int> rightAns = getMinAndMax(root->right);
    int minimum = min(min(leftAns.first, rightAns.first), root->data);
    int maximum = max(max(leftAns.second, rightAns.second), root->data);
    pair<int, int> ans;
    ans.first = minimum;
    ans.second = maximum;
    return ans;
}

// Sum of All Nodes--
int getSum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = getSum(root->right) + getSum(root->left);
    return (root->data + ans);
}

// IsBalanced Tree--
int heightofTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lans = heightofTree(root->left);
    int rans = heightofTree(root->right);
    return 1 + max(lans, rans);
}
bool isBalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    int lh = heightofTree(root->left);
    int rh = heightofTree(root->right);
    if (abs(lh - rh) > 1)
    {
        return false;
    }
    bool lans = isBalanced(root->left);
    bool rans = isBalanced(root->right);
    if (lans == false || rans == false)
    {
        return false;
    }
    return true;
}

// Level Order Traversal--
//  a
//  b c
//  d e f g
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while (pendingNodes.size() != 0)
    {
        if (pendingNodes.size() == 1 && pendingNodes.front() == NULL)
        {
            break;
        }
        if (pendingNodes.front() == NULL)
        {
            cout << endl;
            pendingNodes.pop();
            pendingNodes.push(NULL);
        }
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if (front->left != NULL)
        {
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            pendingNodes.push(front->right);
        }
        cout << front->data << " ";
    }
    return;
}

// Remove Leaf Nodes--
BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return NULL;
    }
    BinaryTreeNode<int> *leftChild = removeLeafNodes(root->left);
    BinaryTreeNode<int> *rightChild = removeLeafNodes(root->right);
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

// Construct Level Wise LL--
#include "ConstructLevelWiseLL.h"
#include <vector>
vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
    vector<Node<int> *> ans;
    if (root == NULL)
    {
        ans.push_back(NULL);
        return ans;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    while (!pendingNodes.empty())
    {
        if (pendingNodes.size() == 1 && pendingNodes.front() == NULL)
        {
            ans.push_back(head);
            head = NULL;
            tail = NULL;
            break;
        }
        if (pendingNodes.front() == NULL)
        {
            pendingNodes.pop();
            pendingNodes.push(NULL);
            ans.push_back(head);
            head = NULL;
            tail = NULL;
        }
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if (front->left != NULL)
        {
            pendingNodes.push(front->left);
        }

        if (front->right != NULL)
        {
            pendingNodes.push(front->right);
        }

        Node<int> *newNode = new Node<int>(front->data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return ans;
}

// ZigZag Tree--
#include <stack>
void zigZagOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<BinaryTreeNode<int> *> ltr; // Left to Right Stack
    stack<BinaryTreeNode<int> *> rtl; // Right to Left Stack
    rtl.push(root);
    bool flag = false;

    while (rtl.size() != 0 || ltr.size() != 0)
    {
        if (flag)
        {
            BinaryTreeNode<int> *top = ltr.top();
            ltr.pop();
            if (top->right != NULL)
            {
                rtl.push(top->right);
            }
            if (top->left != NULL)
            {
                rtl.push(top->left);
            }
            cout << top->data << " ";

            if (ltr.size() == 0)
            {
                cout << endl;
                flag = false;
            }
        }

        else
        {
            BinaryTreeNode<int> *top = rtl.top();
            rtl.pop();
            if (top->left != NULL)
            {
                ltr.push(top->left);
            }
            if (top->right != NULL)
            {
                ltr.push(top->right);
            }
            cout << top->data << " ";

            if (rtl.size() == 0)
            {
                cout << endl;
                flag = true;
            }
        }
    }
    return;
}

// Nodes Without Siblings--
void printNodesWithoutSibling(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->right == NULL && root->left != NULL)
    {
        cout << root->left->data << " ";
    }
    if (root->left == NULL && root->right != NULL)
    {
        cout << root->right->data << " ";
    }
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
    return;
}

int main()
// Tree Example-- 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
{
    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    // root->left = node1;
    // root->right = node2;
    // BinaryTreeNode<int> *root = takeInput();
    BinaryTreeNode<int> *root = takeInputLevelWise();
    // printTreeLevelWise(root);
    // cout << countNodes(root);
    // cout << isNodePresent(root, 2) << " " << isNodePresent(root, 5);
    // cout << height(root);

    // mirrorBinaryTree(root);
    // printTreeLevelWise(root);

    // inorder(root);

    printLevelWise(root);
    delete root;
    return 0;
}