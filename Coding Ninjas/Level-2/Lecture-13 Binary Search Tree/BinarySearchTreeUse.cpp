#include <iostream>
using namespace std;
#include "BinaryTreeNode.h"

//  Searching in Binary Search Tree--
bool searchInBST(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == k)
    {
        return true;
    }
    bool leftans;
    if (root->left != NULL)
    {
        leftans = searchInBST(root->left, k);
    }
    bool rightans;
    if (root->right != NULL)
    {
        rightans = searchInBST(root->right, k);
    }
    if (leftans == true || rightans == true)
    {
        return true;
    }
    return false;
}

// Print Elements in Range
void elementsInRangeK1K2(BinaryTreeNode<int> *root, int k1, int k2)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data <= k2 && root->data >= k1)
    {
        elementsInRangeK1K2(root->left, k1, k2);
        cout << root->data << " ";
        elementsInRangeK1K2(root->right, k1, k2);
    }
    else if (root->data > k2)
    {
        elementsInRangeK1K2(root->left, k1, k2);
    }
    else if (root->data < k1)
    {
        elementsInRangeK1K2(root->right, k1, k2);
    }
    return;
}

// Check if the Binary Tree is BST
// Root ko left aur right child se compare nhi karna cause ho sakta hai neeche kahi BST false ho raha ho.
// Check CN Lecture-13 Video: Check BST-1;
// Time Complexity O(n);
#include <climits>
bool solve(BinaryTreeNode<int> *root, int mn, int mx)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data > mx || root->data < mn)
    {
        return false;
    }
    return solve(root->left, mn, root->data - 1) && solve(root->right, root->data, mx);
}
bool isBST(BinaryTreeNode<int> *root)
{
    return solve(root, INT_MIN, INT_MAX);
}

// Check if the Binary Tree is BST (METHOD-2)
// In this method we will see if the root is smaller than the minimum of right subtree and
// is the root is bigger thean the maximum of the left subtree.
// Time Complexity of the process is O(n*h) which is very bad.
int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
bool isBST2(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    int leftmax = maximum(root->left);
    int rightmin = minimum(root->right);
    bool output = (root->data >= leftmax) && (root->data <= rightmin) && (isBST2(root->left)) && (isBST2(root->right));
    return output;
}

// Check if the Binary Tree is BST (Method-3)
// In this method to reduce the time complexity we will return a class containing 3 properties
// This method reduces the multiple call to the child nodes and brings the required variables only onces
// The time complexity for the code is O(n)
class IsBSTReturn
{
public:
    bool isBST;
    int minimum;
    int maximum;
};
IsBSTReturn isBST3(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        IsBSTReturn ans;
        ans.isBST = true;
        ans.minimum = INT_MAX;
        ans.maximum = INT_MIN;
        return ans;
    }

    IsBSTReturn leftOutput = isBST3(root->left);
    IsBSTReturn rightOutput = isBST3(root->right);

    int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
    int maximum = max(root->data, max(leftOutput.maximum, rightOutput.minimum));
    bool isBSTFinal = (root->data >= leftOutput.maximum) && (root->data <= rightOutput.minimum) && (leftOutput.isBST) && (rightOutput.isBST);

    IsBSTReturn output;
    output.minimum = minimum;
    output.maximum = maximum;
    output.isBST = isBSTFinal;
    return output;
}

// Construct Binary Search Tree Using a Sorted Array--
BinaryTreeNode<int> *constructTreeHelper(int *input, int st, int en)
{
    if (st > en)
    {
        return NULL;
    }

    int mid = (st + en) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);
    BinaryTreeNode<int> *leftChild = constructTreeHelper(input, st, mid - 1);
    BinaryTreeNode<int> *rightChild = constructTreeHelper(input, mid + 1, en);

    root->left = leftChild;
    root->right = rightChild;
    return root;
}
BinaryTreeNode<int> *constructTree(int *input, int n)
{
    int si = 0;
    int en = n - 1;
    return constructTreeHelper(input, si, en);
}

