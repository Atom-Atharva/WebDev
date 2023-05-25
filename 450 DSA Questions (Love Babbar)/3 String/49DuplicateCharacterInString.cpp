// https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/

// Write an efficient program to print all the duplicates and their counts in the input string

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    vector<pair<char, int>> findDuplicateCount(string s)
    {
        unordered_map<char, int> counts;
        for (int i = 0; i < s.length(); i++)
        {
            if (counts.count(s[i]) > 0)
            {
                counts[s[i]]++;
            }
            else
            {
                counts[s[i]] = 1;
            }
        }

        vector<pair<char, int>> ans;
        for (auto i : counts)
        {
            pair<char, int> p;
            if (i.second > 1)
            {
                p.first = i.first;
                p.second = i.second;

                ans.push_back(p);
            }
        }
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution obj;
    vector<pair<char, int>> ans = obj.findDuplicateCount(s);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}