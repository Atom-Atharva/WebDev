#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Dynamically Allocation
    // vector<int> *p = new vector<int>();

    // Static Allocation
    vector<int> v;

    // Push Element At the Back
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);

    // [] <-- This would be use when value need to be get or updated
    v[1] = 100;
    // Carefull with range of the vector array
    cout << v[0] << " ";
    cout << v[1] << " ";
    cout << v[2] << " ";
    cout << v[3] << " ";
    cout << v[4] << " ";

    cout << endl;

    // Size of vector

    cout << v.size() << endl;

    // Value at--
    cout << v.at(4) << endl;
    cout << v.at(5) << endl;
    // cout << v.at(6) << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // Delete Last Element
    v.pop_back();

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // Shows Current Capacity of the array-
    // Increase by factor of 2, Starts from 0
    cout << v.capacity() << endl; 

    return 0;
}