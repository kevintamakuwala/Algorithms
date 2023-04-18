#include <vector>
#include <utility>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define M 1000000007
vector<pair<int, int>> path;


class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int V)
    {
        rank.resize(V + 1, 0);
        parent.resize(V + 1);

        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

int kruskal(vector<pair<int, int>> adj[], int V)
{
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            edges.push_back({it.second, {i, it.first}});
        }
    }
    sort(edges.begin(), edges.end());

    DisjointSet ds(V);

    int sum = 0;
    for (auto it : edges)
    {
        int wt = it.first;
        int u = it.second.first, v = it.second.second;

        if (ds.findParent(u) != ds.findParent(v))
        {
            ds.unionByRank(u, v);
            path.push_back({u, v});
            sum += wt;
        }
    }
    for (auto it : path)
    {
        cout << it.first << " - " << it.second << '\n';
    }
    return sum;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    cout << kruskal(adj, n);
    return 0;
}