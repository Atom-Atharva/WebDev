#include <iostream>
using namespace std;

void printSubset(int *input, int n, int *output, int ans)
{
    if (n == 0)
    {
        for (int i = 0; i < ans; i++)
        {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }
    printSubset(input + 1, n - 1, output, ans);

    output[ans] = input[0];
    printSubset(input + 1, n - 1, output, ans + 1);

    return;
}

void printSubsetOfArray(int *input, int n)
{
    int output[100], ans = 0;
    printSubset(input, n, output, ans);
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

    printSubsetOfArray(input, n);

    return 0;
}