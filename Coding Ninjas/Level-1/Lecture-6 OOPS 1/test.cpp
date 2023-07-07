#include <iostream>
using namespace std;

class Test
{
private:
    int tcode;
    string des;
    int nocand;
    int cenreq;
    void calcantr()
    {
        cenreq = nocand / 100 + 1;
        return;
    }

public:
    void schedule()
    {
        cin >> tcode >> des >> nocand >> cenreq;
        calcantr();
    }

    void disptest()
    {
        cout << cenreq << tcode << des << endl;
    }
};

int main()
{
    Test t;
    t.schedule();
    t.disptest();
    return 0;
}