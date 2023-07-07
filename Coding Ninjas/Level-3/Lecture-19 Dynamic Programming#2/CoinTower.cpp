#include <iostream>
using namespace std;
#include <vector>

class Method3
{
public:
    string findWinner(int n, int x, int y)
    {
        // Dynamic Array--
        int **dp = new int *[2];
        for (int i = 0; i < 2; i++)
        {
            dp[i] = new int[n + 1];
        }

        // Fill Initial Cell--
        dp[0][0] = 1;
        dp[1][0] = 0;

        // Fill Second Column--
        dp[0][1] = 0;
        dp[1][1] = 1;

        // Fill Remaining Cells--
        for (int j = 2; j <= n; j++)
        {
            for (int i = 0; i < 2; i++)
            {
                int oneOut = dp[(i + 1) % 2][j - 1];
                int xOut;
                if (j - x < 0)
                {
                    xOut = -1;
                }
                else
                {
                    xOut = dp[(i + 1) % 2][j - x];
                }
                int yOut;
                if (j - y < 0)
                {
                    yOut = -1;
                }
                else
                {
                    yOut = dp[(i + 1) % 2][j - y];
                }

                // Who Wins?
                if (oneOut == i || xOut == i || yOut == i)
                {
                    dp[i][j] = i;
                }
                else
                {
                    dp[i][j] = (i + 1) % 2;
                }
            }
        }

        // Out Winner When Beerus Turn--
        if (dp[1][n] == 1)
        {
            return "Beerus";
        }
        return "Whis";
    }
};

// Memomization--
class Method2
{
    string winner(int n, int x, int y, bool &beerus, int **dp)
    {
        // Base Case--
        if (n == 1 || n == x || n == y)
        {
            return (beerus) ? "Beerus" : "Whis";
        }
        if (n < 0)
        {
            return "";
        }

        // If Solution Exist--
        if (dp[beerus][n] != -1)
        {
            return (dp[beerus][n] == 1) ? "Beerus" : "Whis";
        }

        // Reccursive Calls--
        bool chance = beerus ^ true;
        string oneOut = winner(n - 1, x, y, chance, dp);
        string xOut = winner(n - x, x, y, chance, dp);
        string yOut = winner(n - y, x, y, chance, dp);

        string win = "";
        if (beerus)
        {
            if (oneOut == "Beerus" || xOut == "Beerus" || yOut == "Beerus")
            {
                win = "Beerus";
            }
            else
            {
                win = "Whis";
            }
        }
        else
        {
            if (oneOut == "Whis" || xOut == "Whis" || yOut == "Whis")
            {
                win = "Whis";
            }
            else
            {
                win = "Beerus";
            }
        }

        dp[beerus][n] = (win == "Beerus") ? 1 : 0;
        return win;
    }

public:
    string findWinner(int n, int x, int y)
    {
        bool beerus = true;

        int **dp = new int *[2];
        for (int i = 0; i < 2; i++)
        {
            dp[i] = new int[n + 1];
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = -1;
            }
        }
        return winner(n, x, y, beerus, dp);
    }
};

// Reccursion--
class Method1
{
    string winner(int n, int x, int y, bool &beerus)
    {
        // Base Case--
        if (n == 1 || n == x || n == y)
        {
            return (beerus) ? "Beerus" : "Whis";
        }
        if (n < 0)
        {
            return "";
        }

        // Reccursive Calls--
        bool chance = beerus ^ true;
        string oneOut = winner(n - 1, x, y, chance);
        string xOut = winner(n - x, x, y, chance);
        string yOut = winner(n - y, x, y, chance);

        if (beerus)
        {
            if (oneOut == "Beerus" || xOut == "Beerus" || yOut == "Beerus")
            {
                return "Beerus";
            }
            return "Whis";
        }
        else
        {
            if (oneOut == "Whis" || xOut == "Whis" || yOut == "Whis")
            {
                return "Whis";
            }
            return "Beerus";
        }
    }

public:
    string findWinner(int n, int x, int y)
    {
        bool beerus = true;
        return winner(n, x, y, beerus);
    }
};