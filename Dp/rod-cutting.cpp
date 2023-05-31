/*
    Problem Link: https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
    
    Given a rod of length N inches and an array of prices, price[]. 
    price[i] denotes the value of a piece of length i. 
    Determine the maximum value obtainable by cutting up the rod and selling the pieces.
    Note: Consider 1-based indexing.
*/

// Memoization
class Solution{
    int solve(int price[],int i,int k,vector<vector<int>>&dp)
    {
        if(!i){
            return k*price[0];
        }    
        if(dp[i][k]!=-1) return dp[i][k];
        int t=-1e9,nt=solve(price,i-1,k,dp);
        if(i+1<=k){
            t=solve(price,i,k-i-1,dp)+price[i];
        }
        return dp[i][k]=max(t,nt);
    }
  public:
    int cutRod(int price[], int n) 
    {
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(price,n-1,n,dp);
    }
};
// Tabulation
class Solution{
    int solve(int price[],int n,int k,vector<vector<int>>&dp)
    {
        for(int i=0;i<=k;i++){
            dp[0][i]=i*price[0];
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                int t=-1e9,nt=dp[i-1][j];
                if(i+1<=j)
                {
                    t=dp[i][j-i-1]+price[i];
                }
                dp[i][j]=max(t,nt);
            }
        }
        return dp[n][k];
        
    }
  public:
    int cutRod(int price[], int n) 
    {
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        return solve(price,n-1,n,dp);
    }
};

// Space Optimization in two rows
class Solution{
    int solve(int price[],int n,int k)
    {
        vector<int>prev(k+1),cur(k+1);
        for(int i=0;i<=k;i++){
            prev[i]=i*price[0];
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                int t=-1e9,nt=prev[j];
                if(i+1<=j)
                {
                    t=cur[j-i-1]+price[i];
                }
                cur[j]=max(t,nt);
            }
            prev=cur;
        }
        return prev[k];
        
    }
  public:
    int cutRod(int price[], int n) 
    {
        return solve(price,n-1,n);
    }
};

// Space Optimization in one row
class Solution{
    int solve(int price[],int n,int k)
    {
        vector<int>prev(k+1);
        for(int i=0;i<=k;i++){
            prev[i]=i*price[0];
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                int t=-1e9,nt=prev[j];
                if(i+1<=j)
                {
                    t=prev[j-i-1]+price[i];
                }
                prev[j]=max(t,nt);
            }
        }
        return prev[k];
        
    }
  public:
    int cutRod(int price[], int n) 
    {
        return solve(price,n-1,n);
    }
};
