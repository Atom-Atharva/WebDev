#include <iostream>
#include <stack>
using namespace std;

bool checkRedundantBrackets(string s)
{
    stack<char> c;
    c.push(0);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            if (c.top() == '(')
            {
                return true;
            }
            c.push('(');
        }
        else if (s[i] == ')')
        {
            if (c.top() == '(')
            {
                return true;
            }
            c.push(')');
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            c.push(s[i]);
        }
    }
    return false;
}

int main()
{
    string s;
    cin >> s;

    bool ans = checkRedundantBrackets(s);
    cout << ans << endl;
    return 0;
}