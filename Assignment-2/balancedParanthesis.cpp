// P15. Given an expression string S, write a program to examine whether the pairs
// and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in the given expression.
// Example:
// Input: S = “[()]{}{[()()]()}”
// Output: Balanced
// Explanation: all the brackets are well-formed
// Input: S = “[(])”
// Output: Not Balanced
// Explanation: 1 and 4 brackets are not balanced because there is a closing ‘]’ before the
// closing ‘(‘

#include <iostream>
using namespace std;
#include <stack>

bool isBalanced(string s)
{
    stack<char> p;
    p.push('0');

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            p.push(s[i]);
        }
        else if (s[i] == '}')
        {
            if (p.top() == '{')
            {
                p.pop();
            }
            else
            {
                return false;
            }
        }
        else if (s[i] == ')')
        {
            if (p.top() == '(')
            {
                p.pop();
            }
            else
            {
                return false;
            }
        }
        else if (s[i] == ']')
        {
            if (p.top() == '[')
            {
                p.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (p.top() == '0')
    {
        return true;
    }
    return false;
}

int main()
{
    string s;
    cin >> s;

    if (isBalanced(s))
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}