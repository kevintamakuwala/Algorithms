/*
    Problem Link: https://leetcode.com/problems/unique-paths/

    There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
    Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

    The test cases are generated so that the answer will be less than or equal to 2 * 109.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Memoization
    int Memoization(int m, int n, vector<vector<int>> &dp)
    {
        if (m == 0 and n == 0)
            return 1;
        if (m < 0 or n < 0)
            return 0;
        if (dp[m][n] != -1)
            return dp[m][n];
        return dp[m][n] = dp[m - 1][n] + dp[m][n - 1];
    }
    // Tabulation
    int Tabulation(int m, int n, vector<vector<int>> &dp)
    {
        dp[0][0] = 1;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i < 1 or j < 1)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
    // Space Optimization
    int helper(int m, int n)
    {
        vector<int> prev(n + 1, 0);
        for (int i = 0; i <= m; i++)
        {
            vector<int> temp(n + 1);
            for (int j = 0; j <= n; j++)
            {
                if (i < 1 or j < 1)
                    temp[j] = 1;
                else
                    temp[j] = prev[j] + temp[j - 1];
            }
            prev = temp;
        }
        return prev[n];
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1);
    }
};