// https://www.programiz.com/java-programming/examples/check-valid-shuffle-of-strings

// Java Program to Check if a string is a valid shuffle of two distinct strings

#include <iostream>
using namespace std;
#include <algorithm>

class Solution
{
public:
    bool valid(string s, string s1, string s2)
    {
        if (s1.length() + s2.length() != s.length())
        {
            return false;
        }

        string temp = s1 + s2;
        // Sort s and temp strings--
        sort(s.begin(), s.end());
        sort(temp.begin(), temp.end());

        if (s == temp)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    string s, s1, s2;
    cin >> s >> s1 >> s2;

    Solution obj;
    bool check = obj.valid(s, s1, s2);

    if (check)
    {
        cout << "TRUE\n";
    }
    else
    {
        cout << "FALSE\n";
    }

    return 0;
}