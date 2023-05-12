/*
    Problem Link: https://leetcode.com/problems/minimum-falling-path-sum/

    Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
    A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Memoization
    int Memoization(int i, int j, int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (i < 0 or j < 0 or j > m)
            return 1e9;
        if (i == 0)
        {
            return matrix[i][j];
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int left = matrix[i][j] + Memoization(i - 1, j - 1, n, m, matrix, dp);
        int up = matrix[i][j] + Memoization(i - 1, j, n, m, matrix, dp);
        int right = matrix[i][j] + Memoization(i - 1, j + 1, n, m, matrix, dp);
        return dp[i][j] = min(left, min(up, right));
    }

    // Tabulation
    int Tabulation(int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {

        int mini = 1e9;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0)
                    dp[i][j] = matrix[i][j];
                else if (j == 0)
                    dp[i][j] = min(matrix[i][j] + dp[i - 1][j], matrix[i][j] + dp[i - 1][j + 1]);
                else if (j == m)
                    dp[i][j] = min(matrix[i][j] + dp[i - 1][j], matrix[i][j] + dp[i - 1][j - 1]);
                else
                    dp[i][j] = min(min(matrix[i][j] + dp[i - 1][j], matrix[i][j] + dp[i - 1][j + 1]), matrix[i][j] + dp[i - 1][j - 1]);
                if (i == n)
                {
                    mini = min(mini, dp[n][j]);
                }
            }
        }
        return mini;
    }

    // Space Optimization
    int helper(int n, int m, vector<vector<int>> &matrix)
    {
        int mini = 1e9;
        vector<int> prev(m + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            vector<int> temp(m + 1);
            for (int j = 0; j <= m; j++)
            {
                if (i == 0)
                    temp[j] = matrix[i][j];
                else if (j == 0)
                    temp[j] = min(matrix[i][j] + prev[j], matrix[i][j] + prev[j + 1]);
                else if (j == m)
                    temp[j] = min(matrix[i][j] + prev[j], matrix[i][j] + prev[j - 1]);
                else
                    temp[j] = min(min(matrix[i][j] + prev[j], matrix[i][j] + prev[j + 1]), matrix[i][j] + prev[j - 1]);
                if (i == n)
                    mini = min(mini, temp[j]);
            }
            prev = temp;
        }
        return mini;
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // Memoization
        int mini = 1e9;
        for (int i = 0; i < m; i++)
            mini = min(mini, Memoization(n - 1, i, n - 1, m - 1, matrix, dp));
        return mini;

        // Tabulation
        return Tabulation(n - 1, m - 1, matrix, dp);
        
        // Space optimization
        return helper(n - 1, m - 1, matrix);
    }
};