/*
    Problem Link: https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

    Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. 
    Also, a knapsack with weight limit W.
    The task is to fill the knapsack in such a way that we can get the maximum profit. 
    Return the maximum profit.
    Note: Each item can be taken any number of times.
*/

// Memoization
class Solution {
    
    int solve(int i,int W,int val[],int wt[],vector<vector<int>>&dp)
    {
        if(!i) {
            return val[0]*(W/wt[0]);
        }
        if(dp[i][W]!=-1) 
            return dp[i][W];
        int take = -1e9;
        int nt = solve(i-1,W,val,wt,dp);
        if(W-wt[i]>=0)
        {
            take=solve(i,W-wt[i],val,wt,dp)+val[i];
        }
        return dp[i][W]=max(take,nt);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        return solve(N-1,W,val,wt,dp);
    }
};

// Tabulation
class Solution {
    
    int solve(int N,int W,int val[],int wt[],vector<vector<int>>&dp)
    {
        for(int i=0;i<=W;i++){
            dp[0][i]=val[0]*(i/wt[0]);
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<=W;j++)
            {
                int take = -1e9;
                int nt = dp[i-1][j];
                if(j-wt[i]>=0)
                {
                    take=dp[i][j-wt[i]]+val[i];
                }
                dp[i][j]=max(take,nt);
            }
        }
        return dp[N][W];
        
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        return solve(N-1,W,val,wt,dp);
    }
};

// Space Optimization using two rows
class Solution {
    
    int solve(int N,int W,int val[],int wt[])
    {
        vector<int>prev(W+1),cur(W+1);
        for(int i=0;i<=W;i++){
            prev[i]=val[0]*(i/wt[0]);
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<=W;j++)
            {
                int take = -1e9;
                int nt = prev[j];
                if(j-wt[i]>=0)
                {
                    take=cur[j-wt[i]]+val[i];
                }
                cur[j]=max(take,nt);
            }
            prev=cur;
        }
        return prev[W];
        
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        return solve(N-1,W,val,wt);
    }
};

//  Space Optimization using one row
class Solution{
    
    int solve(int N,int W,int val[],int wt[])
    {
        vector<int>prev(W+1);
        for(int i=0;i<=W;i++){
            prev[i]=val[0]*(i/wt[0]);
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<=W;j++)
            {
                int take = -1e9;
                int nt = prev[j];
                if(j-wt[i]>=0)
                {
                    take=prev[j-wt[i]]+val[i];
                }
                prev[j]=max(take,nt);
            }
        }
        return prev[W];
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        return solve(N-1,W,val,wt);
    }
};
