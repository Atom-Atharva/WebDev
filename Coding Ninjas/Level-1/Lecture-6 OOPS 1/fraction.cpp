#include <iostream>
using namespace std;
#include "fractionclass.cpp"

int main()
{
    fraction f1(10, 2);
    fraction f2(25, 5);

    f1.print();
    f2.print();
    
    f1.add(f2);
    f1.multiply(f2);

    f1.print();
    f2.print();

    return 0;
}