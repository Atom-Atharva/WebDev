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

int getCodes(string input, string output[100])
{
    if (input.size() == 0)
    {
        output[0] = "";
        return 1;
    }
    if (input.size() == 1)
    {
        output[0] = itoc(stoi(input[0]));
        return 1;
    }
    string op1[100], op2[100];
    int ans2 = 0;

    int ans1 = getCodes(input.substr(1), op1);

    if (input.size() > 1)
    {
        if (stoi(input[0]) * 10 + stoi(input[1]) >= 10 && stoi(input[0]) * 10 + stoi(input[1]) <= 26)
        {
            ans2 = getCodes(input.substr(2), op2);
        }
    }
    int k = 0;
    for (int i = 0; i < ans1; i++, k++)
    {
        output[k] = itoc(stoi(input[0])) + op1[i];
    }
    for (int i = 0; i < ans2; i++, k++)
    {
        output[k] = itoc(stoi(input[0]) * 10 + stoi(input[1])) + op2[i];
    }
    return ans1 + ans2;
}

int main()
{
    string input;
    cin >> input;

    string output[100];
    int size = getCodes(input, output);

    for (int i = 0; i < size && i < 100; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}