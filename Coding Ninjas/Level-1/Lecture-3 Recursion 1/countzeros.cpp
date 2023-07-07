#include <iostream>
using namespace std;

int countZeros(int n)
{
    if (n < 10 && n != 0)
    {
        return 0;
    }

    else if (n == 0)
    {
        return 1;
    }

    int smallout = countZeros(n / 10);
    if (n % 10 == 0)
    {
        return (smallout + 1);
    }
    else
    {
        return (smallout);
    }
}

int main()
{

    int n;
    cin >> n;

    int ans = countZeros(n);

    cout << ans << endl;

    return 0;
}