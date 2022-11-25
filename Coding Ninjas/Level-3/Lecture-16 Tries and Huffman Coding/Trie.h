#include "TrieNode.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

private:
    // Helper Function-
    void insertWord(TrieNode *root, string word)
    {
        // Base Case-
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // Small Calculation-
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

        // Recursive Call-
        insertWord(child, word.substr(1));
        return;
    }

    bool search(TrieNode *root, string word)
    {
        // Base Case-
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

        // Small Calculation-
        int index = word[0] - 'a';
        if (root->children[index] == NULL)
        {
            return false;
        }
        TrieNode *child = root->children[index];

        // Recursive Call-
        bool found = search(child, word.substr(1));
        if (!found)
        {
            return false;
        }
        return true;
    }

    void removeWord(TrieNode *root, string word)
    {
        // Base Case-
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }

        // Small Calculation-
        TrieNode *child;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // Word not Found-
            return;
        }

        // Recursive Call-
        removeWord(child, word.substr(1));

        // Remove child Node if it is useless-
        if (child->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != NULL)
                {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
        return;
    }

    // Pattern Matching Helper Function--
    bool patternMatching(TrieNode *root, string pattern)
    {
        // Base Case-
        if (pattern.length() == 0)
        {
            return true;
        }

        // Small Calculation-
        int index = pattern[0] - 'a';
        if (root->children[index] == NULL)
        {
            return false;
        }
        TrieNode *child = root->children[index];

        // Recursive Call-
        bool ans = patternMatching(child, pattern.substr(1));
        if (ans)
        {
            return true;
        }
        return false;
    }

public:
    void insertWord(string word)
    {
        insertWord(root, word);
        return;
    }

    bool search(string word)
    {
        return search(root, word);
    }

    void removeWord(string word)
    {
        removeWord(root, word);
        return;
    }

    // Pattern Matching--
    bool patternMatching(vector<string> vect, string pattern)
    {
        for (int i = 0; i < vect.size(); i++)
        {
            // Adding all Sufix of the Word-
            for (int j = 0; j < vect[i].size(); j++)
            {
                insertWord(vect[i].substr(j));
            }
        }

        return patternMatching(root, pattern);
    }

    // Auto-Complete--
    void remainingWord(TrieNode *root, string word)
    {
        int i = 0;
        for (i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                // Small Calculation and Recursive Call-
                string newword = word;
                newword = newword + (char)('a' + i);
                remainingWord(root->children[i], newword);
            }
        }

        // Base Case-
        if (i == 26 && root->isTerminal == true)
        {
            cout << word << endl;
        }
        return;
    }
    void completeWord(TrieNode *root, string pattern, string word)
    {
        // Base Case-
        if (pattern.length() == 0)
        {
            remainingWord(root, word);
            return;
        }

        // Small Calculation-
        int index = pattern[0] - 'a';
        TrieNode *child;

        if (root->children[index] == NULL)
        {
            return;
        }
        else
        {
            word = word + pattern[0];
            child = root->children[index];

            // Reccursive Call--
            completeWord(child, pattern.substr(1), word);
        }

        return;
    }
    void autoComplete(vector<string> input, string pattern)
    {
        for (int i = 0; i < input.size(); i++)
        {
            insertWord(input[i]);
        }

        completeWord(root, pattern, "");
        return;
    }
};