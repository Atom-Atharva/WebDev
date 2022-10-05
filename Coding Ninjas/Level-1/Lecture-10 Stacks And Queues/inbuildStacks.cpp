#include <iostream>
using namespace std;

// (.h) files are the file with no main and this copy all the code in the file to the include line.
//#include "Stacktemplate.h"

#include <stack>

int main()
{
    stack<int> s;

    // Inbuild push function

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    // TOP function returns the top data and POP function delete the top data.

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    // Size function returns the size of stack and empty function returns boolean value.

    cout << s.size() << endl;
    cout << s.empty() << endl;

    return 0;
}
