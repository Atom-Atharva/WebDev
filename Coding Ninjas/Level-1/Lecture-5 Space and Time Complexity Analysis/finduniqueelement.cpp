#include <iostream>
using namespace std;

// Not good approach-

// int findUnique(int arr[], int n)
// {
//     int ans = -1;
//     for (int i = 0; i < n; i++)
//     {
//         bool check = false;

//         for (int j = 0; j < n; j++)
//         {
//             if (i != j)
//             {
//                 if (arr[j] == arr[i])
//                 {
//                     check = true;
//                     break;
//                 }
//             }
//         }
//         if (check == false)
//         {
//             ans = arr[i];
//         }
//     }
//     return ans;
// }

// XOR GATE-

int findUnique(int *arr, int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
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

    int ans = findUnique(arr, n);
    cout << ans << endl;

    return 0;
}