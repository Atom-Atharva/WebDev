#include <iostream>
using namespace std;
#include <stack>

int countBracketReversals(string s)
{
    stack<char> c;
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{')
        {
            c.push('{');
        }
        else if (s[i] == '}')
        {
            if (c.empty())
            {
                ans++;
                c.push('{');
            }
            else
            {
                c.pop();
            }
        }
    }
    if (c.size() % 2 != 0)
    {
        return -1;
    }
    ans = ans + c.size() / 2;
    return ans;
}

int main()
{

    string s;
    cin >> s;

    int ans = countBracketReversals(s);
    cout << ans << endl;

    return 0;
}