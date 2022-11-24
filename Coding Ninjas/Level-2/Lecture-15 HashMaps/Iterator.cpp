#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

int main()
{
    unordered_map<string, int> ourmap;
    ourmap["abc1"] = 1;
    ourmap["abc2"] = 2;
    ourmap["abc3"] = 3;
    ourmap["abc4"] = 4;
    ourmap["abc5"] = 5;
    ourmap["abc6"] = 6;
    ourmap["abc7"] = 7;

    // iterator starts with begin method-
    unordered_map<string, int>::iterator it = ourmap.begin(); // it is pointer of the pair in unordered map.
    while (it != ourmap.end())                                // next element of last entry.
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    vector<int>::iterator it2 = v.begin();
    while (it2 != v.end())
    {
        cout << *it2 << endl;
        it2++;
    }

    // find and delete functions.
    // unordered_map<string, int>::iterator it3 = ourmap.find("abc1");
    // ourmap.erase(it3, it3 + 4); // Staring iterator, Ending iterator

    return 0;
}
