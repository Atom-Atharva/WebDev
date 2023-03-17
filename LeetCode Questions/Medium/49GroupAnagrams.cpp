// https://leetcode.com/problems/group-anagrams/

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    // Optimized Approach--
    //Time Complexity O(nk)
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> groups;
        vector<vector<string>> ans;

        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());

            // Check if temp is present in map--
            // if(groups.count(temp)>0){
            //     groups[temp].push_back(strs[i]);
            //     continue;
            // }

            groups[temp].push_back(strs[i]);
        }

        for (auto iterator : groups)
        {
            ans.push_back(iterator.second);
        }
        return ans;
    }

    // Naive Solution--
    // Time Complexity O(n3)--
    // vector<vector<string>> groupAnagrams(vector<string> &strs)
    // {
    //     bool arr[strs.size()];
    //     for (int i = 0; i < strs.size(); i++)
    //     {
    //         arr[i] = false;
    //     }
    //     vector<vector<string>> ans;

    //     // Itterate Over each element--
    //     for (int i = 0; i < strs.size(); i++)
    //     {
    //         // Check if it has been used--
    //         if (arr[i] == true)
    //         {
    //             continue;
    //         }

    //         vector<string> grp;
    //         grp.push_back(strs[i]);

    //         // Add in seen list;
    //         unordered_map<char, int> seen;
    //         for (int j = 0; j < strs[i].size(); j++)
    //         {
    //             seen[strs[i][j]]++;
    //         }

    //         // Check for anagrams--
    //         for (int j = i + 1; j < strs.size(); j++)
    //         {
    //             unordered_map<char, int> cmp;
    //             for (int k = 0; k < strs[j].size(); k++)
    //             {
    //                 cmp[strs[j][k]]++;
    //             }

    //             if (cmp == seen)
    //             {
    //                 grp.push_back(strs[j]);
    //                 arr[j] = true;
    //             }
    //         }

    //         ans.push_back(grp);

    //         // Mark Used--
    //         arr[i] = true;
    //     }
    //     return ans;
    // }
};