#include <iostream>
using namespace std;

// a--from
// b--helper
// c--to

void towerOfHanoi(int n, char a, char b, char c)
{
    if (n == 0)
        return;

    towerOfHanoi(n - 1, a, c, b);
    cout << a << " " << c << endl;
    towerOfHanoi(n - 1, b, a, c);
    return;
}

int main()
{

    int n;
    cin >> n;

    char a, b, c;
    towerOfHanoi(n, 'a', 'b', 'c');

    return 0;
}