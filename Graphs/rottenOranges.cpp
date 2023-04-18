/*

    Problem Link: https://practice.geeksforgeeks.org/problems/rotten-oranges/1
    
    Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 
    which has the following meaning:
    0 : Empty cell
    1 : Cells have fresh oranges
    2 : Cells have rotten oranges

    We have to determine what is the minimum time required to rot all oranges. 

    A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] 
    (up, down, left and right) in unit time. 
    
*/

class Solution 
{
    public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int vis[n][m];
     
        queue<pair<pair<int ,int >,int>> q;
        int cntfresh=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (grid[i][j]==2)
                {
                     q.push({{i,j},0});
                     vis[i][j]=2;
                }
                else {
                    vis[i][j]=0;
                }
                if (grid[i][j]==1) cntfresh++;
            }
        }
        int cnt=0,tm=0;
        while (!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            q.pop();
            
            tm=max(tm,t);
            
            for (int i=0;i<4;i++)
            {
                int nrow=row +delrow[i];
                int ncol=col+delcol[i];
                if (nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                && grid[nrow][ncol]==1 && vis[nrow][ncol]!=2)
                {
                        vis[nrow][ncol]=2;
                        q.push({{nrow,ncol},t+1});
                        cnt++;
                }
            }
        }
             
        return (cnt==cntfresh)?tm:-1;            
    }
};
