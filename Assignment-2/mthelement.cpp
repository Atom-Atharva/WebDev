// P13. Write a program to “retrieve the mth element of a given stack from top ( m < size of
// stack), leaving the stack without its top m-1 elements”.

#include <iostream>
using namespace std;
#include "StackUsingLL.h"

int findmthelement(StackUsingLL<int> s1, int m)
{

    for (int i = 1; i < m; i++)
    {
        s1.pop();
    }
    int ans = s1.pop();
    s1.push(ans);
    return ans;
}

int main()
{
    StackUsingLL<int> s1;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        s1.push(element);
    }

    int m;
    cin >> m;

    cout << findmthelement(s1, m) << endl;

    return 0;
}