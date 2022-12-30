// https://leetcode.com/problems/longest-common-prefix/

// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// Optimized Method--
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
        {
            return "";
        }
        string ans = "";
        sort(strs.begin(), strs.end());

        for (int i = 0; i < strs[0].size(); i++)
        {
            if (strs[0][i] != strs[strs.size() - 1][i])
            {
                return ans;
            }
            else
            {
                ans = ans + strs[0][i];
            }
        }
        return ans;
    }
};

//  Naive Method--
//  class Solution
//  {
//  public:
//      string longestCommonPrefix(vector<string> &strs)
//      {
//          string ans = "";
//          for (int i = 0; i < strs[0].size(); i++)
//          {
//              for (int j = 1; j < strs.size(); j++)
//              {
//                  if (strs[j][i] != strs[0][i])
//                  {
//                      return ans;
//                  }
//              }
//              ans += strs[0][i];
//          }
//          return ans;
//      }
//  };