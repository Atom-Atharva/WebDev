#include <iostream>
using namespace std;

template <typename T, typename V>

class Pair
{
    T x;
    V y;

public:
    void setX(T x)
    {
        this->x = x;
    }
    void setY(V y)
    {
        this->y = y;
    }
    T getX()
    {
        return x;
    }
    V getY()
    {
        return y;
    }
};

int main()
{
    Pair<char, int> p1;
    p1.setX('a');
    p1.setY(15);

    Pair<Pair<char, int>, int> p2;
    p2.setX(p1);
    p2.setY(20);

    cout << p2.getX().getX() << endl
         << p2.getX().getY() << endl
         << p2.getY() << endl;
}