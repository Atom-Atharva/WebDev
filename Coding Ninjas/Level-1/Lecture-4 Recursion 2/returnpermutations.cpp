#include <iostream>
using namespace std;

//Short METHOD--

// int fact(int n)
// {
//     if (n == 1)
//         return 1;

//     return n * fact(n - 1);
// }

// int returnPermutations(string input, string output[])
// {
//    
//     if (input.size() == 1)
//     {
//         output[0] = input[0];
//         return 1;
//     }
//     int small = 0;
//     for (int i = 0; i < input.size(); i++)
//     {
//         string s1 = input.substr(0, i);
//         string s2 = input.substr(i + 1);
//         int small = returnPermutations(s1 + s2, output + i * small);
//         for (int j = 0; j < small; j++)
//         {
//             output[j + i * small] = input[i] + output[j + i * small];
//         }
//     }
//     int size = input.size();
//     return fact(size);
// }

int returnPermutations(string input, string output[])
{
    if (input.size() == 1)
    {
        output[0] = input[0];
        return 1;
    }
    char c = input[0];
    int x = returnPermutations(input.substr(1), output);
    int k = 0;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < input.size(); j++)
        {
            output[j * x + i] = output[i];
        }
    }

    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < x; j++)
        {
            string s1 = output[i * x + j].substr(0, i);
            string s2 = output[i * x + j].substr(i);
            output[i * x + j] = s1 + c + s2;
        }
    }

    return x * input.size();
}

int main()
{
    string input;
    cin >> input;

    string output[10000];
    int size = returnPermutations(input, output);

    for (int i = 0; i < size; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}