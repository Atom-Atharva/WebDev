#include <iostream>
#include <cstring>
#include<cmath>
using namespace std;

int stringToNumber(char input[])
{
    if (strlen(input) == 1)
    {
        return input[0]-48;
    }
    int smallans = stringToNumber(input + 1);
    return smallans + ((input[0] - 48) * pow(10, strlen(input) - 1));
}

int main()
{
    char input[100];
    cin >> input;

    int ans = stringToNumber(input);

    cout << ans << endl;

    return 0;
}