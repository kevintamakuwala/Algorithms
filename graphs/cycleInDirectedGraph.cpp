/*
    Problem Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

    Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, 
    check whether it contains any cycle or not.
*/
class Solution
{  
    bool dfs(int i,vector<int>adj[],vector<int>&vis)
    {
        // pathVis[i]=1;
        vis[i]=2;
        
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,vis)) return 1;
            }
            else if(vis[it]==2) //pathVis[it]==1
            {
                return 1;
            }
        }
        vis[i]=1;   //pathVis[i]=0;
        return 0;
    }
    
    public:
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int>vis(V,0);//,pathVis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                if(dfs(i,adj,vis)) return 1;
        }
        return 0;
    }
};