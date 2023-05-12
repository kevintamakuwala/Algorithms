/*
    Problem Link: https://leetcode.com/problems/min-cost-climbing-stairs/

    You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
    You can either start from the step with index 0, or the step with index 1.
    Return the minimum cost to reach the top of the floor.
*/

#include <bits/stdc++.h>
using namespace std;
vector<int>dp(1001,-1);
class Solution {    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        for(int i=2;i<n;i++)
        {
            cost[i]+=min(cost[i-1],cost[i-2]);
        }
        return min(cost[n-1],cost[n-2]);
    }
};