/*

    Problem Link: https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

    Given a boolean 2D matrix grid of size n * m. 
    You have to find the number of distinct islands where a group of connected 1s
    (horizontally or vertically) forms an island. 
    Two islands are considered to be distinct if and only if one island 
    is not equal to another (not rotated or reflected).

*/

class Solution
{
    void dfs(int r,int c,vector<vector<int>>&grid,vector<pair<int,int>>&vec,
    vector<vector<int>>&vis,int r0,int c0)
    {
        int n=grid.size(),m=grid[0].size();
        vis[r][c]=1;
        
        vec.push_back({r-r0,c-c0});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nr=dr[i]+r,nc=dc[i]+c;
            if(nr>=0 and nr<n and nc>=0 and nc<m
            and !vis[nr][nc] and grid[nr][nc]==1)
            {
                dfs(nr,nc,grid,vec,vis,r0,c0);    
            }
        }
    }
    public:
    int countDistinctIslands(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0)); 
        set<vector<pair<int,int>>>st;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] and grid[i][j]==1)
                {
                    vector<pair<int,int>>vec;
                    dfs(i,j,grid,vec,vis,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
