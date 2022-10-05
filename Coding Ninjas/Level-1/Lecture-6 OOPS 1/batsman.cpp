#include <iostream>
using namespace std;

class Batsman
{
private:
    string bcode;
    char bname[20];
    int innings, notouts, runs;
    float batavg;
    float calavg()
    {
        return runs / (innings - notouts);
    }

public:
    void readdata()
    {
        cin >> bcode;
        cin >> bname;
        cin >> innings >> notouts >> runs;

        batavg = calavg();
    }
    void diplaydata()
    {
        cout << bcode;
        cout << endl;
        cout << bname << endl;
        cout << innings << endl
             << notouts << endl
             << runs << endl;
        cout << batavg << endl;
    }
};

int main()
{
    Batsman b;
    b.readdata();
    b.diplaydata();

    return 0;
}