#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <unordered_map>

vector<int> *getPathBFS(bool **edges, int v, bool *visited, int st, int en)
{
    unordered_map<int, int> map;
    queue<int> vertex;
    vertex.push(st);
    map[st] = -1; // Denots starting point;

    while (!vertex.empty())
    {
        int node = vertex.front();
        vertex.pop();
        visited[node] = 1;

        for (int i = 0; i < v; i++)
        {
            if (i == node)
            {
                continue;
            }
            if (edges[i][node] == 1 && visited[i] != 1)
            {
                vertex.push(i);
                visited[i] = 1;
                map[i] = node;
                if (i == en)
                {
                    break;
                }
            }
        }
        if (map.count(en) != 0)
        {
            vector<int> *path = new vector<int>();
            int n = en;
            path->push_back(n);
            
            while (map[n] != -1)
            {
                path->push_back(map[n]);
                n = map[n];
            }
            return path;
        }
    }
    return NULL;
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
    int a, b;
    cin >> a >> b;

    // Initialising with Declaring
    bool *visited = new bool[v]();

    vector<int> *path = getPathBFS(edges, v, visited, a, b);

    for (int i = 0; path != NULL && i < path->size(); i++)
    {
        cout << path->at(i) << " ";
    }

    return 0;
}