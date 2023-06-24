/*
    Problem Link: https://leetcode.com/problems/russian-doll-envelopes/

    You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
    One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
    Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).    
    Note: You cannot rotate an envelope.
*/
class Solution {
    // Tabulation ( Gives TLE TC: O(N*N) ) :==
    int solve(int n,int prev_ind,vector<vector<int>>&envelopes,vector<vector<int>>&dp)
    {
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i-1;j>=-1;j--)
            {
                int t=0,nt=dp[i+1][j+1];
                if(j==-1 or ( envelopes[i][1]>envelopes[j][1] and envelopes[i][0]>envelopes[j][0]))
                {
                    t=dp[i+1][i+1]+1;
                }
                dp[i][j+1] = max(t,nt);   
            }
        }
        return dp[0][0];
    }
public:
    static auto compare (const vector<int> & a, const vector<int> & b) {
        return a[0]<b[0] || (a[0]==b[0] and a[1]>b[1]);
    };
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),compare);
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // return solve(n,-1,envelopes,dp);

        // DP + Binary Search TC:O(NlogN) :==
        vector<int>dp;
        dp.push_back(envelopes[0][1]);
        int size=1;
        for(int i=1;i<n;i++) 
        {
            if(dp.back()<envelopes[i][1]) {
                dp.push_back(envelopes[i][1]);
                size++;
            }
            else
            {
                auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1])-dp.begin();
                dp[it] = envelopes[i][1];
            }
        }
        return size;
    }
};
