/*
  Problem Link: https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980
*/
#include <bits/stdc++.h>>
using namespace std;


// Memoization
bool Memoization(vector<int> &arr, int i, int k, vector<vector<int>> &dp)
{
    if (i == 0)
        return k == arr[0];

    if (i < 0)
        return 0;

    if (dp[i][k] != -1)
        return dp[i][k];

    int notTake = Memoization(arr, i - 1, k, dp);
    int take = 0;

    if (k >= arr[i])
        take = Memoization(arr, i - 1, k - arr[i], dp);

    return dp[i][k] = (take | notTake);
}

// Tabulation
bool Tabulation(vector<int> &arr, int n, int k, vector<vector<bool>> &dp)
{

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    if (arr[0] <= k)
        dp[0][arr[0]] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int notTake = dp[i - 1][j];
            int take = 0;
            if (j >= arr[i])
                take = dp[i - 1][j - arr[i]];

            dp[i][j] = (take | notTake);
        }
    }
    return dp[n][k];
}

// SpaceOptimization
bool SpaceOptimization(vector<int> &arr, int n, int k)
{
    vector<bool> prev(k + 1, 0);
    prev[0] = 1;

    if (arr[0] <= k)
        prev[arr[0]] = 1;

    for (int i = 1; i <= n; i++)
    {
        vector<bool> temp(k + 1, 0);
        for (int j = 1; j <= k; j++)
        {
            int notTake = prev[j];
            int take = 0;
            if (j >= arr[i])
                take = prev[j - arr[i]];

            temp[j] = (take | notTake);
        }
        prev = temp;
    }
    return prev[k];
}

bool canPartition(vector<int> &arr, int n)
{
    int s = 0;
    for (auto it : arr)
        s += it;

    if (s % 2)
        return 0;
    return SpaceOptimization(arr, n - 1, s / 2);
}
