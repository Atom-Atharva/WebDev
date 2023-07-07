#include <iostream>
using namespace std;

class Time
{
    int hour;
    int min;

public:
    void settime(int hour, int min)
    {
        this->hour = hour;
        this->min = min;
    }
    void showtime()
    {
        cout << hour << " " << min << endl;
    }
    Time sum(Time t)
    {
        Time x;
        x.hour = t.hour + hour;
        x.min = t.min + min;
        if (x.min >= 60)
        {
            int add = x.min / 60;
            x.hour += add;
            x.min -= (add * 60);
        }
        return x;
    }
};

int main()
{
    Time a, b;
    a.settime(4, 50);
    b.settime(5, 10);

    Time c = a.sum(b);
    c.showtime();

    return 0;
}