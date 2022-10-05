#include <iostream>
#include <cstring>
using namespace std;

void replacePi(char input[])
{
    if (strlen(input) <= 1)
    {
        return;
    }

    replacePi(input + 1);
    if (input[0] == 'p')
    {
        if (input[1] == 'i')
        {
            int n = strlen(input);
            for (int i = n; i > 1; i--)
            {
                input[i + 2] = input[i];
            }
            input[0] = '3';
            input[1] = '.';
            input[2] = '1';
            input[3] = '4';
        }
        return;
    }
    else
    {
        return;
    }
}

int main()
{
    char input[100];
    cin >> input;

    replacePi(input);

    cout << input << endl;

    return 0;
}