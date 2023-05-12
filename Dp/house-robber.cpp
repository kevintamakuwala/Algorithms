/*
    Problem Link: https://leetcode.com/problems/house-robber/

    You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

    Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Memoization
    int memoization(int n, vector<int> &nums, vector<int> &dp)
    {
        if (n == 0)
            return nums[0];
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int take = memoization(n - 2, nums, dp) + nums[n];
        int notTake = memoization(n - 1, nums, dp);
        return dp[n] = max(take, notTake);
    }

    // Tabulation
    int Tabulation(vector<int> &nums, vector<int> &dp)
    {
        int n = nums.size() - 1;

        dp[0] = nums[0];
        for (int i = 1; i <= n; i++)
        {
            int take = 0;
            if (i > 1)
                take += dp[i - 2];

            take += nums[i];
            int notTake = dp[i - 1];
            dp[i] = max(take, notTake);
        }
        return dp[n];
    }
    // Space Optimization
    int helper(vector<int> &nums)
    {
        int n = nums.size() - 1;
        int prev2 = 0;
        int prev = nums[0];
        int curi = prev;

        for (int i = 1; i <= n; i++)
        {
            int take = 0;
            if (i > 1)
                take += prev2;

            take += nums[i];
            int notTake = prev;
            curi = max(take, notTake);

            prev2 = prev;
            prev = curi;
        }
        return prev;
    }

public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1, -1);
        return helper(nums);
    }
};