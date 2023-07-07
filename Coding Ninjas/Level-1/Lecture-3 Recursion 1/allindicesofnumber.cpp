#include <iostream>
using namespace std;

// Method-1:(Easier)

// int allIndexes(int input[], int n, int x, int output[])
// {
//     if (n == 0)
//     {
//         return 0;
//     }

//     int smallout = allIndexes(input, n - 1, x, output);
//     if (input[n - 1] == x)
//     {
//         output[smallout] = n - 1;
//         return ++smallout;
//     }
//     else
//     {
//         return smallout;
//     }
// }

// Method-2:

int allIndexes(int input[], int n, int x, int output[])
{
    if (n == 0)
    {
        return 0;
    }

    int smallout = allIndexes(input + 1, n - 1, x, output);
    for (int i = 0; i < smallout; i++)
    {
        output[i]++;
    }

    if (input[0] == x)
    {
        smallout++;
        for (int i = smallout - 1; i > 0; i--)
        {
            output[i] = output[i - 1];
        }
        output[0] = 0;
        return smallout;
    }
    else
    {
        return smallout;
    }
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int x;
    cin >> x;

    int *output = new int[n];

    int m = allIndexes(input, n, x, output);

    for (int i = 0; i < m; i++)
    {
        cout << output[i] << " ";
    }

    delete[] input;
    delete[] output;

    return 0;
}