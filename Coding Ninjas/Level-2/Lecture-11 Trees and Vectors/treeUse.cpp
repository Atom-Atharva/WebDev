#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

// No of Nodes--
int numNodes(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;
}

// Sum of Nodes--
int sumOfNodes(TreeNode<int> *root)
{
    int ans = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += sumOfNodes(root->children[i]);
    }
    return ans;
}

// Heigth of Nodes--
int getHeight(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int height = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        int max_height = getHeight(root->children[i]) + 1;
        if (max_height > height)
        {
            height = max_height;
        }
    }
    return height;
}

// Total Leafs--
int getLeafNodeCount(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->children.size() == 0)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += getLeafNodeCount(root->children[i]);
    }
    return ans;
}

// Nodes at LEVEL K--
void printAtLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << endl;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
    return;
}

// print in PreOrder--
void preorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
    return;
}

// Print in PostOrder--
void postorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
    }
    cout << root->data << " ";
    return;
}

// Max Node--
TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return root;
    }
    TreeNode<int> *maximum = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *ans = maxDataNode(root->children[i]);
        if (ans->data > root->data)
        {
            maximum = ans;
        }
    }
    return maximum;
}

// Input Level Wise--
TreeNode<int> *takeInputLevelwise()
{
    int rootData;
    cout << "ENTER ROOTDATA:" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "ENTER NO. OF CHILDREN:";
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "ENTER DATA OF CHILD:" << endl;
            cin >> childData;   
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

// Normal Input--
TreeNode<int> *takeInput()
{
    int rootData;
    cout << "ENTER ROOTDATA:" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << "No. of Childrens:" << endl;
    cin >> n;

    // If (n==0), Simply reccursion will not call thus no need to define base case.
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

// Print Level Wise--
void printLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        int i = 0;
        for (i = 0; i < front->children.size(); i++)
        {
            if (i == front->children.size() - 1)
            {
                cout << front->children[i]->data;
                pendingNodes.push(front->children[i]);
            }
            else
            {
                cout << front->children[i]->data << ",";
                pendingNodes.push(front->children[i]);
            }
        }
        cout << endl;
    }
    return;
}

// Normal Printing of Tree--
void printTree(TreeNode<int> *root)
{
    // NOT BASE CASE--(EDGE CASE)
    if (root == NULL)
    {
        return;
    }

    //HERE BASE CASE IS DEFINED INTERNALLY-\
    ROOT KA CHILDREN NAHI HOGA TOH RECCURSION HI DUBARA CALL NAHI HOGA--

    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

// Delete Tree explicitiely--
void deleteTree(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
    return;
}

// Node Present?!
bool isPresent(TreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        bool ans = isPresent(root->children[i], x);
        if (ans == true)
        {
            return true;
        }
    }
    return false;
}

// Get Larger Node--
int getLargeNodeCount(TreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += getLargeNodeCount(root->children[i], x);
    }
    if (root->data > x)
    {
        ans = ans + 1;
    }
    return ans;
}

// Max Sum--
#include <climits>
template <typename T>
class MaxPair
{
public:
    TreeNode<T> *node;
    int sum;
};

