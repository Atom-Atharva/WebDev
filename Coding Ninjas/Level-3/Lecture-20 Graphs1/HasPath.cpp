#include <iostream>
using namespace std;

// DFS Traversal--
bool hasPath(int **edges, int v, int st, int en, bool *visited)
{
    // Base Case--
    if (st == en)
    {
        return true;
    }

    // Reccursive Call and Small Calculation--
    visited[st] = 1;
    bool path = false;
    for (int i = 0; i < v; i++)
    {
        if (i == st)
        {
            continue;
        }
        if (edges[i][st] == 1 && visited[i] == false)
        {
            path = hasPath(edges, v, i, en, visited);
            if (path)
            {
                return true;
            }
        }
    }
    return path;
}

int main()
{
    // Edges and Vertices
    int v, e;
    cin >> v >> e;

    int **edges = new int *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            edges[i][j] = 0;
        }
    }

    // Adjencentcy Matrix
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    // Starting and Ending point
    int a, b;
    cin >> a >> b;

    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    // Has path
    if (hasPath(edges, v, a, b, visited))
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}