/*

    Problem Link: https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1/1
    
    Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
    The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number 
    and column number of the current cell, and i2, j2 are the row number and column number 
    of the nearest cell having value 1. There should be atleast one 1 in the grid.
    
*/

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n=grid.size(),m=grid[0].size();
	    int vis[n][m];
	    vector<vector<int>>dist(n,vector<int>(m,0));
        
        // {{rowIndex,colIndex},distance}
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vis[i][j]=0;
                if(grid[i][j]==1)
                {
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
                
            }
        }
        
        int rowDir[]={0,0,-1,1};
        int colDir[]={1,-1,0,0};
        
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            q.pop();
            dist[r][c]=d;
            for(int i=0;i<4;i++)
            {
                int nr=r+rowDir[i],nc=c+colDir[i];
                if(nr>=0 and  nr<n and nc>=0  and nc<m 
                and vis[nr][nc]==0 )
                {
                    vis[nr][nc]=1;
                    q.push({{nr,nc},d+1});
                }
            }
        }
        return dist;
	}
};