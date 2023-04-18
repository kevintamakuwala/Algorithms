/*

    Problem Link: https://practice.geeksforgeeks.org/problems/number-of-provinces/1

    Given an undirected graph with V vertices. We say two vertices u and v belong to a single 
    province if there is a path from u to v or v to u. 
    Your task is to find the number of provinces.

    Note: A province is a group of directly or indirectly connected cities and no other cities 
    outside of the group.

*/

class Solution {
    private:
    void bfs(vector<int>adj[],int V,int s,vector<int>&vis)
    {
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        while (!q.empty())
        {
            auto i = q.front();
            q.pop();
    
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
    public:
    int numProvinces(vector<vector<int>> ad, int V) {
        // code here
        vector<int>adj[V];
        for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
        {
            if(ad[i][j]==1 and i!=j)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        vector<int>vis(V,0);
        int ans=0;
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                
                bfs(adj,V,i,vis);
                ans++;   
            }
        }
        return ans;
        
    }
};