/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

    You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
    Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
    Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/
class Solution
{
public:
    int maxProfit(int cnt, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> prev(3, vector<int>(cnt + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k <= cnt; k++)
                {
                    int profit = 0;
                    if (j)
                    {
                        if (k < cnt)
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