// https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1

// Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers. Return in increasing order.

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

//********************** IMPORTANT QUESTION *******************************//

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        // Take XOR of all elements--
        int element_XOR = 0;
        for (auto itr : nums)
        {
            element_XOR = element_XOR ^ itr;
            cout << itr << endl;
        }

        // Take Out Right-most Set BIT--
        /*
            Steps--
                1. Take out element-1
                2. Invert it
                3. And with Original Element
        */
        element_XOR = element_XOR & ~(element_XOR - 1);

        // We Know,
        // XOR of 2 element is 1 when either of them is 1 and other is 0,
        // Thus with right most set bit we make 2 groups of elements giving 0 and 1 on & with Rightmost bit.
        vector<int> group1;
        vector<int> group2;

        for (auto itr : nums)
        {
            if ((itr & element_XOR) == 0)
            {
                group1.push_back(itr);
            }
            else
            {
                group2.push_back(itr);
            }
        }

        // Now we need to find unique element from each group.
        int unique1 = 0, unique2 = 0;
        for (auto itr : group1)
        {
            unique1 = unique1 ^ itr;
        }
        for (auto itr : group2)
        {
            unique2 = unique2 ^ itr;
        }

        // Insert Answer in increasing order.
        vector<int> ans;
        ans.push_back(min(unique1, unique2));
        ans.push_back(max(unique1, unique2));

        return ans;
    }
};

// Wrong Answer: Answer should be in increasing order--
// Brute Force--
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        // Set in Map--
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++)
        {
            seen[nums[i]]++;
        }

        // Check Single Elements--
        vector<int> ans;
        for (auto itr : seen)
        {
            if (itr.second == 1)
            {
                ans.push_back(itr.first);
            }
        }

        return ans;
    }
};