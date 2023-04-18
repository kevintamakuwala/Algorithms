/*

    Problem Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
    
    Given an undirected graph with V vertices and E edges, 
    check whether it contains any cycle or not. 
    Graph is in the form of adjacency list where adj[i] contains all the nodes ith node 
    is having edge with.

*/
class Solution {
    
    private:
    bool dfs(int s,int parent,vector<int>adj[],vector<int>&vis)
    {
        vis[s]=1;
        
        for(auto it:adj[s])
        {
            if(!vis[it])
            {
               if(dfs(it,s,adj,vis)) return 1;
            }
            else if(it!=parent)
            {
                return 1;
            }
        }
        return 0;
    }
    bool bfs(int V,vector<int>adj[],int s,vector<int>&vis)
    {
        queue<pair<int,int>>q;
        q.push({s,-1});
        vis[s]=1;
        while(!q.empty())
        {
            int parent=q.front().second;
            int node=q.front().first;
            q.pop();
            for(auto it:adj[node])
            {
                if(vis[it]  and it!=parent)
                return 1;
                if(!vis[it])
                {
                    q.push({it,node});
                    vis[it]=1;
                }
            }
        }
        return 0;
    }
    
    public:
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<int>vis(V+1,0);

        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
               if(dfs(i,-1,adj,vis))  // if(bfs(V,adj,i,vis))  
               return 1;
            }
        }
        return 0;
    }
};