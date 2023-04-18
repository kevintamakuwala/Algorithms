/*

    Problem Link: https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
    
    Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) 
    consisting of '0's (Water) and '1's(Land). 
    Find the number of islands.

    Note: An island is either surrounded by water or boundary of grid and is formed by 
    connecting adjacent lands horizontally or vertically or diagonally 
    i.e., in all 8 directions.
    
*/

class Solution {
    
    private:
    void bfs(int n,int m,vector<vector<int>>&vis,vector<vector<char>>grid)
    {
        queue<pair<int,int>> q;
        
        q.push({n,m});
        vis[n][m] = 1;
        
        
        int row=grid.size();
        int col=grid[0].size();
        
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            
            q.pop();
    
            for(int delrow=-1;delrow<=1;delrow++)
            {
                for(int delcol=-1;delcol<=1;delcol++)
                {
                    int nrow=delrow+r;
                    int ncol=delcol+c;
                    if(nrow>=0 and nrow<row and ncol>=0 and ncol<col and grid[nrow][ncol]=='1' and !vis[nrow][ncol])
                    {
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                    }
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size(),ans=0;
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] and grid[i][j]=='1')
                {
                    bfs(i,j,vis,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};