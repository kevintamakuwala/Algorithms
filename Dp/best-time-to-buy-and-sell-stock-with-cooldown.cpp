/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

    You are given an array prices where prices[i] is the price of a given stock on the ith day.
    Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
    After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
    Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

class Solution
{
    // int solve(int i,int buy,int cooldown,vector<vector<vector<int>>>&dp,vector<int>& prices)
    // {
    //     if(i==prices.size()) return 0;
    //     if(dp[i][buy][cooldown]!=-1) return dp[i][buy][cooldown];
    //     int profit = 0;
    //     if(buy)
    //     {
    //         if(cooldown)
    //             profit = max(solve(i+1,0,1,dp,prices)-prices[i],solve(i+1,1,1,dp,prices));
    //         else
    //             profit = solve(i+1,1,1,dp,prices);
    //     }
    //     else
    //     {
    //         profit = max(solve(i+1,1,0,dp,prices)+prices[i],solve(i+1,0,1,dp,prices));
    //     }
    //     return dp[i][buy][cooldown]=profit;
    // }
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(2,-1)));
        // return solve(0,1,1,dp,prices);
        vector<vector<int>> prev(2, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    int profit = 0;
                    if (j)
                    {
                        if (k)
                            profit = max(prev[0][1] - prices[i], prev[1][1]);
                        else
                            profit = prev[1][1];
                    }
                    else
                    {
                        profit = max(prev[1][0] + prices[i], prev[0][1]);
                    }
                    prev[j][k] = profit;
                }
            }
        }
        return prev[1][1];
    }
};