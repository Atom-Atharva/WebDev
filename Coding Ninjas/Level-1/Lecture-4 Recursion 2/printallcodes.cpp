#include <iostream>
#include <string.h>
using namespace std;

int stoi(char a)
{
    int i = a - '0';
    return i;
}

char itoc(int i)
{
    char c = 'a' + i - 1;
    return c;
}

void printCodes(string input, string output)
{
    if (input.size() == 0)
    {
        cout << output << endl;
        return;
    }
    if (input.size() == 1)
    {
        cout << output + itoc(stoi(input[0])) << endl;
        return;
    }
    printCodes(input.substr(1), output + itoc(stoi(input[0])));
    if (input.size() > 1)
    {
        if ((stoi(input[0]) * 10 + stoi(input[1])) >= 10 && (stoi(input[0]) * 10 + stoi(input[1])) <= 26)
        {
            printCodes(input.substr(2), output + itoc(stoi(input[0]) * 10 + stoi(input[1])));
        }
    }
    return;
}

void printAllPossibleCodes(string input)
{
    string output;
    printCodes(input, output);
    return;
}

int main()
{

    string input;
    cin >> input;

    printAllPossibleCodes(input);

    return 0;
}