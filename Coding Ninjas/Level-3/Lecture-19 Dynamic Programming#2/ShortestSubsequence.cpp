#include <iostream>
using namespace std;
#include <climits>

// Dynamic Programming--
class Method3
{
public:
    // Wrong Approach--
    //  int solve(string s, string v)
    // {
    //     // Dynamic Array--
    //     int **dp = new int *[s.length() + 1];
    //     for (int i = 0; i <= s.length(); i++)
    //     {
    //         dp[i] = new int[v.length() + 1];
    //     }

    //     // Fill First Cell--
    //     dp[0][0] = 1001;

    //     // Fill First Row--
    //     for (int i = 1; i <= v.length(); i++)
    //     {
    //         dp[0][i] = 1001;
    //     }

    //     // Fill First Column--
    //     for (int i = 1; i <= s.length(); i++)
    //     {
    //         dp[i][0] = 1;
    //     }

    //     // Fill Rest of the cells--
    //     for (int i = 1; i <= s.length(); i++)
    //     {
    //         for (int j = 1; j <= v.length(); j++)
    //         {
    //             int refuse = dp[i - 1][j];

    //             // Search for element in v string--
    //             int pos = 0;
    //             for (int k = j; k <= v.length(); k++)
    //             {
    //                 if (v[k] == s[i])
    //                 {
    //                     break;
    //                 }
    //                 pos++;
    //             }
    //             if (pos == v.length())
    //             {
    //                 dp[i][j] = 1;
    //                 continue;
    //             }
    //             int take = 1 + dp[i - 1][j - pos - 1];

    //             dp[i][j] = min(refuse, take);
    //         }
    //     }
    //     return dp[s.length()][v.length()];
    // }
};

// Memomization--
class Method2
{
    int solve(string s, string v, int sf, int vf, int **dp)
    {
        // Base Case--
        if (v.length() == vf)
        {
            return 1;
        }
        if (s.length() == sf)
        {
            return 1001;
        }
        if (dp[sf][vf] != -1)
        {
            return dp[sf][vf];
        }

        // Reccursive Calls--
        int refuse = solve(s, v, sf + 1, vf, dp);

        // Search for element in v string--
        int pos = 0;
        for (int i = vf; i < v.length(); i++)
        {
            if (v[i] == s[sf])
            {
                break;
            }
            pos++;
        }
        if (pos == v.length())
        {
            return dp[sf][vf] = 1;
        }
        int take = 1 + solve(s, v, sf + 1, vf + pos + 1, dp);

        return dp[sf][vf] = min(refuse, take);
    }

public:
    int solve(string s, string v)
    {
        int **dp = new int *[s.length()];
        for (int i = 0; i < s.length(); i++)
        {
            dp[i] = new int[v.length()];
            for (int j = 0; j < v.length(); j++)
            {
                dp[i][j] = -1;
            }
        }
        return solve(s, v, 0, 0, dp);
    }
};

// Reccursion--
class Method1
{
public:
    int solve(string s, string v, int sf = 0, int vf = 0)
    {
        // Base Case--
        if (v.length() == vf)
        {
            return 1;
        }
        if (s.length() == sf)
        {
            return 1001;
        }

        // Reccursive Calls--
        int refuse = solve(s, v, sf + 1, vf);

        // Search for element in v string--
        int pos = 0;
        for (int i = vf; i < v.length(); i++)
        {
            if (v[i] == s[sf])
            {
                break;
            }
            pos++;
        }
        if (pos == v.length())
        {
            return 1;
        }
        int take = 1 + solve(s, v, sf + 1, vf + pos + 1);

        return min(refuse, take);
    }
};
