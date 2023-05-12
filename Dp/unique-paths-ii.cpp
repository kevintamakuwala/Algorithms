/*
    Problem Link: https://leetcode.com/problems/unique-paths-ii/

    You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
    An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
    Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

    The testcases are generated so that the answer will be less than or equal to 2 * 109.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

    // Memoization
    int Memoization(int n, int m, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
    {
        if (n < 0 or m < 0 or obstacleGrid[n][m] == 1)
            return 0;
        if (n == 0 and m == 0)
            return 1;
        if (dp[n][m] != -1)
            return dp[n][m];
        return dp[n][m] = Memoization(n, m - 1, obstacleGrid, dp) + Memoization(n - 1, m, obstacleGrid, dp);
    }

    // Tabulation
    int Tabulation(int n, int m, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
    {
        dp[0][0] = (obstacleGrid[0][0] == 0) ? 1 : 0;
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = (obstacleGrid[i][0] == 0) ? dp[i - 1][0] : 0;
        }
        for (int i = 1; i <= m; i++)
        {
            dp[0][i] = (obstacleGrid[0][i] == 0) ? dp[0][i - 1] : 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                else
                    dp[i][j] = 0;
            }
        }
        return dp[n][m];
    }

public:
    int minPathSum(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return Tabulation(n - 1, m - 1, obstacleGrid, dp);
    }
};