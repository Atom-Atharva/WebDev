#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>

// BFS Order--
vector<int> *connectedComponent(bool **edges, int v, bool *visited, int sv)
{
    vector<int> *ans = new vector<int>();
    queue<int> vertex;
    vertex.push(sv);
    visited[sv] = 1;

    while (!vertex.empty())
    {
        int node = vertex.front();
        vertex.pop();
        ans->push_back(node);

        for (int i = 0; i < v; i++)
        {
            if (i == node)
            {
                continue;
            }
            if (edges[i][node] == 1 && visited[i] == 0)
            {
                vertex.push(i);
                visited[i] = 1;
            }
        }
    }
    return ans;
}

vector<vector<int> *> *allConnected(bool **edges, int v)
{
    bool *visited = new bool[v]();
    vector<vector<int> *> *ans = new vector<vector<int> *>();

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == 0)
        {
            vector<int> *smallans = connectedComponent(edges, v, visited, i);
            sort(smallans->begin(), smallans->end());
            ans->push_back(smallans);
        }
    }
    return ans;
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

    vector<vector<int> *> *components = allConnected(edges, v);

    for (int i = 0; i < components->size(); i++)
    {
        for (int j = 0; j < components->at(i)->size(); j++)
        {
            cout << components->at(i)->at(j) << " ";
        }
        cout << endl;
    }

    return 0;
}