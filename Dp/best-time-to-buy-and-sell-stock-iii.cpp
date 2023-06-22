/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

    You are given an array prices where prices[i] is the price of a given stock on the ith day.
    Find the maximum profit you can achieve. You may complete at most two transactions.
    Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/
class Solution
{
    int solve(int i, int buy, int cnt, vector<vector<vector<int>>> &dp, vector<int> &prices)
    {
        if (i == prices.size())
        {
            return 0;
        }
        if (dp[i][buy][cnt] != -1)
            return dp[i][buy][cnt];
        int profit = 0;
        if (buy)
        {
            if (cnt < 2)
            {
                profit = max(solve(i + 1, 1, cnt, dp, prices), solve(i + 1, 0, cnt + 1, dp, prices) - prices[i]);
            }
            else
            {
                profit = solve(i + 1, 1, cnt, dp, prices);
            }
        }
        else
        {
            profit = max(solve(i + 1, 1, cnt, dp, prices) + prices[i], solve(i + 1, 0, cnt, dp, prices));
        }
        return dp[i][buy][cnt] = profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(3,0)));
        // return solve(0,1,0,dp,prices);
        vector<vector<int>> prev(3, vector<int>(3, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k <= 2; k++)
                {
                    int profit = 0;
                    if (j)
                    {
                        if (k < 2)
                        {
                            profit = max(prev[1][k], prev[0][k + 1] - prices[i]);
                        }
                        else
                        {
                            profit = prev[1][k];
                        }
                    }
                    else
                    {
                        profit = max(prev[1][k] + prices[i], prev[0][k]);
                    }
                    prev[j][k] = profit;
                }
            }
        }
        return prev[1][0];
    }
};