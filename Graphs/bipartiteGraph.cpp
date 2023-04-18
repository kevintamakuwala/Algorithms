/*

    Problem Link: https://practice.geeksforgeeks.org/problems/bipartite-graph/1
    
    Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. 
    Check whether the graph is bipartite or not.
    
*/

class Solution {
    
    bool cycledfs(int s,vector<int>adj[],vector<int>&color,int colr)
    {
        
        color[s]=colr;
        for(auto it:adj[s])
        {
            if(color[it]==-1 )
            {
                if(!cycledfs(it,adj,color,!colr))
                return 0;
            }
            else if(color[it]==color[s])
            {
                return 0;
            }
        }
        return 1;
        
    }
    bool cyclebfs(int s,vector<int>adj[],vector<int>&color)
    {
        // vector<int>vis(V,0);
        queue<pair<int,int>>q;

        color[s]=0;
        q.push({s,0});
        
        while(!q.empty())
        {
            auto qit=q.front();
            
            int node=qit.first;
            int colr=qit.second;
            
            q.pop();
            
            for(auto it:adj[node])
            {
                if(color[it]==-1)
                {
                    color[it]=!colr;
                    q.push({it,color[it]});
                }
                else if(color[it]==colr)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
public:

	bool isBipartite(int V, vector<int>adj[]){
	    bool ans=1;
	    vector<int>color(V,-1);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            ans=cycledfs(i,adj,color,0);
	           // ans = cyclebfs(i,adj,color);
	            if(!ans)
	            return 0;
	        }
	    }
	    return 1;
	     
	}

};