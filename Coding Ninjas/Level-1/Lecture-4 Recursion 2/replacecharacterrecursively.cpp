#include <iostream>
using namespace std;

void replaceCharacter(char str[], char c1, char c2)
{
    if (str[0] == '\0')
    {
        return;
    }
    replaceCharacter(str + 1, c1, c2);
    if (str[0] == c1)
    {
        str[0] = c2;
    }
    return;
}

int main()
{

    char str[50];
    cin >> str;

    char c1, c2;
    cin >> c1 >> c2;

    replaceCharacter(str, c1, c2);

    cout << str << endl;

    return 0;
}