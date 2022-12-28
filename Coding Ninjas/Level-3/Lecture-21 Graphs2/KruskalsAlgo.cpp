#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

class Edge
{
public:
    int v1;
    int v2;
    int weight;
};

bool compare(Edge e1, Edge e2)
{
    // Increasing order--
    return (e1.weight < e2.weight);
}

int findParent(int v, int *parent)
{
    if (v == parent[v])
    {
        return v;
    }

    int ans = findParent(parent[v], parent);
    return ans;
}

void kruskals(Edge *edges, int v, int e)
{
    // Sort the input array in ascending order
    sort(edges, edges + e, compare);

    Edge *output = new Edge[v - 1];

    int *parent = new int[v];
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    while (count != v - 1)
    {
        Edge currentEdge = edges[i];

        // Check for the current edge in MST--
        int sourceparent = findParent(currentEdge.v1, parent);
        int destinationparent = findParent(currentEdge.v2, parent);

        if (sourceparent != destinationparent)
        {
            output[count] = currentEdge;
            count++;
            parent[sourceparent] = destinationparent;
        }
        i++;
    }

    for (int i = 0; i < v - 1; i++)
    {
        if (output[i].v1 < output[i].v2)
            cout << output[i].v1 << " " << output[i].v2 << " " << output[i].weight << endl;

        else
            cout << output[i].v2 << " " << output[i].v1 << " " << output[i].weight << endl;
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    Edge *edges = new Edge[e];
    for (int i = 0; i < e; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;

        edges[i].v1 = v1;
        edges[i].v2 = v2;
        edges[i].weight = w;
    }

    kruskals(edges, v, e);

    return 0;
}