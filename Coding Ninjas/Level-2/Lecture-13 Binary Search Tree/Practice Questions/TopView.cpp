#include <iostream>
#include "NodeClass.h"
#include <queue>
#include <map>
using namespace std;

// Good Question--
// Using Map and Queue--
// TODO- Map Data Stucture is not covered so cannot be solved now.

// NOT MY APPROACH
void topView(Node *root)
{
    map<int, int> top_view;             // map<column, data>
    queue<pair<int, Node *>> nextQueue; // queue<column, Node*>
    if (root)
    {
        nextQueue.push({0, root});
        top_view.insert({0, root->data});
        while (!nextQueue.empty())
        {
            pair<int, Node *> temp;
            temp = nextQueue.front();
            if (temp.second->left != NULL)
            {
                nextQueue.push({temp.first - 1, temp.second->left});
                if (top_view.find(temp.first - 1) == top_view.end())
                {
                    top_view.insert({temp.first - 1, temp.second->left->data});
                }
            }
            if (temp.second->right != NULL)
            {
                nextQueue.push({temp.first + 1, temp.second->right});
                if (top_view.find(temp.first + 1) == top_view.end())
                {
                    top_view.insert({temp.first + 1, temp.second->right->data});
                }
            }
            // cout<<temp.first<<":"<<temp.second->data<<" | ";
            nextQueue.pop();
        }
    }
    map<int, int>::iterator itr;
    for (itr = top_view.begin(); itr != top_view.end(); itr++)
    {
        // cout<<itr->first<<":"<<itr->second<<" | ";
        cout << itr->second << " ";
    }
}