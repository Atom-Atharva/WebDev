#include <iostream>
using namespace std;

int sum(int n)
{
    if (n == 1  )
    {
        return 1;
    }
    int smallout = sum(n - 1);
    return smallout + n;
}

int main()
{
    int n;
    cin >> n;

    int ans = sum(n);
    cout << ans << endl;

    return 0;
}