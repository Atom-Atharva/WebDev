#include <iostream>
using namespace std;

class Distance
{
    int feet;
    float inches;

public:
    void set(int feet, float inches)
    {
        this->feet = feet;
        this->inches = inches;
    }
    void display()
    {
        cout << feet << " " << inches << endl;
    }
    Distance add(Distance d)
    {
        Distance c;
        c.feet = d.feet + feet;
        c.inches = d.inches + inches;
        if (c.inches >= 12)
        {
            int add = c.inches / 12;
            c.inches = c.inches - add * 12;
            c.feet = c.feet + add;
        }
        return c;
    }
};

int main()
{
    Distance a, b;
    a.set(3, 8);
    b.set(5, 11.5);

    Distance c = a.add(b);
    c.display();

    return 0;
}