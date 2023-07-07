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