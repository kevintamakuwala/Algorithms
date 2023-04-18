/*

    Problem Link: https://practice.geeksforgeeks.org/problems/number-of-enclaves/1

    You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 
    represents a land cell.
    A move consists of walking from one land cell to another adjacent (4-directionally) 
    land cell or walking off the boundary of the grid.

    Find the number of land cells in grid for which we cannot walk off the boundary of the grid 
    in any number of moves.
*/

class Solution
{
    int cnt=0;
    void dfs(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&vis)
    {
        int rd[]={-1,0,1,0},cd[]={0,1,0,-1};
        int n=grid.size(),m=grid[0].size();
        vis[r][c]=1;
        cnt++;
        
        for(int i=0;i<4;i++)
        {
            int nr=r+rd[i];
            int nc=c+cd[i];
            if(nr>=0 and nr<n-1 and nc>=0 and nc<=m-1 and grid[nr][nc]==1 and  !vis[nr][nc])
            {
                dfs(nr,nc,grid,vis);
            }
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1 and !vis[i][0])
            {
                dfs(i,0,grid,vis);
            }
        }
        
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1 and !vis[0][i])
            {
                dfs(0,i,grid,vis);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(grid[i][m-1]==1 and !vis[i][m-1])
            {
                dfs(i,m-1,grid,vis);
            }
        }
        
        for(int i=0;i<m;i++)
        {
            if(grid[n-1][i]==1 and !vis[n-1][i])
            {
                dfs(n-1,i,grid,vis);
            }
        }
        int c=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            c++;
        }
        return c-cnt;
        
    }
};