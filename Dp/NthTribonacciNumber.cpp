/*
    Problem Link: https://leetcode.com/problems/n-th-tribonacci-number/

    The Tribonacci sequence Tn is defined as follows:
    T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
    Given n, return the value of Tn.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dp(38, -1);
class Solution
{
public:
    // Memoization
    int memoization(int n)
    {
        if (n < 2)
            return n;
        if (n == 2)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = memoization(n - 1) + memoization(n - 2);
    }
    // Tabulation
    int tribonacci(int n)
    {
        if (n < 2)
            return n;
        if (n == 2)
            return 1;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        return dp[n];
    }
    // SpaceOptimization
    int SpaceOptimization(int n)
    {
        if (n < 2)
            return n;
        if (n == 2)
            return 1;

        int prev3 = 0;
        int prev2 = 1;
        int prev = 1;
        int curi = 2;
        for (int i = 3; i <= n; i++)
        {
            curi = prev + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};