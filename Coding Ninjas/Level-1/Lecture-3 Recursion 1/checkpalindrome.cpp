#include <iostream>
#include <cstring>
using namespace std;

bool helper(char input[], int st, int en)
{
    if (st == en)
    {
        return true;
    }
    if (input[st] != input[en])
    {
        return false;
    }
    if (st < en + 1)
    {
        return helper(input, st + 1, en - 1);
    }
    return true;
}

bool checkPalindrome(char input[])
{
    int n = strlen(input);
    int st = 0, en = n - 1;

    if (n == 0)
    {
        return true;
    }

    bool ans = helper(input, st, en);
    return ans;
}

int main()
{
    char input[50];
    cin >> input;

    if (checkPalindrome(input))
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}