// https://leetcode.com/problems/implement-trie-prefix-tree/

// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

// Implement the Trie class:

// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
// boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

//  Example 1:

// Input
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output
// [null, null, true, false, true, null, true]

// Explanation
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app");     // return True

#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

private:
    void insert(TrieNode *root, string word)
    {
        // Base Case--
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // Check for the Child TrieNode--
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Reccursive Call--
        insert(child, word.substr(1));

        return;
    }

public:
    void insert(string word)
    {
        return insert(root, word);
    }

private:
    bool search(TrieNode *root, string word)
    {
        // Base Case--
        if (root == NULL)
        {
            return false;
        }
        if (word.length() == 0)
        {
            if (root->isTerminal == true)
            {
                return true;
            }

            else
            {
                return false;
            }
        }

        // Check for Child TrieNode--
        int index = word[0] - 'a';
        TrieNode *child = root->children[index];

        // Reccursive Call--
        bool ans = search(child, word.substr(1));

        return (ans) ? true : false;
    }

public:
    bool search(string word)
    {
        return search(root, word);
    }

private:
    bool startsWith(TrieNode *root, string prefix)
    {
        // Base Case--
        if (root == NULL)
        {
            return false;
        }
        if (prefix.length() == 0)
        {
            return true;
        }

        // Check for child TrieNode--
        int index = prefix[0] - 'a';
        TrieNode *child = root->children[index];

        // Reccursive Call--
        bool ans = startsWith(child, prefix.substr(1));

        return (ans) ? true : false;
    }

public:
    bool startsWith(string prefix)
    {
        return startsWith(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */