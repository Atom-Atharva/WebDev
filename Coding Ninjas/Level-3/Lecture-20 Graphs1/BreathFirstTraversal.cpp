#include <iostream>
using namespace std;
#include <queue>

void print(int **edges, int v, bool *visited, int sv)
{
    queue<int> vertex;
    vertex.push(sv);
    visited[sv] = true;

    while (!vertex.empty())
    {
        int element = vertex.front();
        vertex.pop();
        cout << element << " ";

        for (int i = 0; i < v; i++)
        {
            if (i == element)
            {
                continue;
            }
            if (edges[i][element] == 1)
            {
                if (visited[i])
                {
                    continue;
                }
                vertex.push(i);
                visited[i] = 1;
            }
        }
    }
}

// For all different components in the graph--
void print(int **edges, int v, bool *visited)
{
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            print(edges, v, visited, i);
        }
    }
    return;
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

    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    // Print in BFS Traversal--
    print(edges, v, visited);

    // Delete Heap Memory--
    delete[] visited;
    for (int i = 0; i < v; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}