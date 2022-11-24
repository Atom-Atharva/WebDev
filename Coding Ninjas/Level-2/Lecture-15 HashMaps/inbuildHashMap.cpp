#include <iostream>
using namespace std;

// For HashTable Types of Maps--
#include <unordered_map>
int main()
{
    unordered_map<string, int> ourmap;

    // Insert
    pair<string, int> p("abc", 1);
    //Pairs must be given for easy insertion of the element-
    ourmap.insert(p);
    ourmap["def"] = 2;

    // Find or Access
    cout << ourmap["abc"] << endl;
    cout << ourmap.at("abc") << endl;

    // Will throw Exception on excessing out of range element
    // cout << ourmap.at("ghi") << endl;

    // Agar nahi hoga toh insert kar dega aur value 0(by default) rakh dega
    cout << ourmap["ghi"];

    cout << ourmap.size() << endl;

    // Check Presense
    if (ourmap.count("ghi") > 0)
    {
        cout << "ghi is present\n";
    }

    // Erase
    ourmap.erase("ghi");
    if (ourmap.count("ghi") > 0)
    {
        cout << "ghi is present\n";
    }

    return 0;
}