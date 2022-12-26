#include <iostream>
using namespace std;

// Brute Force--
// Time Complexity--O(3^n)
int lcs(string s, string t)
{
    // Base Case--
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }

    // Reccursive Calls--
    if (s[0] == t[0])
    {
        return 1 + lcs(s.substr(1), t.substr(1));
    }

    int a = lcs(s.substr(1), t);
    int b = lcs(s, t.substr(1));
    int c = lcs(s.substr(1), t.substr(1));

    return max(a, max(b, c));
}

// Memoization Approach--
int lcs_2(string s, string t, int **arr, int m, int n)
{
    // Base Case--
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }

    // Check if ans already exist--
    if (arr[m][n] != -1)
    {
        return arr[m][n];
    }

    // Reccursive Calls--
    int ans;
    if (s[0] == t[0])
    {
        ans = 1 + lcs_2(s.substr(1), t.substr(1), arr, m - 1, n - 1);
    }
    else
    {
        int a = lcs_2(s.substr(1), t, arr, m - 1, n);
        int b = lcs_2(s, t.substr(1), arr, m, n - 1);
        int c = lcs_2(s.substr(1), t.substr(1), arr, m - 1, n - 1);
        ans = max(a, max(b, c));
    }

    // Save Calculation--
    arr[m][n] = ans;

    // Return ans
    return arr[m][n];
}
int lcs_2(string s, string t)
{
    int **arr = new int *[s.length() + 1];
    for (int i = 0; i <= s.length(); i++)
    {
        arr[i] = new int[t.length() + 1];
        for (int j = 0; j <= t.length(); j++)
        {
            arr[i][j] = -1;
        }
    }

    return lcs_2(s, t, arr, s.length(), t.length());
}

// Dynamic Programming--
int lcs_3(string s, string t)
{
    int **arr = new int *[s.length() + 1];
    for (int i = 0; i <= s.length(); i++)
    {
        arr[i] = new int[t.length() + 1];
    }

    // Top Element--
    arr[0][0] = 0;

    // Top Row(left to Right)--
    for (int i = 1; i <= t.length(); i++)
    {
        arr[0][i] = 0;
    }

    // First Column(top to bottom)--
    for (int i = 1; i <= s.length(); i++)
    {
        arr[i][0] = 0;
    }

    // Fill Remaining Cells--
    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 1; j <= t.length(); j++)
        {
            if (s[s.length() - i] == t[t.length() - j])
            {
                arr[i][j] = arr[i - 1][j - 1] + 1;
            }
            else
            {
                arr[i][j] = max(arr[i - 1][j - 1], max(arr[i][j - 1], arr[i - 1][j]));
            }
        }
    }

    return arr[s.length()][t.length()];
}

int main()
{
    string s, t;
    cin >> s >> t;

    cout << lcs_3(s, t) << endl;

    return 0;
}