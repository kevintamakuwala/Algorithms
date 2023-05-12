/*
    Problem Link: https://leetcode.com/problems/fibonacci-number

    The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dp(31, -1);
class Solution
{
public:
    // Memoization
    int memoization(int n)
    {
        if (n <= 1)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = memoization(n - 1) + memoization(n - 2);
    }
    // Tabulation
    int fib(int n)
    {
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
    // SpaceOptimization
    int SpaceOptimization(int n)
    {
        int prev2 = 0;
        int prev = 1;
        int curi = 1;
        for (int i = 2; i <= n; i++)
        {
            curi = prev + prev2;
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};