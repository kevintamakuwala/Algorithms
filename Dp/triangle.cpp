/*
    Problem Link: https://leetcode.com/problems/triangle/

    Given a triangle array, return the minimum path sum from top to bottom.
    For each step, you may move to an adjacent number of the row below.
    More formally, if you are on index i on the current row,
    you may move to either index i or index i + 1 on the next row.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Memoization
    int Memoization(vector<vector<int>> &dp, int i, int j, int n, vector<vector<int>> &triangle)
    {
        if (n == i + 1)
        {
            return triangle[n - 1][j];
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = min(Memoization(dp, i + 1, j, n, triangle) + triangle[i][j], Memoization(dp, i + 1, j + 1, n, triangle) + triangle[i][j]);
    }

    // Tabulation
    int Tabulation(vector<vector<int>> &dp, int n, vector<vector<int>> &triangle)
    {

        for (int i = n; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                if (i != n)
                    dp[i][j] = min(dp[i + 1][j] + triangle[i][j],
                                   triangle[i][j] + dp[i + 1][j + 1]);
                else
                    dp[i][j] = triangle[i][j];
            }
        }
        return dp[0][0];
    }

    // Space Optimization
    int helper(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> dp(triangle.back());
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return helper(triangle);
    }
};