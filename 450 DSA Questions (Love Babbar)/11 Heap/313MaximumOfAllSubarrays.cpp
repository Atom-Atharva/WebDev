// https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1

// Due to the rise of covid-19 cases in India, this year BCCI decided to organize knock-out matches in IPL rather than a league.

// Today is matchday 2 and it is between the most loved team Chennai Super Kings and the most underrated team - Punjab Kings. Stephen Fleming, the head coach of CSK, analyzing the batting stats of Punjab. He has stats of runs scored by all N players in the previous season and he wants to find the maximum score for each and every contiguous sub-list of size K to strategize for the game.

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

// Method 2:
class Solution
{
public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k)
    {
        vector<int> ans;
        priority_queue<pair<int, int>> maxHeap;

        // Insert in Window--
        for (int i = 0; i < k; i++)
        {
            maxHeap.push({arr[i], i});
        }

        // Initialise first Window--
        ans.push_back(maxHeap.top().first);

        for (int i = k; i < n; i++)
        {
            // Insert in MaxHeap--
            maxHeap.push({arr[i], i});

            // Remove Out of Range Elements--
            while (maxHeap.top().second < i - k)
            {
                maxHeap.pop();
            }

            // Push in Answer--
            ans.push_back(maxHeap.top().first);
        }

        return ans;
    }
};

// Method 1:
// Time Limit Exceeded O(n^2)--
// class Solution
// {
// public:
//     vector<int> max_of_subarrays(vector<int> arr, int n, int k)
//     {
//         vector<int> ans;
//         priority_queue<int> pq;

//         // Insert in Window--
//         for (int i = 0; i < k; i++)
//         {
//             pq.push(arr[i]);
//         }

//         // Initialise first Window--
//         ans.push_back(pq.top());

//         for (int i = k; i < n; i++)
//         {
//             queue<int> temp;
//             // Remove First Outgoing--
//             bool remove = false;
//             while (!pq.empty())
//             {
//                 if (pq.top() == arr[i - k] && remove == false)
//                 {
//                     pq.pop();
//                     remove = true;
//                     continue;
//                 }

//                 temp.push(pq.top());
//                 pq.pop();
//             }

//             while (!temp.empty())
//             {
//                 pq.push(temp.front());
//                 temp.pop();
//             }

//             // Insert new Element--
//             pq.push(arr[i]);

//             // Maximum of that Window--
//             ans.push_back(pq.top());
//         }

//         return ans;
//     }
// };
