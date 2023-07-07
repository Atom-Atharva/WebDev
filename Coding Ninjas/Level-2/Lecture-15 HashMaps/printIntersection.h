#include <iostream>
using namespace std;
#include <unordered_map>

void printIntersection(int arr1[], int arr2[], int n, int m)
{
    unordered_map<int, int> seen;
    for (int i = 0; i < n; i++)
    {
        if (seen.count(arr1[i]) > 0)
        {
            seen[arr1[i]]++;
            continue;
        }
        seen[arr1[i]] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        if (seen.count(arr2[i]) > 0 && seen[arr2[i]] != 0)
        {
            seen[arr2[i]]--;
            cout << arr2[i] << endl;
        }
    }

    return;
}
