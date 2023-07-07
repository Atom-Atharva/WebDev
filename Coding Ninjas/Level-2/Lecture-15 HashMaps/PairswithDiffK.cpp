#include <iostream>
using namespace std;
#include <unordered_map>

int getPairsWithDifferenceK(int *arr, int n, int k)
{
    unordered_map<int, int> freq;
    int pairs = 0;

    // Jab tak complement hoga hi nahi tab tak if else chalenge hi nahi--

    for (int i = 0; i < n; i++)
    {
        int pair1 = arr[i] + k;
        if (freq.count(pair1) > 0)
        {
            pairs = pairs + freq[pair1];
        }

        if (k != 0)
        {
            int pair2 = arr[i] - k;
            if (freq.count(pair2) > 0)
            {
                pairs = pairs + freq[pair2];
            }
        }

        freq[arr[i]]++;
    }

    return pairs;

    // unordered_map<int, int> seen;
    // for (int i = 0; i < n; i++)
    // {
    //     if (seen.count(arr[i]) > 0)
    //     {
    //         seen[arr[i]]++;
    //         continue;
    //     }
    //     seen[arr[i]] = 1;
    // }

    // int pairs = 0;
    // Iterating over array causes more time for searching--

    // for (int i = 0; i < n; i++)
    // {
    //     if (seen.count(k + arr[i]) > 0)
    //     {
    //         if (seen[k + arr[i]] > 0)
    //         {
    //             seen[arr[i]]--;

    //             pairs = pairs + seen[k + arr[i]];
    //         }
    //     }
    //     if (k == 0)
    //     {
    //         continue;
    //     }
    //     if (seen.count(arr[i] - k) > 0)
    //     {
    //         if (seen[arr[i] - k] > 0)
    //         {

    //             seen[arr[i]]--;
    //             pairs = pairs + seen[arr[i] - k];
    //         }
    //     }
    // }

    // return pairs;
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

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(arr, n, k);

    return 0;
}