#include <iostream>
using namespace std;
#include <vector>

vector<int> *getPathDFS(int **edges, int v, bool *visited, int st, int en)
{
    visited[st] = 1;
    if (st == en)
    {
        vector<int> *ans = new vector<int>();
        ans->push_back(st);
        return ans;
    }

    for (int i = 0; i < v; i++)
    {
        if (i == st)
        {
            continue;
        }
        if (visited[i] == 0 && edges[st][i] == 1)
        {
            vector<int> *smallans = getPathDFS(edges, v, visited, i, en);
            if (smallans != NULL)
            {
                smallans->push_back(st);
                return smallans;
            }
        }
    }
    return NULL;
}

int main()
{
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

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    int a, b;
    cin >> a >> b;

    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    vector<int> *path = getPathDFS(edges, v, visited, a, b);

    for (int i = 0; path != NULL && i < path->size(); i++)
    {
        cout << path->at(i) << " ";
    }

    return 0;
}