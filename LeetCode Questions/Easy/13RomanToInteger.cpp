// https://leetcode.com/problems/roman-to-integer/description/

// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9.
// X can be placed before L (50) and C (100) to make 40 and 90.
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.

#include <iostream>
#include <climits>
using namespace std;
#include <unordered_map>

// Optimised Method--
class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> ele = {{'I', 1},
                                        {'V', 5},
                                        {'X', 10},
                                        {'L', 50},
                                        {'C', 100},
                                        {'D', 500},
                                        {'M', 1000}};

        int sum = ele[s.back()];
        for (int i = s.length() - 2; i >= 0; i--)
        {
            if (ele[s[i + 1]] > ele[s[i]])
            {
                sum = sum - ele[s[i]];
            }
            else
            {
                sum = sum + ele[s[i]];
            }
        }
        return sum;
    }
};

// Knife Method--
// class Solution
// {
//     int convert(char c)
//     {
//         if (c == 'I')
//         {
//             return 1;
//         }
//         else if (c == 'V')
//         {
//             return 5;
//         }
//         else if (c == 'X')
//         {
//             return 10;
//         }
//         else if (c == 'L')
//         {
//             return 50;
//         }
//         else if (c == 'C')
//         {
//             return 100;
//         }
//         else if (c == 'D')
//         {
//             return 500;
//         }
//         else if (c == 'M')
//         {
//             return 1000;
//         }
//         return INT_MIN;
//     }

// public:
//     int romanToInt(string s)
//     {
//         int sum = 0;
//         int n = s.length();
//         for (int i = 0; i < n; i++)
//         {
//             // Search for Roman Numerals--
//             if (s[i] == 'I')
//             {
//                 if (s[i + 1] == 'V' || s[i + 1] == 'X')
//                 {
//                     sum = sum + convert(s[i + 1]) - 1;
//                     i++;
//                 }
//                 else
//                     sum += convert(s[i]);
//             }
//             else if (s[i] == 'X')
//             {
//                 if (s[i + 1] == 'L' || s[i + 1] == 'C')
//                 {
//                     sum += convert(s[i + 1]) - 10;
//                     i++;
//                 }
//                 else
//                     sum += convert(s[i]);
//             }
//             else if (s[i] == 'C')
//             {
//                 if (s[i + 1] == 'M' || s[i + 1] == 'D')
//                 {
//                     sum += convert(s[i + 1]) - 100;
//                     i++;
//                 }
//                 else
//                     sum += convert(s[i]);
//             }
//             else
//             {
//                 sum += convert(s[i]);
//             }
//         }
//         return sum;
//     }
// };