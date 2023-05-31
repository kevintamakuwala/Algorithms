/*
    Problem Link: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

    You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
    Note that we have only one quantity of each item.
    In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. 
    Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is 
    smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).
*/

// Memoization 
class Solution
{
    
    int solve(int i,int W,int wt[],int val[],int n,vector<vector<int>>&dp)
    {
        if(i==0) {
            return (wt[0]<=W)?val[0]:0;
        }
        if(dp[i][W]!=-1) return dp[i][W];
        int t=-1e9,nt=solve(i-1,W,wt,val,n,dp);
        if(W-wt[i]>=0)
        {
            t=solve(i-1,W-wt[i],wt,val,n,dp)+val[i];
        }
        return dp[i][W]=max(t,nt);
    }
    
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return solve(n-1,W,wt,val,n,dp);
    }
};

// Tabulation
class Solution
{
    
    int solve(int i,int W,int wt[],int val[],int n,vector<vector<int>>&dp)
    {
        for(int i=0;i<=W;i++) {
            dp[0][i] = (wt[0]<=i)?val[0]:0;
        }
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<=W;j++){
                int t=-1e9,nt=dp[i-1][j];
                if(j-wt[i]>=0)
                {
                    t=dp[i-1][j-wt[i]]+val[i];
                }
                dp[i][j]=max(t,nt);
            }
        }
       
        return dp[n-1][W];
    }
    
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n+1,vector<int>(W+1,0));
        return solve(n-1,W,wt,val,n,dp);
    }
};
// Space Optimization Two ROWS
class Solution
{
    
    int solve(int i,int W,int wt[],int val[],int n)
    {
        vector<int>prev(W+1,0),cur(W+1,0);
        for(int i=0;i<=W;i++) {
            prev[i] = (wt[0]<=i) ? val[0]:0;
        }
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<=W;j++){
                int t=-1e9,nt=prev[j];
                if(j-wt[i]>=0)
                {
                    t=prev[j-wt[i]]+val[i];
                }
                cur[j]=max(t,nt);
            }
            prev=cur;
        }
       
        return prev[W];
    }
    
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        return solve(n-1,W,wt,val,n);
    }
};

// Space optimization in One ROW
class Solution
{
    
    int solve(int i,int W,int wt[],int val[],int n)
    {
        vector<int>prev(W+1,0);
        for(int i=0;i<=W;i++) {
            prev[i] = (wt[0]<=i) ? val[0]:0;
        }
        
        for(int i=1;i<n;i++) {
            for(int j=W;j>=0;j--){
                int t=-1e9,nt=prev[j];
                if(j-wt[i]>=0)
                {
                    t=prev[j-wt[i]]+val[i];
                }
                prev[j]=max(t,nt);
            }
            
        }
       
        return prev[W];
    }
    
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        return solve(n-1,W,wt,val,n);
    }
};
