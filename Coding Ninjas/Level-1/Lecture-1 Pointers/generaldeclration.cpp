#include <iostream>
using namespace std;

int main()
{
    int f_val = 5, s_val = 15;
    char t_val = 'a';

    int *p1, *p2;
    char *p3;

    p1 = &f_val;
    p2 = &s_val;
    p3 = &t_val;

    *p1 = 10;
    *p2 = *p1;

    cout << s_val << endl;

    p1 = p2;
    *p1 = 20;
    *p3 = 'b';

    cout << f_val << endl;
    cout << s_val << endl;
    cout << t_val << endl;

    return 0;
}