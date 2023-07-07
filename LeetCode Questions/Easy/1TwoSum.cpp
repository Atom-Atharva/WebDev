// https://leetcode.com/problems/two-sum/

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:

    // Optimum Solution--
    // TimeComplexity-- O(n)
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        // Key is the number and value is its index in the vector.
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++)
        {
            int numberToFind = target - numbers[i];

            // if numberToFind is found in map, return them
            if (hash.find(numberToFind) != hash.end())
            {
                //+1 because indices are NOT zero based
                result.push_back(hash[numberToFind] + 1);
                result.push_back(i + 1);
                return result;
            }

            // number was not found. Put it in the map.
            hash[numbers[i]] = i;
        }
        return result;
    }

    // Naive Solution--
    // Time Complexity-- O(n)
    // vector<int> twoSum(vector<int> &arr, int target)
    // {
    //     unordered_map<int, pair<int, int>> seen;
    //     for (int i = 0; i < arr.size(); i++)
    //     {
    //         if (seen.count(arr[i]) > 0)
    //         {
    //             seen[arr[i]].first++;
    //             seen[arr[i]].second = i;
    //             continue;
    //         }
    //         seen[arr[i]].first = 1;
    //         seen[arr[i]].second = i;
    //     }

    //     vector<int> ans;
    //     for (int i = 0; i < arr.size(); i++)
    //     {
    //         int left = target - arr[i];
    //         if (left == arr[i])
    //         {
    //             if (seen.count(arr[i]) > 0 && seen[arr[i]].first > 1)
    //             {
    //                 ans.push_back(i);
    //                 ans.push_back(seen[arr[i]].second);
    //                 seen[arr[i]].first--;
    //             }
    //         }
    //         else if (seen.count(left) > 0 && seen[left].first > 0)
    //         {
    //             ans.push_back(i);
    //             ans.push_back(seen[left].second);
    //             seen[arr[i]].first--;
    //         }
    //     }
    //     return ans;
    // }
};