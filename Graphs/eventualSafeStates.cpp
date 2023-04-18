/*

    Problem Link: https://practice.geeksforgeeks.org/problems/eventual-safe-states/1
    
    A directed graph of V vertices and E edges is given in the form of an adjacency list adj.
    Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.
    A node is a terminal node if there are no outgoing edges.
    A node is a safe node if every possible path starting from that node leads to a terminal node.
    You have to return an array containing all the safe nodes of the graph. 
    The answer should be sorted in ascending order.
    
*/

class Solution 
{
    bool cycleDfs(int i,vector<int>adj[],vector<int>&vis,vector<int>&pathVis)
    {
        vis[i]=1;
        pathVis[i]=1;
        
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                if(cycleDfs(it,adj,vis,pathVis))
                return 1;
            }
            else if(pathVis[it]) {
                return 1;
            }
        }
        
        pathVis[i]=0;
        return 0;
    }
    public:  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
       
        vector<int>ans,vis(V,0),pathVis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                cycleDfs(i,adj,vis,pathVis);
        }
        for(int i=0;i<V;i++){
            if(!pathVis[i])
            ans.push_back(i);
        }return ans;
    }
};