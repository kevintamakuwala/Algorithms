/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

    You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
    Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
    Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/
class Solution
{
    // int solve(int i,int buy,vector<int>&prices,vector<vector<int>>&dp,int fee)
    // {
    //     if(i==prices.size())
    //     {
    //         return 0;
    //     }
    //     if(dp[i][buy]!=-1) return dp[i][buy];
    //     int profit=0;
    //     if(buy) {
    //         profit = max(solve(i+1,0,prices,dp,fee)-prices[i]-fee,solve(i+1,1,prices,dp,fee));
    //     }
    //     else {
    //         profit = max(solve(i+1,1,prices,dp,fee)+prices[i],solve(i+1,0,prices,dp,fee));
    //     }
    //     return dp[i][buy]=profit;
    // }
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // return solve(0,1,prices,dp,fee);
        vector<int> prev(2, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 2; j++)
            {
                int profit = 0;
                if (j)
                {
                    profit = max(prev[0] - prices[i] - fee, prev[1]);
                }
                else
                {
                    profit = max(prev[1] + prices[i], prev[0]);
                }
                prev[j] = profit;
            }
        }
        return prev[1];
    }
};