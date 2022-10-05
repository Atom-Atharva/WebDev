#include <iostream>
using namespace std;

int subset(int *input, int n, int output[][20])
{
    if (n == 0)
    {
        output[0][0] = 0;
        return 1;
    }
    int smallans = subset(input + 1, n - 1, output);
    for (int i = 0; i < smallans; i++)
    {
        for (int j = 1; j <= output[i][0] + 1; j++)
        {
            output[i + smallans][0] = output[i][0] + 1;
            output[i + smallans][1] = input[0];
            output[i + smallans][j + 1] = output[i][j];
        }
    }
    return 2 * smallans;
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
    int output[100][20];
    int ans = subset(input, n, output);

    for (int i = 0; i < ans; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    delete[] input;

    return 0;
}