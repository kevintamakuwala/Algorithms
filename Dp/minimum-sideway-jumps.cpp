/*
    Problem Link: https://leetcode.com/problems/minimum-sideway-jumps/

    There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. 
    A frog starts at point 0 in the second lane and wants to jump to point n. 
    However, there could be obstacles along the way.
    You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle on the lane obstacles[i] at point i. 
    If obstacles[i] == 0, there are no obstacles at point i. 
    There will be at most one obstacle in the 3 lanes at each point.
    
      For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.
      The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the lane at point i + 1. To avoid obstacles, the frog can also perform a side jump to jump to another lane (even if they are not adjacent) at the same point if there is no obstacle on the new lane.
    
      For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.
      Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0.
    
    Note: There will be no obstacles on points 0 and n.
*/

class Solution {
    // Memoization :==
    // int solve(int i,int lane,vector<int>&obstacles,vector<vector<int>>&dp)
    // {
    //     if(i==obstacles.size()-1) return 0;
    //     if(dp[i][lane]!=-1) return dp[i][lane];
    //     int ans=1e9;
    //     if(obstacles[i+1]==0 or obstacles[i+1] != lane)
    //        ans = solve(i+1,lane,obstacles,dp);
    //     else
    //     {
    //         for(int ind=1;ind<=3;ind++){
    //             if(lane!=ind  and obstacles[i]!=ind)
    //                 ans = min(ans,1+solve(i+1,ind,obstacles,dp)); 
    //         }
    //     }
    //     return dp[i][lane] = ans;
    // }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        // vector<vector<int>>dp(n+1,vector<int>(4,-1));
        // return solve(0,2,obstacles,dp);

        // Tabulation/ Space Optimization :==
        vector<int>prev(4,0);
        for(int i=n-2;i>=0;i--)
        {
            for(int j = 3;j>=1;j--)
            {
                int ans=1e9;
                if(obstacles[i+1]==0 or obstacles[i+1] != j)
                ans = prev[j];
                else
                {
                    for(int ind=1;ind<=3;ind++)
                    {
                        if(j!=ind  and obstacles[i]!=ind)
                        ans = min(ans,1+prev[ind]); 
                    }          
                }
                prev[j] = ans;
            }
        }
        return prev[2];
    }
};
