/*

    Problem Link: https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1
    
    Given a matrix mat of size N x M where every element is either O or X.
    Replace all O with X that are surrounded by X.
    A O (or a set of O) is considered to be surrounded by X if there are X at locations 
    just below, just above, just left and just right of it.
    
*/

class Solution
{
    
    public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 or j==0 or i==n-1 or j==m-1 )
                {
                    if(mat[i][j]=='O')
                    {
                    q.push({i,j});
                    vis[i][j]=1;
                    }
                }
            }
        }
        int dr[]={1,0,0,-1};
        int dc[]={0,1,-1,0};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 and nc>=0 and nr<n and nc<m and vis[nr][nc]==0 and mat[nr][nc]=='O')
                {
                  q.push({nr,nc});
                  vis[nr][nc]=1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 and mat[i][j]=='O')
                {
                    mat[i][j]='X';
                }
            }
        }
        return mat;
   
    }
};