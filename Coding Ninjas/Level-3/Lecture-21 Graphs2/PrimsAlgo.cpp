#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(int *weight, bool *visited, int v)
{
    int minVertex = -1;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void prims(int **edges, int v)
{
    int *parent = new int[v];
    int *weight = new int[v];
    bool *visited = new bool[v];

    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    parent[0] = -1;
    weight[0] = 0;

    for (int i = 0; i < v-1; i++)
    {
        // Find Min Vertex
        int minVertex = findMinVertex(weight, visited, v);
        visited[minVertex] = true;

        // Explore unvisited neighbour
        for (int j = 0; j < v; j++)
        {
            if (edges[minVertex][j] != 0 && !visited[j])
            {
                if (edges[minVertex][j] < weight[j])
                {
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    for (int i = 1; i < v; i++)
    {
        if (parent[i] < i)
        {
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        }
        else
        {
            cout << i << " " << parent[i] << " " << weight[i] << endl;
        }
    }
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
        int f, s, w;
        cin >> f >> s >> w;

        edges[f][s] = w;
        edges[s][f] = w;
    }

    prims(edges, v);

    return 0;
}