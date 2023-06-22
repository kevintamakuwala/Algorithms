/*
    Problem Link: https://leetcode.com/problems/wildcard-matching/
    
    Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).
    The matching should cover the entire input string (not partial).

*/

class Solution {
    bool solve(int n,int j,vector<vector<int>>&dp,string &s,string &p)
    {

        // Memoization-----------------------------------------------------------------------------------
        // if(i<0 and j<0) return 1;
        // if(j<0) return 0;
        // if(i<0 and j>=0) {
        //     while(j>=0)
        //     {
        //         if(p[j]=='*') j--;
        //         else return 0;
        //     }
        //     return 1;
        // }
        // if(dp[i][j]!=-1) return dp[i][j];
        // if(p[j]==s[i] or p[j]=='?') {
        //     return dp[i][j] = solve(i-1,j-1,dp,s,p);
        // }
        // if(p[j]=='*')
        // return dp[i][j] = solve(i,j-1,dp,s,p) | solve(i-1,j,dp,s,p);
        // return 0;

        // Tabulation-----------------------------------------------------------------------------------
        for(int k=1;k<=j;k++){
            if(p[k-1]=='*') dp[0][k]=1;
            else break;
        }

        dp[0][0]=1;
        
        for(int i=1;i<=n;i++) {
            for(int k=1;k<=j;k++) {
                if(p[k-1]==s[i-1] or p[k-1]=='?') {
                    dp[i][k] = dp[i-1][k-1];
                }
                if(p[k-1]=='*')
                dp[i][k] = dp[i][k-1] | dp[i-1][k];
            }
        }
        return dp[n][j];
    }
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        // vector<vector<int>>dp(n+2,vector<int>(m+2,0));

        // Space Optimization-----------------------------------------------------------------------------------
        vector<int>prev(m+2,0),cur(m+2,0);
        for(int k=1;k<=m;k++) {
            if(p[k-1]=='*') prev[k]=1;
            else break;
        }
        prev[0]=1;
        for(int i=1;i<=n;i++) {
            for(int k=1;k<=m;k++) {
                if(p[k-1]==s[i-1] or p[k-1]=='?') {
                    cur[k] = prev[k-1];
                }
                else if(p[k-1]=='*')
                cur[k] = cur[k-1] | prev[k];
                else cur[k]=0;
            }
            prev=cur;
        }
        return prev[m];
    }
};
