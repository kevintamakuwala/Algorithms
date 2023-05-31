/*
  Problem Link:  https://leetcode.com/problems/coin-change-ii/
  
  You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
  Return the number of combinations that make up that amount. 
  If that amount of money cannot be made up by any combination of the coins, return 0.
  You may assume that you have an infinite number of each kind of coin.
  The answer is guaranteed to fit into a signed 32-bit integer.
*/

// Memoization
class Solution {
    int solve(int i,int k,vector<vector<int>>&dp,vector<int>& coins)
    {
        if(i==0) {
            if(k%coins[0]) return 0;
            return 1;
        }
        if(dp[i][k]!=-1)
            return dp[i][k];
        int take = 0,notTake=solve(i-1,k,dp,coins);

        if(k-coins[i]>=0)
        {
            take = solve(i,k-coins[i],dp,coins);
        }
        return dp[i][k]=take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,dp,coins);        
    }
};

// Tabulation
class Solution {
    int solve(int k,vector<vector<int>>&dp,vector<int>& coins)
    {
        for(int i=0;i<=k;i++) {
            dp[0][i]=(i%coins[0])?0:1;
        }
        for(int i=1;i<coins.size();i++) {
            for(int j=0;j<=k;j++) {
                int take = 0,notTake=dp[i-1][j];
                if(j-coins[i]>=0)
                {
                    take = dp[i][j-coins[i]];
                }
                dp[i][j]=take+notTake;
            }
        }
        return dp[coins.size()-1][k];        
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        return solve(amount,dp,coins);        
    }
};

// Space optimization
class Solution {
    int solve(int k,vector<int>& coins)
    {
        vector<int>prev(k+1,0),cur(k+1,0);
        for(int i=0;i<=k;i++) {
            prev[i]=(i%coins[0])?0:1;
        }
        for(int i=1;i<coins.size();i++) {
            for(int j=0;j<=k;j++) {
                int take = 0,notTake=prev[j];
                if(j-coins[i]>=0)
                {
                    take = cur[j-coins[i]];
                }
                cur[j]=take+notTake;
            }
            prev=cur;
        }
        return prev[k];        
    }
public:
    int change(int amount, vector<int>& coins) {
        return solve(amount,coins);        
    }
};
