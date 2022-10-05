#include <iostream>
using namespace std;
#include <stack>

int *stockSpan(int *price, int n)
{
    stack<int> s;
    s.push(0);

    int *ans = new int[n];
    ans[0] = 1;
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && price[s.top()] < price[i])
        {
            s.pop();
        }

        ans[i] = (s.empty()) ? i + 1 : (i - s.top());
        s.push(i);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int *price = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    int *stockSpanArr = new int[n];
    stockSpanArr = stockSpan(price, n);

    for (int i = 0; i < n; i++)
    {
        cout << stockSpanArr[i] << " ";
    }
    cout << endl;
    return 0;
}