#include <iostream>
using namespace std;

int subsetSumToK(int *input, int n, int output[][50], int k)
{
    if (n == 0)
    {
        if (k == 0)
        {
            output[0][0] = 0;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int op1 = subsetSumToK(input + 1, n - 1, output, k);
    int op2 = subsetSumToK(input + 1, n - 1, output + op1, k - input[0]);

    for (int i = op1; i < op1 + op2; i++)
    {
        for (int j = output[i][0]; j >= 1; j--)
        {
            output[i][j + 1] = output[i][j];
        }
        output[i][1] = input[0];
        output[i][0]++;
    }
    return op1 + op2;
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

    int output[1000][50];

    int size = subsetSumToK(input, n, output, k);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}