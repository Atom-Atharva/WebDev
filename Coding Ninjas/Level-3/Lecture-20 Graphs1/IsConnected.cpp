#include <iostream>
using namespace std;

void traverse(bool **edges, int v, bool *visited, int st)
{
    visited[st] = 1;
    for (int i = 0; i < v; i++)
    {
        if (i == st)
        {
            continue;
        }
        if (visited[i] == 0 && edges[i][st] == 1)
        {
            traverse(edges, v, visited, i);
        }
    }
    return;
}

bool isConnected(bool **edges, int v)
{
    bool *visited = new bool[v]();

    traverse(edges, v, visited, 0);

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int v, e;
    cin >> v >> e;

    bool **edges = new bool *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new bool[v]();
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    if (isConnected(edges, v))
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}