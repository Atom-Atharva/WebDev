#include <iostream>
using namespace std;

void print_sub(string input, string output)
{
    if (input.size() == 0)
    {
        cout << output << endl;
        return;
    }
    print_sub(input.substr(1), output);
    print_sub(input.substr(1), input[0] + output);
}

int main()
{

    string input;
    cin >> input;

    string output = " ";
    print_sub(input, output);

    return 0;
}