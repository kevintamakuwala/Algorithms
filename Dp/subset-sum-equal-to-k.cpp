/*
    Problem Link: https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954
*/

#include <bits/stdc++.h> 
using namespace std;
// Memoization
bool Memoization(int i,int k,vector<int>&arr,vector<vector<bool>>&dp)
{
    if(k==0)
        return 1;
    if(i==0)
        return arr[0]==k;
    if(dp[i][k]!=-1) return dp[i][k];
    bool notTake = Memoization(i-1,k,arr,dp);
    bool take = 0;
    if(arr[i]<=k)
        take=Memoization(i-1,k-arr[i],arr,dp);
    return dp[i][k]=take | notTake;
}
// Tabulation
bool Tabulation(int n,int k,vector<int>&arr,vector<vector<bool>>&dp)
{
      for(int i=0;i<=n;i++)
      dp[i][0]=1;
  
      dp[0][arr[0]]=1;
  
      for(int i = 1;i<=n;i++)
      {
          for(int j=1;j<=k;j++)
          {
              bool notTake = dp[i-1][j];
              bool take = 0;
              if(arr[i]<=j)
              take=dp[i-1][j-arr[i]];
              dp[i][j]=take | notTake;
          }
      }
      return dp[n][k];
}
// SpaceOptimization
bool SpaceOptimization(int n, int k, vector<int> &arr)
{
    vector<bool>prev(k+1,0);
    prev[0]=1;
    for (int i = 0; i <= n; i++) 
    {
          vector<bool>temp(k+1,0);
          temp[0]=1;
          for (int j = 0; j <= k; j++) 
          {
              bool notTake = prev[j];
              bool take = 0;
              if (arr[i] <= j)
                take = prev[j - arr[i]];
              temp[j] = take | notTake;
          }
          prev=temp;
    }
    return prev[k];
}
bool subsetSumToK(int n, int k, vector<int> &arr) 
{
    vector<vector<bool>>dp(n+1,vector<bool>(k+1,0));
    return Memoization(n-1,k,arr,dp);
}
