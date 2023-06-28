// https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1

// Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.
// Note: While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and other one to the right.

// Example 1:

// S = "abcdef"
// f[] = {5, 9, 12, 13, 16, 45}
// Output:
// 0 100 101 1100 1101 111
// Explanation:
// Steps to print codes from Huffman Tree
// HuffmanCodes will be:
// f : 0
// c : 100
// d : 101
// a : 1100
// b : 1101
// e : 111
// Hence printing them in the PreOrder of Binary
// Tree.

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Node
{
public:
    int freq;
    string str;
    Node *left, *right;

    Node(int freq, string str)
    {
        this->freq = freq;
        this->str = str;
        left = NULL;
        right = NULL;
    }
};
class Compare
{
public:
    bool operator()(Node *a1, Node *a2)
    {
        return (a1->freq > a2->freq);
    }
};

class Solution
{

    void preOrder(Node *root, vector<string> &ans, string s)
    {
        // Base Case--
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            if (s == "")
            {
                ans.push_back("0");
                return;
            }
            ans.push_back(s);
            return;
        }

        // Recursive Calls--
        preOrder(root->left, ans, s + '0');
        preOrder(root->right, ans, s + '1');

        return;
    }

public:
    vector<string> huffmanCodes(string s, vector<int> f, int n)
    {
        // Insert into Priority Queue--
        priority_queue<Node *, vector<Node *>, Compare> pq;
        for (int i = 0; i < n; i++)
        {
            Node *temp = new Node(f[i], s.substr(i, 1));
            pq.push(temp);
        }

        // Operate on Top 2 Nodes--
        while (pq.size() > 1)
        {
            Node *first = pq.top();
            pq.pop();

            Node *second = pq.top();
            pq.pop();

            // Construct new Node and make connections--
            Node *result = new Node(first->freq + second->freq, first->str + second->str);
            result->left = first;
            result->right = second;

            // Insert in Min Heap--
            pq.push(result);
        }

        // Obtain root Node--
        Node *root = pq.top();
        pq.pop();

        // PreOrder Traversal on Tree Obtained--
        vector<string> ans;
        preOrder(root, ans, "");

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        int N = S.length();
        vector<int> f(N);
        for (int i = 0; i < N; i++)
        {
            cin >> f[i];
        }
        Solution ob;
        vector<string> ans = ob.huffmanCodes(S, f, N);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends