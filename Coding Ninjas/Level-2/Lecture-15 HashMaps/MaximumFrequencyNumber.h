#include <iostream>
using namespace std;
#include <unordered_map>

int highestFrequency(int arr[], int n)
{
    unordered_map<int, int> frequency;
    int maxfrequency = 1;
    for (int i = 0; i < n; i++)
    {
        if (frequency.count(arr[i]) > 0)
        {
            frequency[arr[i]]++;
            if (maxfrequency < frequency[arr[i]])
            {
                maxfrequency = frequency[arr[i]];
            }
            continue;
        }
        frequency[arr[i]] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (frequency[arr[i]] == maxfrequency)
        {
            return arr[i];
        }
    }
    return -1;
}