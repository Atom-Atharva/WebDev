#include <iostream>
#include <cstring>
using namespace std;

void removeX(char input[])
{
    if (strlen(input) == 0)
    {
        return;
    }
    removeX(input + 1);
    if (input[0] == 'x')
    {
        int n = strlen(input);
        for (int i = 0; i <= n; i++)
        {
            input[i] = input[i + 1];
        }
    }
    return;
}

int main()
{
    char input[100];
    cin >> input;

    removeX(input);

    cout << input << endl;
    return 0;
}