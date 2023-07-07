#include <iostream>
#include <cstring>
using namespace std;

void pairStar(char input[])
{
    if (strlen(input) == 1)
    {
        return;
    }
    pairStar(input + 1);
    if (input[0] == input[1])
    {
        for (int i = strlen(input); i >= 1; i--)
        {
            input[i + 1] = input[i];
        }
        input[1] = '*';
    }
    return;
}

int main()
{
    char input[50];
    cin >> input;

    pairStar(input);

    cout << input << endl;
    return 0;
}