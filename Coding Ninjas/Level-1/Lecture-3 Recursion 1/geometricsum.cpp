#include <iostream>
#include <math.h>
using namespace std;

double geometricSum(int k)
{
    if (k == 0)
    {
        return 1;
    }
    double smallout = geometricSum(k - 1);
    return (smallout + pow(0.5, k));
}

int main()
{
    int k;
    cin >> k;

    double ans = geometricSum(k);
    cout << ans << endl;

    return 0;
}