// https://www.codingninjas.com/studio/problems/permutationcoefficient_1214975

#define M 1000000007

// Method 4: Optimal Solution--
class Solution
{
    int factorial(int st, int en)
    {
        int fact = 1;
        for (int i = st; i <= en; i++)
        {
            fact = ((long long) fact * i) % M;
        }

        return fact;
    }

public:
    int P(int n, int k)
    {
        // Base Case--
        if (k > n)
        {
            return 0;
        }

        // Factorials End Points--
        int st = n - k + 1;
        int en = n;

        return factorial(st, en);
    }
};

// Method 3: Dynamic Programming--
class Solution
{
public:
    int P(int n, int k)
    {
        // Base Case--
        if (k > n)
        {
            return 0;
        }

        int **arr = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            arr[i] = new int[k + 1];
        }

        // Fill Initial Cell--
        arr[0][0] = 1;

        // Fill First Row--
        for (int i = 1; i <= k; i++)
        {
            arr[0][i] = 0;
        }

        // Fill First Column--
        for (int i = 1; i <= n; i++)
        {
            arr[i][0] = 1;
        }

        // Fill Remaining Cells--
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                arr[i][j] = (arr[i - 1][j] + ((long long)j * arr[i - 1][j - 1]) % M) % M;
            }
        }

        return arr[n][k];
    }
};

// Method 2: Memomization--
class Solution
{
    int P(int n, int k, int **arr)
    {
        // Base Case--
        if (k == 0)
        {
            return 1;
        }
        if (k > n)
        {
            return 0;
        }
        if (arr[n - 1][k - 1] != -1)
        {
            return arr[n - 1][k - 1];
        }

        // Recursive Calls--
        return arr[n - 1][k - 1] = (P(n - 1, k, arr) % M + ((long long)k * P(n - 1, k - 1, arr)) % M) % M;
    }

public:
    int P(int n, int k)
    {
        int **arr = new int *[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[k];
            for (int j = 0; j < k; j++)
            {
                arr[i][j] = -1;
            }
        }
        return P(n, k, arr);
    }
};

// Method 1: Recursive Approach--
class Solution
{
public:
    int P(int n, int k)
    {
        // Base Case--
        if (k == 0)
        {
            return 1;
        }
        if (k > n)
        {
            return 0;
        }

        // Recursive Calls--
        return (P(n - 1, k) + ((long long)k * P(n - 1, k - 1)) % M) % M;
    }
};