MaxPair<int> *maxSumHelper(TreeNode<int> *root)
{
    if (root == NULL)
    {
        MaxPair<int> *pair = new MaxPair<int>();
        pair->node = NULL;
        pair->sum = INT_MIN;
        return pair;
    }

    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
    }

    MaxPair<int> *ans = new MaxPair<int>();
    ans->node = root;
    ans->sum = sum;

    for (int i = 0; i < root->children.size(); i++)
    {
        MaxPair<int> *maxNode = maxSumHelper(root->children[i]);
        if (maxNode->sum > ans->sum)
        {
            ans = maxNode;
        }
    }
    return ans;
}

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    // METHOD--1

    // if (root == NULL)
    // {
    //     return NULL;
    // }
    // int sum = root->data;
    // for (int i = 0; i < root->children.size(); i++)
    // {
    //     sum += root->children[i]->data;
    // }

    // if (root->children.size() == 0)
    // {
    //     return root;
    // }

    // TreeNode<int> *ansNode = root;
    // for (int i = 0; i < root->children.size(); i++)
    // {
    //     TreeNode<int> *maxNode = maxSumNode(root->children[i]);
    //     int smallsum = maxNode->data;
    //     for (int i = 0; i < maxNode->children.size(); i++)
    //     {
    //         smallsum += maxNode->children[i]->data;
    //     }
    //     if (smallsum > sum)
    //     {
    //         ansNode = maxNode;
    //         sum = smallsum;
    //     }
    // }
    // return ansNode;

    // METHOD--2
    return maxSumHelper(root)->node;
}

// Trees Identical--
bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
    {
        return false;
    }

    if ((root1->data != root2->data) || (root1->children.size() != root2->children.size()))
    {
        return false;
    }
    bool ans = true;
    for (int i = 0; i < root1->children.size(); i++)
    {
        bool check = areIdentical(root1->children[i], root2->children[i]);
        if (!check)
        {
            ans = false;
        }
    }
    return ans;
}

// Next Larger Element in Tree--
TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data > x)
    {
        return root;
    }
    TreeNode<int> *ans = NULL;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = getNextLargerElement(root->children[i], x);
        if (ans != NULL)
        {
            return ans;
        }
    }
    return ans;
}

// Second Largest Element in Tree--
template <typename T>
class PairNode
{
public:
    TreeNode<T> *largest;
    TreeNode<T> *second;

    PairNode(TreeNode<int> *largest, TreeNode<int> *second)
    {
        this->largest = largest;
        this->second = second;
    }
};

PairNode<int> *getSecondHelper(TreeNode<int> *root)
{
    if (root == NULL)
    {
        PairNode<int> *ans = new PairNode<int>(NULL, NULL);
        return ans;
    }

    PairNode<int> *ans = new PairNode<int>(root, NULL);

    for (int i = 0; i < root->children.size(); i++)
    {
        PairNode<int> *smallans = getSecondHelper(root->children[i]);
        if (smallans->largest->data > ans->largest->data)
        {
            if (smallans->second == NULL)
            {
                ans->second = ans->largest;
                ans->largest = smallans->largest;
            }
            else
            {
                if (smallans->second->data > ans->largest->data)
                {
                    ans->second = smallans->second;
                    ans->largest = smallans->largest;
                }
                else
                {
                    ans->second = ans->largest;
                    ans->largest = smallans->largest;
                }
            }
        }
        else
        {
            if (ans->largest->data != smallans->largest->data && (ans->second == NULL || smallans->largest->data > ans->second->data))
            {
                ans->second = smallans->largest;
            }
        }
    }
    return ans;
}

TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    return getSecondHelper(root)->second;
}

// Replace with Depth--
void replaceWithDepthHelper(TreeNode<int> *root, int count)
{
    if (root == NULL)
    {
        return;
    }
    root->data = count;
    for (int i = 0; i < root->children.size(); i++)
    {
        replaceWithDepthHelper(root->children[i], count + 1);
    }
    return;
}
void replaceWithDepthValue(TreeNode<int> *root)
{
    return replaceWithDepthHelper(root, 0);
}

int main()
{
    // TreeNode<int> *root = new TreeNode<int>(1);
    // TreeNode<int> *node1 = new TreeNode<int>(2);
    // TreeNode<int> *node2 = new TreeNode<int>(3);

    // Connecting root and nodes
    // root->children.push_back(node1);
    // root->children.push_back(node2);

    TreeNode<int> *root = takeInputLevelwise();
    printLevelWise(root);

    // TODO delete the tree
    // deleteTree(root);

    // delete Using Destructor
    delete root;
    return 0;
}