// Create the Sorted LL using Binary Search Tree--
#include "SortedLLUsingBST.h"
pair<Node<int> *, Node<int> *> constructList(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<Node<int> *, Node<int> *> ans;
        ans.first = NULL;
        ans.second = NULL;
        return ans;
    }
    Node<int> *newNode = new Node<int>(root->data);
    if (root->left == NULL && root->right == NULL)
    {
        pair<Node<int> *, Node<int> *> ans;
        ans.first = newNode;
        ans.second = newNode;
        return ans;
    }
    if (root->left == NULL)
    {
        pair<Node<int> *, Node<int> *> rightChild = constructList(root->right);
        pair<Node<int> *, Node<int> *> output;
        output.first = newNode;
        newNode->next = rightChild.first;
        output.second = rightChild.second;
        return output;
    }
    if (root->right == NULL)
    {
        pair<Node<int> *, Node<int> *> leftChild = constructList(root->left);
        pair<Node<int> *, Node<int> *> output;
        output.first = leftChild.first;
        leftChild.second->next = newNode;
        output.second = newNode;
        return output;
    }

    pair<Node<int> *, Node<int> *> leftChild = constructList(root->left);
    pair<Node<int> *, Node<int> *> rightChild = constructList(root->right);

    leftChild.second->next = newNode;
    newNode->next = rightChild.first;

    pair<Node<int> *, Node<int> *> output;
    output.first = leftChild.first;
    output.second = rightChild.second;

    return output;
}
Node<int> *constructLinkedList(BinaryTreeNode<int> *root)
{
    return constructList(root).first;
}

// Node To Root PATH in Binary Tree--
#include <vector>
vector<int> *getRootToNodePath(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data = data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int> *leftOutput = getRootToNodePath(root->left, data);
    if (leftOutput != NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int> *rightOutput = getRootToNodePath(root->right, data);
    if (rightOutput != NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else
    {
        return NULL;
    }
}

// Find Path in Binary Search Tree--
vector<int> *getPath(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    if (root->data > data)
    {
        vector<int> *leftOutput = getPath(root->left, data);
        if (leftOutput != NULL)
        {
            leftOutput->push_back(root->data);
            return leftOutput;
        }
        else
        {
            return NULL;
        }
    }

    vector<int> *rightOutput = getPath(root->right, data);
    if (rightOutput != NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else
    {
        return NULL;
    }
}

// Create and Insert Dublicate Nodes--
void insertDuplicateNode(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int> *temp = root->left;
    root->left = newNode;
    newNode->left = temp;

    insertDuplicateNode(temp);
    insertDuplicateNode(root->right);
    return;
}

// Pair Sum Binary Tree

// Approach-1: Time Complexity- O(n^2)--
// Traval to each node, find corresponding sum(sum-rootdata) in the full tree.

// Approach-2: Time Complexity- O(nlogn)--
// Convert Tree into array and sort array and find pair sum.
#include <algorithm>
void createArray(BinaryTreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    ans.push_back(root->data);
    createArray(root->left, ans);
    createArray(root->right, ans);
    return;
}
void pairSum(BinaryTreeNode<int> *root, int sum)
{
    vector<int> ans;
    createArray(root, ans);
    sort(ans.begin(), ans.end());
    int i = 0;
    int j = ans.size() - 1;
    while (i < j)
    {
        if (ans[i] + ans[j] == sum)
        {
            cout << ans[i] << " " << ans[j] << endl;
            i++;
            j--;
        }
        else if (ans[i] + ans[j] > sum)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
}

// LCA of Binary Tree--
int getLCA(BinaryTreeNode<int> *root, int a, int b)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == a || root->data == b)
    {
        return root->data;
    }
    int left = getLCA(root->left, a, b);
    int right = getLCA(root->right, a, b);

    if (left == -1 && right == -1)
    {
        return -1;
    }
    else if (left == -1)
    {
        return right;
    }
    else if (right == -1)
    {
        return left;
    }
    else
    {
        return root->data;
    }
}

// LCA of Binary Search Tree--
int getLCA_BST(BinaryTreeNode<int> *root, int a, int b)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == a || root->data == b)
    {
        return root->data;
    }

    int left = -1;
    int right = -1;

    if (a < root->data && b < root->data)
        left = getLCA_BST(root->left, a, b);

    else if (a > root->data && b > root->data)
        right = getLCA_BST(root->right, a, b);

    else
    {
        left = getLCA_BST(root->left, a, b);
        right = getLCA_BST(root->right, a, b);
    }
    if (left == -1 && right == -1)
    {
        return -1;
    }
    else if (left == -1)
    {
        return right;
    }
    else if (right == -1)
    {
        return left;
    }
    else
    {
        return root->data;
    }
}

