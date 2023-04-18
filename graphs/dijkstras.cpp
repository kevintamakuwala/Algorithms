#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

vector<int> dijkstras(vector<vector<int>> adj[], int V, int S)
{
    vector<int> dist(V, INT_MAX);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it[0], adjWt = it[1];
            if (wt + adjWt < dist[adjNode])
            {
                dist[adjNode] = wt + adjWt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}
int main()
{

    int n, m;
    
    cin >> n >> m;

    vector<vector<int>> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    
    vector<int> ans(n);
    
    ans = dijkstras(adj, n, 0);
    
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return 0;
}