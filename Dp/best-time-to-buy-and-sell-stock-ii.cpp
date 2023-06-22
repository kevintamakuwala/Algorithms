/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

    You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
    On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
    Find and return the maximum profit you can achieve.
*/
class Solution
{
    int solve(int i, int buy, vector<vector<int>> &dp, vector<int> &prices)
    {
        // if(i==prices.size()){
        //     return 0;
        // }
        // if(dp[i][buy]!=-1) return dp[i][buy];
        // int profit=0;
        // if(buy){
        //     profit=max(solve(i+1,1,dp,prices),solve(i+1,0,dp,prices)-prices[i]);
        // }else{
        //     profit=max(solve(i+1,1,dp,prices)+prices[i],solve(i+1,0,dp,prices));
        // }
        // return dp[i][buy]=profit;
        dp[prices.size()] = {0, 0};
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < 2; j++)
            {
                int profit = 0;
                if (j)
                {
                    profit = max(dp[i + 1][j], dp[i + 1][j - 1] - prices[i]);
                }
                else
                {
                    profit = max(dp[i + 1][j + 1] + prices[i], dp[i + 1][j]);
                }
                dp[i][j] = profit;
                // cout<<profit<< " ";
            }
            // cout<<'\n';
        }
        return dp[0][1];
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(3,0));
        // return solve(0,1,dp,prices);
        vector<int> prev(2, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 2; j++)
            {
                int profit = 0;
                if (j)
                {
                    profit = max(prev[j], prev[j - 1] - prices[i]);
                }
                else
                {
                    profit = max(prev[j + 1] + prices[i], prev[j]);
                }
                prev[j] = profit;
                // cout<<profit<< " ";
            }
            // prev=cur;
            // cout<<'\n';
        }
        return prev[1];
    }
};