/*
    Problem Link: https://leetcode.com/problems/minimum-path-sum/

    Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
    Note: You can only move either down or right at any point in time.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    
    // Memoization
    int Memoization(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (n == 0 and m == 0)
            return grid[0][0];
        if (n < 0 or m < 0)
            return INT_MAX;
        if (dp[n][m] != -1)
            return dp[n][m];
        int up = Memoization(n - 1, m, grid, dp);
        int down = Memoization(n, m - 1, grid, dp);
        return dp[n][m] = min(up, down) + grid[n][m];
    }

    // Tabulation
    int Tabulation(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == j and j == 0)
                {
                    dp[0][0] = grid[0][0];
                }
                else if (i == 0)
                {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                }
                else if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }
        return dp[n][m];
    }

    // Space Optimization
    int helper(int n, int m, vector<vector<int>> &grid)
    {
        vector<int> prev(m + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            vector<int> temp(m + 1);
            for (int j = 0; j <= m; j++)
            {
                if (i == j and j == 0)
                {
                    temp[0] = grid[0][0];
                }
                else if (i == 0)
                {
                    temp[j] = temp[j - 1] + grid[i][j];
                }
                else if (j == 0)
                {
                    temp[j] = prev[j] + grid[i][j];
                }
                else
                {
                    temp[j] = min(prev[j], temp[j - 1]) + grid[i][j];
                }
            }
            prev = temp;
        }
        return prev[m];
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n - 1, m - 1, grid);
    }
};