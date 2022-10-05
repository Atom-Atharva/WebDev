#include <iostream>
using namespace std;

// Not a good method-

// int findDuplicate(int *arr, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (i != j)
//             {
//                 if (arr[i] == arr[j])
//                 {
//                     return arr[i];
//                 }
//             }
//         }
//     }
//     return -1;
// }

// Fast approach-

int findDuplicate(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    int smallsum = ((n - 2) * (n - 1)) / 2;
    return sum - smallsum;
}

int main()
{
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = findDuplicate(arr, n);
    cout << ans << endl;

    return 0;
}