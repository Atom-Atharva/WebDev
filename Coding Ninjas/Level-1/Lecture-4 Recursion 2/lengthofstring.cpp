#include <iostream>
using namespace std;

int stringLength(char str[])
{
    if (str[0] == '\0')
    {
        return 0;
    }
    int smallans = stringLength(str + 1);
    return smallans + 1;
}

int main()
{

    char str[100];
    cin >> str;

    int length = stringLength(str);
    cout << length << endl;

    return 0;
}
