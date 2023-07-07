#include <iostream>
using namespace std;

void printSubset(int *input, int n, int st, int k, int *output, int m)
{
    if (st == n)
    {
        if (k == 0)
        {
            for (int i = 0; i < m; i++)
            {
                cout << output[i] << " ";
            }
            cout << endl;
            return;
        }
        else
        {
            return;
        }
    }
    printSubset(input, n, st + 1, k, output, m);

    int newoutput[50];
    newoutput[m] = input[st];
    for (int i = 0; i < m; i++)
    {
        newoutput[i] = output[i];
    }

    printSubset(input, n, st + 1, k - input[st], newoutput, m + 1);
    return;
}

void printSubsetSumToK(int *input, int n, int k)
{
    int st = 0;
    int output[100], m = 0;
    printSubset(input, n, st, k, output, m);
    return;
}

int main()
{
    int n;
    cin >> n;

    int input[100];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int k;
    cin >> k;

    printSubsetSumToK(input, n, k);

    return 0;
}