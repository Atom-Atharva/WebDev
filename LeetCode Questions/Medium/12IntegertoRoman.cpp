// https://leetcode.com/problems/integer-to-roman/

// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9.
// X can be placed before L (50) and C (100) to make 40 and 90.
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given an integer, convert it to a roman numeral.

#include <iostream>
using namespace std;

// Optimized Solution--
// Time Complexity--O(1);
string intToRoman(int num)
{
    string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string hrns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string ths[] = {"", "M", "MM", "MMM"};

    return ths[num / 1000] + hrns[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
}

// Naive Solution--
// Time Complexity--O(num);
// string intToRoman(int num)
// {
//     string ans = "";
//     while (num > 0)
//     {
//         if (num / 1000 > 0)
//         {
//             ans += "M";
//             num = num - 1000;
//         }
//         else if (num / 500 > 0)
//         {
//             if (num - 500 >= 400)
//             {
//                 ans += "CM";
//                 num = num - 900;
//                 continue;
//             }
//             ans += "D";
//             num = num - 500;
//         }
//         else if (num / 100 > 0)
//         {
//             if (num - 100 >= 300)
//             {
//                 ans += "CD";
//                 num = num - 400;
//                 continue;
//             }
//             ans += "C";
//             num = num - 100;
//         }
//         else if (num / 50 > 0)
//         {
//             if (num - 50 >= 40)
//             {
//                 ans += "XC";
//                 num = num - 90;
//                 continue;
//             }
//             ans += "L";
//             num = num - 50;
//         }
//         else if (num / 10 > 0)
//         {
//             if (num - 10 >= 30)
//             {
//                 ans += "XL";
//                 num = num - 40;
//                 continue;
//             }
//             ans += "X";
//             num = num - 10;
//         }
//         else if (num / 5 > 0)
//         {
//             if (num - 5 >= 4)
//             {
//                 ans += "IX";
//                 num = num - 9;
//                 continue;
//             }
//             ans += "V";
//             num = num - 5;
//         }
//         else if (num / 1 > 0)
//         {
//             if (num - 1 >= 3)
//             {
//                 ans += "IV";
//                 num = num - 4;
//                 continue;
//             }
//             ans += "I";
//             num = num - 1;
//         }
//     }
//     return ans;
// }

int main()
{
    int num;
    cin >> num;

    string ans = intToRoman(num);
    cout << ans << endl;

    return 0;
}