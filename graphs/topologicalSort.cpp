/*

    Problem Link: https://practice.geeksforgeeks.org/problems/topological-sort/1
    
    Given a Directed Acyclic Graph (DAG) with V vertices and E edges,
    Find any Topological Sorting of that Graph.

*/
class Solution
{
    vector<int>khanAlgo(int V,vector<int> adj[])
    {
        vector<int>indegree(V,0),topo;
        
        for(int i=0;i<V;i++)
        {
            for(int it:adj[i])
            {
                indegree[it]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<V;++i)
        {
            if(!indegree[i])
                q.push(i);
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
            
        }
        return topo;
    }
    // void dfs(int i,vector<int>adj[],vector<int>&vis,stack<int>&st)
    // {
    //     vis[i]=1;
    //     for(int it:adj[i])
    //     {
    //         if(!vis[it])
    //         {
    //             dfs(it,adj,vis,st);
    //         }
    //     }
    //     st.push(i);
    // }
	public:   
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   // vector<int>vis(V,0),res;
	    
	   // stack<int>st;
	    
	   // for(int i=0;i<V;i++)
	   // {
	   //     if(!vis[i])
	   //     {
	   //         dfs(i,adj,vis,st);
	   //     }
	   // }
	   // while(!st.empty())
	   // {
	   //     res.push_back(st.top());
	   //    // cout<<st.top()<<' ';
	   //     st.pop();
	   // }
	    
	    
    //     return res;
    
    return khanAlgo(V,adj);
	   
	}
};