// Find the Largest Heigth of the BST from the given Binary Tree--
class Properties
{
public:
    int min;
    int max;
    bool isBST;
    int height;

    Properties()
    {
        min = INT_MAX;
        max = INT_MIN;
        isBST = true;
        height = 0;
    }
};
Properties *largestBSTSubTreeHelper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Properties *ans = new Properties();
        return ans;
    }

    Properties *leftChild = largestBSTSubTreeHelper(root->left);
    Properties *rightChild = largestBSTSubTreeHelper(root->right);

    if (!(rightChild->isBST && rightChild->min > root->data))
    {
        rightChild->isBST = false;
    }
    if (!(leftChild->isBST && leftChild->max < root->data))
    {
        leftChild->isBST = false;
    }

    if (!(rightChild->isBST) || !(leftChild->isBST) || !(root->data > leftChild->max) || !(root->data < rightChild->min))
    {
        if (rightChild->height > leftChild->height)
        {
            rightChild->isBST = false;
            return rightChild;
        }
        else
        {
            leftChild->isBST = false;
            return leftChild;
        }
    }

    Properties *ans = new Properties();
    ans->height = (max(leftChild->height, rightChild->height) + 1);
    ans->min = min(root->data, min(leftChild->min, rightChild->min));
    ans->max = max(root->data, max(leftChild->max, rightChild->max));
    ans->isBST = true;

    return ans;
}
int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    return largestBSTSubTreeHelper(root)->height;
}

// Replace with SUM of Greater Nodes--
int replace(BinaryTreeNode<int> *root, int sum)
{
    if (root == NULL)
    {
        return sum;
    }
    int rightSum = replace(root->right, sum);
    root->data = root->data + rightSum;
    int leftSum = replace(root->left, root->data);

    return leftSum;
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root)
{
    int sum = replace(root, 0);
    return;
}

// Path Sum root to leaf--
void rootToLeafPaths(BinaryTreeNode<int> *root, int k, string p)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        if (k == root->data)
        {
            cout << p + " " + to_string(root->data) << endl;
        }
        return;
    }
    string data = to_string(root->data);
    rootToLeafPaths(root->left, k - root->data, p + data + " ");
    rootToLeafPaths(root->right, k - root->data, p + data + " ");
    return;
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k)
{
    return rootToLeafPaths(root, k, "");
}

// Print Node at a Distance K from node--
void findKDown(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    findKDown(root->left, k - 1);
    findKDown(root->right, k - 1);
}
int nodeAtDistK(BinaryTreeNode<int> *root, int node, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == node)
    {
        findKDown(root, k);
        return 0;
    }
    int leftDist = nodeAtDistK(root->left, node, k);
    if (leftDist != -1)
    {
        if (leftDist + 1 == k)
        {
            cout << root->data << endl;
        }
        else
        {
            findKDown(root->right, k - leftDist - 2);
        }
        return 1 + leftDist;
    }

    int rightDist = nodeAtDistK(root->right, node, k);
    if (rightDist != -1)
    {
        if (rightDist + 1 == k)
        {
            cout << root->data << endl;
        }
        else
        {
            findKDown(root->left, k - rightDist - 2);
        }
        return 1 + rightDist;
    }
    return -1;
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k)
{
    int distance = nodeAtDistK(root, node, k);
    return;
}

// Pair Sum in BST--
void inOrder(BinaryTreeNode<int> *root, vector<int> *arr)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left, arr);
    arr->push_back(root->data);
    inOrder(root->right, arr);
    return;
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s)
{
    vector<int> *arr = new vector<int>();
    inOrder(root, arr);
    int i = 0, j = arr->size() - 1;
    while (i < j)
    {
        if (arr->at(i) + arr->at(j) == s)
        {
            cout << arr->at(i) << " " << arr->at(j) << endl;
            i++;
            j--;
        }
        else if (arr->at(i) + arr->at(j) > s)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return;
}

int main()
{
    return 0;
}