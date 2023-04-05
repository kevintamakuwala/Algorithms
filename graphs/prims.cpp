#include <vector>
#include <utility>
#include <queue>
#include <iostream>

using namespace std;
#define ll long long
#define M 1000000007

vector<pair<int, int>> path;

int prims(vector<pair<int, int>> adj[], int n)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<int> vis(n + 1);
    pq.push({0, {0, -1}});
    int sum = 0;
    while (!pq.empty())
    {
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        int wt = pq.top().first;
        pq.pop();

        if (vis[node])
            continue;

        vis[node] = 1;

        if (parent != -1)
            path.push_back({node, parent});
        sum += wt;

        for (auto it : adj[node])
        {
            if (!vis[it.first])
            {
                pq.push({it.second, {it.first, node}});
            }
        }
    }
    for (auto it : path)
    {
        cout << it.first << " -> " << it.second << '\n';
    }
    return sum;
}
int main()
{
    int n, m, wt;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    cout << endl
         << endl
         << prims(adj, n);
    return 0;
}