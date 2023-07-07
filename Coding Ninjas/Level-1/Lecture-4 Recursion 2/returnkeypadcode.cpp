#include <iostream>
using namespace std;

// Solved by 2 methods--

// string getString(int d)
// {
//     if(d==2)
//     {
//         return "abc";
//     }
//      if(d==3)
//     {
//         return "def";
//     }
//     if(d==4)
//     {
//         return "ghi";
//     }
//     if(d==5)
//     {
//         return "jkl";
//     }
//     if(d==6)
//     {
//         return "mno";
//     }
//     if(d==7)
//     {
//         return "pqrs";
//     }
//     if(d==8)
//     {
//         return "tuv";
//     }
//     if(d==9)
//     {
//         return "wxyz";
//     }
//     return "";
// }

int keypad(int num, string output[])
{
    if (num == 0)
    {
        output[0] = "";
        return 1;
    }
    int smallout = keypad(num / 10, output);

    int n = num % 10;
    //    string options=getString(n);

    //     for(int i=0;i<options.size()-1;i++){
    //         for(int j=0;j<smallout;j++){
    //             output[j+(i+1)*smallout]=output[j];
    //         }
    //     }

    //     int k=0;
    //     for(int i=0;i<options.size();i++){
    //         for(int j=0;j<smallout;j++){
    //             output[k]=output[k]+options[i];
    //             k++;
    //         }
    //     }
    //     return smallout*options.size();

    switch (n)
    {
    case 2:

        for (int i = 0; i < smallout; i++)
        {

            output[i + smallout] = output[i] + 'a';
            output[i + 2 * smallout] = output[i] + 'b';
            output[i] = output[i] + 'c';
        }
        return smallout * 3;

    case 3:
        for (int i = 0; i < smallout; i++)
        {
            output[i + smallout] = output[i] + 'd';
            output[i + 2 * smallout] = output[i] + 'e';
            output[i] = output[i] + 'f';
        }
        return smallout * 3;

    case 4:
        for (int i = 0; i < smallout; i++)
        {
            output[i + smallout] = output[i] + 'g';
            output[i + 2 * smallout] = output[i] + 'h';
            output[i] = output[i] + 'i';
        }
        return smallout * 3;

    case 5:
        for (int i = 0; i < smallout; i++)
        {
            output[i + smallout] = output[i] + 'j';
            output[i + 2 * smallout] = output[i] + 'k';
            output[i] = output[i] + 'l';
        }
        return smallout * 3;

    case 6:
        for (int i = 0; i < smallout; i++)
        {
            output[i + smallout] = output[i] + 'm';
            output[i + 2 * smallout] = output[i] + 'n';
            output[i] = output[i] + 'o';
        }
        return smallout * 3;

    case 7:
        for (int i = 0; i < smallout; i++)
        {
            output[i + smallout] = output[i] + 'p';
            output[i + 2 * smallout] = output[i] + 'q';
            output[i + 3 * smallout] = output[i] + 'r';
            output[i] = output[i] + 's';
        }
        return smallout * 4;

    case 8:
        for (int i = 0; i < smallout; i++)
        {
            output[i + smallout] = output[i] + 't';
            output[i + 2 * smallout] = output[i] + 'u';
            output[i] = output[i] + 'v';
        }
        return smallout * 3;

    case 9:
        for (int i = 0; i < smallout; i++)
        {
            output[i + smallout] = output[i] + 'w';
            output[i + 2 * smallout] = output[i] + 'x';
            output[i + 3 * smallout] = output[i] + 'y';
            output[i] = output[i] + 'z';
        }
        return smallout * 4;
    }
}

int main()
{

    int num;
    cin >> num;

    string output[1000];
    int ans = keypad(num, output);
    
    for (int i = 0; i < ans; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}