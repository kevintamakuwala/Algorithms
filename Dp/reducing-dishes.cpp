/*
    Problem Link: https://leetcode.com/problems/reducing-dishes/
    A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
    Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].    
    Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.
    Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.
*/
class Solution {
    // Memoization:==
    int solve(vector<int>& satisfaction,int time,int i,vector<vector<int>>& dp)
    {
        if(i==satisfaction.size())
        {
            return 0;
        }
        if(dp[i][time]!=-1) return dp[i][time];
        int t = 0, nt = solve(satisfaction,time,i+1,dp);
        t=solve(satisfaction,time+1,i+1,dp) + time*satisfaction[i];
        return dp[i][time] = max(t,nt);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solve(satisfaction,1,0,dp);

        // Tabulation/ Space Optimization :==
        vector<int>prev(n+2,0),cur=prev;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n;j>=1;j--)
            {
                int t = 0, nt = prev[j];
                t=prev[j+1] + j*satisfaction[i];
                cur[j] = max(t,nt);
            }
            prev=cur;
        }
        return prev[1];
    }
};
