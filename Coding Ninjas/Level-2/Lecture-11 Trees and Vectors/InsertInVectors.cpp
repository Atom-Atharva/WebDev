#include <iostream>
using namespace std;
#include <vector>

int main()
{
    vector<int> v;

    for (int i = 0; i < 10; i++)
    {
        cout << v.size() << " " << v.capacity() << endl;
        v.push_back(i);
    }

    return 0;
}