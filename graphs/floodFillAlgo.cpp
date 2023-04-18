/*

    Problem Link: https://practice.geeksforgeeks.org/problems/flood-fill-algorithm/1
    
    An image is represented by a 2-D array of integers, each integer representing the pixel 
    value of the image.
    Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood 
    fill, and a pixel value newColor, "flood fill" the image.

    To perform a "flood fill", consider the starting pixel, plus any pixels connected 
    4-directionally to the starting pixel of the same color as the starting pixel, 
    plus any pixels connected 4-directionally to those pixels (also with the same color as
    the starting pixel), and so on. 
    Replace the color of all of the aforementioned pixels with the newColor. 
    
*/

class Solution {
    int rowDir[4]={-1,0,1,0};
    int colDir[4]={0,-1,0,1};
    
    void dfs(int sr,int sc,vector<vector<int>>&adj,int initialColor,int ncolor)
    {
            int row=adj.size(),col=adj[0].size();
            adj[sr][sc]=ncolor;
            for(int i=0;i<4;i++)
            {
                int nr=sr+rowDir[i],nc=sc+colDir[i];
                if(nr>=0 and nr<row and nc>=0 and nc<col and adj[nr][nc]==initialColor and adj[nr][nc]!=ncolor)
                {
                    dfs(nr,nc,adj,initialColor,ncolor);
                }
            }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int ncolor) {
        
        if(ncolor==image[sr][sc]) return image;
        int r=image.size(),c=image[0].size();
        
        vector<vector<int>> adj;
        
        for(int i=0;i<r;i++)
        {
            vector<int>t;
            for(int j=0;j<c;j++)
            {
                t.push_back(image[i][j]);
            }
            adj.push_back(t);
        }
        
        dfs(sr,sc,adj,adj[sr][sc],ncolor);
        return adj;
    }
};
