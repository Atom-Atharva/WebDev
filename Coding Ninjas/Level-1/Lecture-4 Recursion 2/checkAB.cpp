#include <iostream>
using namespace std;

bool checkAB(char input[])
{
    
    if (input[0] == '\0')
    {
        return true;
    }
     if (input[0] != 'a')
    {
        return false;
    }
     if (input[1] == 'b' && input[2] == 'b')
        {
                return checkAB(input+3);
        }
        return checkAB(input+1);
}

//wrong method

// bool checkAB(char str[])
// {
//     if (str[0] == '\0')
//     {
//         return true;
//     }

//     char temp = str[0];
//     if (temp == 'a')
//     {
//         if (str[1] == 'a' || str[1] == 'b' || str[1] == '\0')
//         {
//             return checkAB(str + 1);
//         }
//         else
//         {
//             return false;
//         }
//     }
//     if (temp == 'b')
//     {
//         if (str[1] == 'b' && (str[2] == 'a' || str[2] == '\0'))
//         {
//             return checkAB(str + 2);
//         }
//         else
//         {
//             return false;
//         }
//     }
// }

int main()
{

    char str[100];
    cin >> str;

    if (checkAB(str))
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}