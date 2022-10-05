#include <iostream>
using namespace std;

void permutations(string input, string output)
{
    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }
    for (int i = 0; i < input.length(); i++)
    {
        string s1 = input.substr(0, i);
        string s2 = input.substr(i + 1);
        string rest = s1 + s2;
        char ch = input[i];
        permutations(rest, output + ch);
    }
}

void printPermutations(string input)
{
    string output;
    permutations(input, output);
    return;
}

int main()
{

    string input;
    cin >> input;

    printPermutations(input);

    return 0;
}