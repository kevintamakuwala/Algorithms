/*
    Problem Link: https://leetcode.com/problems/climbing-stairs/

    You are climbing a staircase. It takes n steps to reach the top.
    Each time you can either climb 1 or 2 steps.
    In how many distinct ways can you climb to the top?
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dp(46, -1);
class Solution
{
public:
    // Memoization
    int climbStairs(int n)
    {
        if (n <= 2)
        {
            return n;
        }
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = climbStairs(n - 2) + climbStairs(n - 1);
    }

    // Tabulation
    int Tabulation(int n)
    {
        if (n <= 2)
            return n;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    // Space Optimization
    int SpaceOptimization(int n)
    {
        if (n <= 2)
            return n;            
        int prev2 = 0;
        int prev = 1;
        int curi = 1;

        for (int i = 3; i <= n; i++)
        {
            curi = prev + prev2;
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
};
