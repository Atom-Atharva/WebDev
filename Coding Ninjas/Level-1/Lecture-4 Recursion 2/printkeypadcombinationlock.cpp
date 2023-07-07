#include <iostream>
using namespace std;

string getString(int n)
{
    switch (n)
    {
    case 2:
        return "abc";

    case 3:
        return "def";

    case 4:
        return "ghi";

    case 5:
        return "jkl";

    case 6:
        return "mno";

    case 7:
        return "pqrs";

    case 8:
        return "tuv";

    case 9:
        return "wxyz";

    default:
        return "";
    }
}

void print_Keypad(int num, string output)
{
    if (num == 0)
    {
        cout << output << endl;
        return;
    }
    string options = getString(num % 10);

    for (int i = 0; i < options.size(); i++)
    {
        print_Keypad(num / 10, options[i] + output);
    }
    return;
}

void printKeypad(int num)
{
    string output = "";
    print_Keypad(num, output);
    return;
}

int main()
{

    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}