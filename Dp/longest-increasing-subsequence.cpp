/*
    Problem Link: https://leetcode.com/problems/longest-increasing-subsequence/
    
    Given an integer array nums, return the length of the longest strictly increasing subsequence.
*/
//  Memoization
class Solution
{
public:
    int f(int i, int j, vector<vector<int>> &dp, vector<int> &nums)
    {
        if (i == nums.size())
        {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int pick = -1e9, notPick;
        if(i==j) {
            pick=1+f(i+1,i,dp,nums);
            notPick=f(i+1,i+1,dp,nums);
            return dp[i][j]=max(pick,notPick);
        }
        else if (nums[i] > nums[j])
            pick = f(i + 1, i, dp, nums)+1 ;
        notPick = f(i + 1, j, dp, nums);        
        return dp[i][j] = max(pick, notPick);
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n , -1));
        return f(0, 0, dp, nums);
    }
};
//  Tabulation
class Solution
{
public:
    int f(int i, int j, vector<vector<int>> &dp, vector<int> &nums)
    {
        int n=nums.size();
        for(int i=n-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--){
                int pick = -1e9, notPick;
                if(j==n-1) {
                    dp[i][j]=1;
                    continue;
                }
                if(i==n-1){
                    dp[i][j]=(nums[i]>nums[j])?1:0;
                    continue;
                }
                if(i==j) {
                    pick=1+dp[i+1][i];
                    notPick=dp[i+1][i+1];
                    dp[i][j]=max(pick,notPick);
                    continue;
                }
                else if (nums[i] > nums[j])
                    pick = dp[i + 1][i]+1 ;
                notPick = dp[i + 1][j];        
                dp[i][j] = max(pick, notPick);
            }
        }

        return dp[0][0];
        
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n , 0));
        return f(0, 0, dp, nums);
    }
};
//  Space Optimization

class Solution
{
public:
    int f(vector<int> &nums)
    {
        int n=nums.size();
        vector<int>prev(n+1),cur=prev;
        for(int i=n-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--){
                int pick = -1e9, notPick;
                if(j==n-1) {
                    cur[j]=1;
                    continue;
                }
                if(i==n-1){
                    cur[j]=(nums[i]>nums[j])?1:0;
                    continue;
                }
                if(i==j) {
                    pick=1+prev[i];
                    notPick=prev[i+1];
                    cur[j]=max(pick,notPick);
                    continue;
                }
                else if (nums[i] > nums[j])
                    pick = prev[i]+1 ;
                notPick = prev[j];        
                cur[j] = max(pick, notPick);
            }
            prev=cur;
        }

        return prev[0];
        
    }
    int lengthOfLIS(vector<int> &nums)
    {
        return f(nums);
    }
};
