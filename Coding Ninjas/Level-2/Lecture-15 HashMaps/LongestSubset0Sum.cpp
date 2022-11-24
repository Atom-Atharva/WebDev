#include <iostream>
using namespace std;
#include <unordered_map>

int lengthOfLongestSubsetWithZeroSum(int *arr, int n)
{
    int maxlength = 0;
    int currsum = 0;
    unordered_map<int, int> sumindex;
    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];
        if (arr[i] == 0 && maxlength == 0)
        {
            maxlength = 1;
            continue;
        }

        if (currsum == 0)
        {
            maxlength = i + 1;
        }
        if (sumindex.count(currsum) > 0)
        {
            if (maxlength < i - sumindex[currsum])
            {
                maxlength = i - sumindex[currsum];
            }
        }
        sumindex[currsum] = i;
    }
    return maxlength;
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

    cout << lengthOfLongestSubsetWithZeroSum(arr, n) << endl;

    return 0;
}