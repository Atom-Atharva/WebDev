#include <iostream>
using namespace std;
#include <unordered_map>

int pairSum(int *arr, int n)
{
    unordered_map<int, int> seen;
    int pairs = 0;
    for (int i = 0; i < n; i++)
    {
        if (seen.count(-(arr[i])) > 0)
        {
            pairs = pairs + seen[-(arr[i])];
        }
        if (seen.count(arr[i]) > 0)
        {
            seen[arr[i]]++;
            continue;
        }
        seen[arr[i]] = 1;
    }
    return pairs;
}