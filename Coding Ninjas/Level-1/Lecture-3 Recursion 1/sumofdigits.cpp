#include <iostream>
using namespace std;

int sumOfDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int smallout = sumOfDigits(n / 10);
    return smallout + (n % 10);
}

int main()
{

    int n;
    cin >> n;

    int ans = sumOfDigits(n);

    cout << ans << endl;

    return 0;
}