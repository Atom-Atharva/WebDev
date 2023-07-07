// https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/

// Given a string s1 and a string s2, write a function to check whether s2 is a rotation of s1.

#include <iostream>
using namespace std;

// Time Complexity O(n)--
class Solution
{
public:
    bool checkRotation(string s1, string s2)
    {
        string c = s1 + s1;
        for (int i = 0; i < c.length(); i++)
        {
            if (c.substr(i, s2.length()) == s2)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    Solution obj;
    bool check = obj.checkRotation(s1, s2);

    if (check)
    {
        cout << "True\n";
    }
    else
    {
        cout << "False\n";
    }

    return 0;
}