#include <iostream>
using namespace std;

int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    int output = power(x, n - 1);
    return (output * x);
}

int main()
{
    int x, n;
    cin >> x >> n;

    int output = power(x, n);

    cout << output << endl;

    return 0;
}