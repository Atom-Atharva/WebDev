// https://leetcode.com/problems/palindrome-number/

// Given an integer x, return true if x is a palindrome, and false otherwise.

// Optimized Method--
class Solution
{
public:
    // Half number Reverse then compare --> no overflow;
    bool isPalindrome(int x)
    {
        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;

        int sum = 0;
        while (x > sum)
        {
            sum = sum * 10 + x % 10;
            x = x / 10;
        }
        return (x == sum) || (x == sum / 10);
    }
};

// Knife Method--
//  class Solution
//  {
//  public:
//      bool isPalindrome(int x)
//      {
//          if (x < 0)
//          {
//              return false;
//          }
//          long long int a = (long long int)x;
//          long long int b = 0;
//          while (a > 0)
//          {
//              b = b * 10 + a % 10;
//              a = a / 10;
//          }

//         if (b == (long long int)x)
//         {
//             return true;
//         }
//         return false;
//     }
// };