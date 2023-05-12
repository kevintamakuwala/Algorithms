/*
    Problem Link: https://leetcode.com/problems/maximal-square/

    Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dp[301][301];
    // Memoization
    int Memoization(int row, int col, int m, int n, vector<vector<char>> &matrix)
    {

        if (row >= m || col >= n || matrix[row][col] == '0')
            return 0;

        if (dp[row][col] != -1)
            return dp[row][col];

        int right = 1 + Memoization(row, col + 1, m, n, matrix);
        int below = 1 + Memoization(row + 1, col, m, n, matrix);
        int diagonal = 1 + Memoization(row + 1, col + 1, m, n, matrix);

        return dp[row][col] = min(right, min(below, diagonal));
    }

    // Space Optimization
    int helper(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
        {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), sz = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!i || !j || matrix[i][j] == '0')
                {
                    dp[i][j] = matrix[i][j] - '0';
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                sz = max(dp[i][j], sz);
            }
        }
        return sz * sz;
    }

public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        // Memoization
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        memset(dp, -1, sizeof dp);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    ans = max(ans, Memoization(i, j, m, n, matrix));
                    ;
                }
            }
        }
        return ans * ans;

        // Space Optimization
        return helper(matrix);
    }
};