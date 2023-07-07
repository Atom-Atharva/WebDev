#include <iostream>
using namespace std;
#include <unordered_map>

string uniqueChar(string str)
{
    string output;
    unordered_map<char, bool> seen;
    for (int i = 0; i < str.length(); i++)
    {
        if (seen.count(str[i]) > 0)
        {
            continue;
        }
        seen[str[i]] = 1;
        output = output + str[i];
    }
    return output;
}

int main()
{
    string s;
    cin >> s;

    string ans = uniqueChar(s);
    cout << ans << endl;

    return 0;
}