// https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

// You are given a string s. You need to reverse the string.

#include <iostream>
using namespace std;

string reverseWord(string str)
{
    int len = str.length();
    for (int i = 0; i < len / 2; i++)
    {
        char c = str[i];
        str[i] = str[len - 1 - i];
        str[len - i - 1] = c;
    }

    return str;
}