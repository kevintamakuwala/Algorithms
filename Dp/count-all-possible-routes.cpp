/*
    Problem Link: https://leetcode.com/problems/count-all-possible-routes/
    
    You are given an array of distinct positive integers locations where locations[i] represents the position of city i.
    You are also given integers start, finish and fuel representing the starting city, ending city, and the initial amount of fuel you have, respectively.
    At each step, if you are at city i, you can pick any city j such that j != i and 0 <= j < locations.length and move to city j. 
    Moving from city i to city j reduces the amount of fuel you have by |locations[i] - locations[j]|.
    Please notice that |x| denotes the absolute value of x.    
    Notice that fuel cannot become negative at any point in time, and that you are allowed to visit any city more than once (including start and finish).
    Return the count of all possible routes from start to finish. Since the answer may be too large, return it modulo 109 + 7.
*/
class Solution {
    const int mod=1e9+7;
    int solve(int i, int fuel, int& e, vector<int>& locations,vector<vector<int>>&dp)  
    {
        if(fuel<0) return 0;
        if(dp[i][fuel]!=-1) return dp[i][fuel];
        int ans = (i==e);
        for(int j=0; j<locations.size(); ++j){
            if(i==j) continue;
            ans = (ans+solve(j,fuel-abs(locations[j]-locations[i]), e, locations,dp)) % mod;
        }
        return dp[i][fuel] = ans;
  }
public:
  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
      vector<vector<int>>dp(101,vector<int>(2001,-1));
      return solve(start,fuel,finish,locations,dp);
  }
};
