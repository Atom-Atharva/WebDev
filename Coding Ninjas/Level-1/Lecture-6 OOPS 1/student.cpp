#include <iostream>
using namespace std;

class Student
{
private:
    int admno;
    char sname[20];
    float math, eng, science;
    float total;
    float ctotal()
    {
        return eng + math + science;
    }

public:
    void takedata()
    {
        cin >> admno;
        cin >> sname;
        cin >> eng >> math >> science;
        total = ctotal();
    }

    void showdata()
    {
        cout << admno << endl;
        cout << sname << endl;
        cout << eng << " " << math << " " << science << endl;
        cout << total << endl;
    }
};

int main()
{
    Student s;
    s.takedata();
    s.showdata();

    return 0;
}