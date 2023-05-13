// Problem Link: https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494

#include <bits/stdc++.h>
using namespace std;

// Tabulation
int Tabulation(vector<int> &arr, int k, int n, vector<vector<bool>> &dp)
{
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    if (k >= arr[0])
        dp[0][arr[0]] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool take = 0;
            bool notTake = dp[i - 1][j];
            if (j >= arr[i])
            {
                take = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = take | notTake;
        }
    }

    int s1 = 0;
    int mini = 1e9;
    for (int i = 0; i <= k; i++)
    {
        if (dp[n][i])
        {
            s1 = i;
            mini = min(mini, abs(s1 - k + s1));
        }
    }
    return mini;
}
// SpaceOptimization
int SpaceOptimization(vector<int> &arr, int k, int n)
{
    vector<bool> prev(k + 1, 0);
    prev[0] = 1;
    if (arr[0] <= k)
        prev[arr[0]] = 1;

    for (int i = 1; i <= n; i++)
    {
        vector<bool> temp(k + 1, 0);
        temp[0] = 1;
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
    int s1 = 0;
    int mini = 1e9;
    for (int i = 0; i <= k; i++)
    {
        if (prev[i])
        {
            s1 = i;
            mini = min(mini, abs(s1 - k + s1));
        }
    }
    return mini;
}
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int sum = 0;
    for (auto it : arr)
        sum += it;
    return SpaceOptimization(arr, sum, n - 1);
}
