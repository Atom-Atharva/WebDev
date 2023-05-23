// https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/

// An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    // Time Complexity: O(n)--
    void allNegativeOneSide(vector<int> &nums)
    {
        // Length of array--
        int len = nums.size();

        // Two Pointer Approach--
        int pos = 0;
        for (int i = 0; i < len; i++)
        {
            // If negative element--
            if (nums[i] < 0)
            {
                // Swap--
                int temp = nums[i];
                nums[i] = nums[pos];
                nums[pos] = temp;
                pos++;
            }
        }

        return;
    }
};

int main()
{
    // code
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;

        nums.push_back(ele);
    }

    Solution sol;
    sol.allNegativeOneSide(nums);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}