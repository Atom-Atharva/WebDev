#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    unordered_map<int, bool> seen;
    unordered_map<int, int> index;
    for (int i = 0; i < n; i++)
    {
        seen[arr[i]] = 1;
        if (index.count(arr[i]) > 0)
        {
            continue;
        }
        index[arr[i]] = i;
    }
    int max = 0;
    vector<int> output;
    int longestStart = 0;

    for (int i = 0; i < n; i++)
    {
        if (seen[arr[i]] == 0)
        {
            continue;
        }

        int smallmax = 0;
        vector<int> ans;
        int element = arr[i];
        while (seen.count(element) > 0)
        {
            seen[element] = 0;
            smallmax++;
            element++;
        }
        ans.push_back(element - 1);
        int currStart = i;

        element = arr[i] - 1;
        while (seen.count(element) > 0)
        {
            seen[element] = 0;
            smallmax++;
            currStart = index[element];
            element--;
        }
        if (element + 1 != ans[0])
        {
            ans.insert(ans.begin(), element + 1);
        }

        if (smallmax > max)
        {
            max = smallmax;
            output = ans;
            longestStart = currStart;
        }
        else if (smallmax == max)
        {
            if (currStart < longestStart)
            {
                output = ans;
                longestStart = currStart;
            }
        }
    }
    return output;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}