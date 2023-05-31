/*
  Problem Link: https://leetcode.com/problems/target-sum/
  
  You are given an integer array nums and an integer target.
  You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums 
  and then concatenate all the integers.

  For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
  Return the number of different expressions that you can build, which evaluates to target.

*/
// Memoization
class Solution {

    int solve(vector<int>&nums,int i,int k,vector<vector<int>>&dp)
    {
        if(i==0) {
            if(k==0 and nums[0]==0) {
                return 2;
            }
            if(k==0 or nums[0]==k) {
                return 1;
            }
            return 0;
        }
        if(dp[i][k]!=-1) 
            return dp[i][k];
        int take = 0; 
        if(k-nums[i]>=0)
          take= solve(nums,i-1,k-nums[i],dp);
        int notTake = solve(nums,i-1,k,dp);
        return dp[i][k]=take+notTake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int k) {
        int s=0,n=nums.size();
        for(auto it:nums){
            s+=it;
        }
        if((s-k)<0 or (s-k)&1) return 0;
        vector<vector<int>>dp(n,vector<int>(2001,-1));
        return solve(nums,n-1,(s-k)/2,dp);
    }
};

// Tabulation
class Solution {

    int solve(vector<int>&nums,int n,int k,vector<vector<int>>&dp)
    {
        for(int i=0;i<=k;i++){
            if(i==0 and nums[0]==0){
                dp[0][0]=2;
            }else if(i==0 or nums[0]==i){
                dp[0][i]=1;
            }
            else{
                dp[0][i]=0;
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                int take = 0; 
                if(j-nums[i]>=0)
                    take=dp[i-1][j-nums[i]];
                int notTake = dp[i-1][j];
                dp[i][j]=take+notTake;
            }
        }return dp[n][k];
    }
public:
    int findTargetSumWays(vector<int>& nums, int k) {
        int s=0,n=nums.size();
        for(auto it:nums){
            s+=it;
        }
        if((s-k)<0 or (s-k)&1) return 0;
        vector<vector<int>>dp(n,vector<int>(2001,0));
        return solve(nums,n-1,(s-k)/2,dp);
    }
};


// Space Optimization in two rows
class Solution {

    int solve(vector<int>&nums,int n,int k)
    {
        vector<int>prev(k+1,0),cur(k+1,0);
        for(int i=0;i<=k;i++){
            if(i==0 and nums[0]==0){
                prev[0]=2;
            }else if(i==0 or nums[0]==i){
                prev[i]=1;
            }
            else{
                prev[i]=0;
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                int take = 0; 
                if(j-nums[i]>=0)
                    take=prev[j-nums[i]];
                int notTake = prev[j];
                cur[j]=take+notTake;
            }prev=cur;
        }
        return prev[k];
    }
public:
    int findTargetSumWays(vector<int>& nums, int k) {
        int s=0,n=nums.size();
        for(auto it:nums){
            s+=it;
        }
        if((s-k)<0 or (s-k)&1) return 0;
        return solve(nums,n-1,(s-k)/2);
    }
};

//  Space Optimization in one Row
class Solution {

    int solve(vector<int>&nums,int n,int k)
    {
        vector<int>prev(k+1,0);
        for(int i=0;i<=k;i++){
            if(i==0 and nums[0]==0){
                prev[0]=2;
            }else if(i==0 or nums[0]==i){
                prev[i]=1;
            }
            else{
                prev[i]=0;
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=k;j>=0;j--){
                int take = 0; 
                if(j-nums[i]>=0)
                    take=prev[j-nums[i]];
                int notTake = prev[j];
                prev[j]=take+notTake;
            }
        }
        return prev[k];
    }
public:
    int findTargetSumWays(vector<int>& nums, int k) {
        int s=0,n=nums.size();
        for(auto it:nums){
            s+=it;
        }
        if((s-k)<0 or (s-k)&1) return 0;
        return solve(nums,n-1,(s-k)/2);
    }
};
