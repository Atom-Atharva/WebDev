#include <iostream>
using namespace std;

// Brute Force--
int editDistance(string s, string t)
{
    // Base Case--
    if (s.length() == 0 || t.length() == 0)
    {
        return max(s.length(), t.length());
    }

    // Reccursive Call--
    if (s[0] == t[0])
    {
        return editDistance(s.substr(1), t.substr(1));
    }

    // Add--
    int a = editDistance(s.substr(1), t);

    // Delete--
    int b = editDistance(s, t.substr(1));

    // Update--
    int c = editDistance(s.substr(1), t.substr(1));

    // Small Calculation--
    return 1 + min(a, min(b, c));
}

// Memoization Approach--
int editDistance_2(string s, string t, int **output)
{
    int m = s.length();
    int n = t.length();

    // Base Case--
    if (s.length() == 0 || t.length() == 0)
    {
        return max(s.length(), t.length());
    }

    // Check if the solution exist--
    if (output[m][n] != -1)
    {
        return output[m][n];
    }

    int ans;
    if (s[0] == t[0])
    {
        ans = editDistance_2(s.substr(1), t.substr(1), output);
    }
    else
    {
        // Add--
        int a = editDistance_2(s.substr(1), t, output);

        // Delete--
        int b = editDistance_2(s, t.substr(1), output);

        // Update--
        int c = editDistance_2(s.substr(1), t.substr(1), output);

        ans = 1 + min(a, min(b, c));
    }

    // Save ans for future use--
    output[m][n] = ans;
    return ans;
}
int editDistance_2(string s, string t)
{
    int **output = new int *[s.length() + 1];
    for (int i = 0; i <= s.length(); i++)
    {
        output[i] = new int[t.length() + 1];
        for (int j = 0; j <= t.length(); j++)
        {
            output[i][j] = -1;
        }
    }
    return editDistance_2(s, t, output);
}

// Dynamic Progromming--
int editDistance_3(string s, string t)
{
    int m = s.length();
    int n = t.length();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
    }

    // Fill the Topest(intial) Cell--
    output[0][0] = 0;

    // Fill the top row(left to right)--
    for (int j = 1; j <= n; j++)
    {
        output[0][j] = j;
    }

    // Fill the first coloumn(top to bottom)--
    for (int i = 1; i <= m; i++)
    {
        output[i][0] = i;
    }

    // Fill the remaining cells--
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[m - i] == t[n - j])
            {
                output[i][j] = output[i - 1][j - 1];
            }
            else
            {
                output[i][j] = min(output[i - 1][j - 1], min(output[i - 1][j], output[i][j - 1])) + 1;
            }
        }
    }

    return output[m][n];
}

int main()
{
    string s, t;
    cin >> s >> t;

    cout << editDistance(s, t) << endl;
    cout << editDistance_2(s, t) << endl;
    cout << editDistance_3(s, t) << endl;

    return 0;
}