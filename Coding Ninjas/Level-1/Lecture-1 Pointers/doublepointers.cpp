#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *p = &a;
    int **q = &p;

    //Next three statements will print same output--

    cout << &a << endl;
    cout << p << endl;
    cout << *q << endl
         << endl;

    //Next two statements will print same output--

    cout << &p << endl;
    cout << q << endl
         << endl;

    //Next three statements will print same output--

    cout << a << endl;
    cout << *p << endl;
    cout << **q << endl
         << endl;

    return 0;
}