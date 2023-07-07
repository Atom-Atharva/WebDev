#include <iostream>
using namespace std;

class Rectangle
{
    float length;
    float width;

public:
    void setlength(float length)
    {
        this->length = length;
    }
    void setwidth(float width)
    {
        this->width = width;
    }
    float perimeter()
    {
        return 2 * (length + width);
    }
    float area()
    {
        return length * width;
    }
    int sameArea(Rectangle r)
    {
        float area = width * length;
        float area_r = r.length * r.width;
        if (area_r == area)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    Rectangle a, b;
    a.setlength(5);
    a.setwidth(2.5);

    b.setlength(5);
    b.setwidth(18.9);

    cout << a.area() << endl;
    cout << a.perimeter() << endl;
    cout << b.area() << endl;
    cout << b.perimeter() << endl;

    cout << a.sameArea(b) << endl;

    return 0;
}