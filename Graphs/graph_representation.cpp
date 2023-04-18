#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
vector<int> dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs)
{
    storeDfs.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, storeDfs);
        }
    }
    return storeDfs;
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{

    vector<int> storeDfs, vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, storeDfs);
        }
    }
    return storeDfs;
}
void bfs(vector<int> adj[], int n)
{
    queue<int> q;
    q.push(0);
    vector<int> vis(n + 1, 0);
    vis[0] = 1;
    while (!q.empty())
    {
        auto i = q.front();
        q.pop();
        cout << i << " ";

        for (auto it : adj[i])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
}
int main()
{
    ll n, m;
    cin >> n >> m;
    // ll adj[n+1][m+1]={{0}};
    // for(ll i=0;i<m;i++)
    // {
    //     ll u,v,wt;
    //     cin>>u>>v>>wt;
    //     adj[u][v]=wt;
    //     adj[v][u]=wt;
    // }
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}