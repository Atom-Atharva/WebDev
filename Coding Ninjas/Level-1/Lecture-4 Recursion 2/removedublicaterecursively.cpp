#include <iostream>
#include <cstring>
using namespace std;

void removeConsecutiveDuplicates(char str[])
{
    if (str[0] == '\0')
    {
        return;
    }
    removeConsecutiveDuplicates(str + 1);
    if (str[0] == str[1])
    {
        for (int i = 1; i <= strlen(str); i++)
        {
            str[i] = str[i + 1];
        }
        removeConsecutiveDuplicates(str);
    }
    return;
}

int main()
{
    char str[50];
    cin >> str;

    removeConsecutiveDuplicates(str);

    cout << str << endl;
    return 0;
}