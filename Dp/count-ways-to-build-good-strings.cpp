/*
  Problem link: https://leetcode.com/problems/count-ways-to-build-good-strings/
  Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, 
  and then at each step perform either of the following:
      Append the character '0' zero times.
      Append the character '1' one times.
  This can be performed any number of times.
  A good string is a string constructed by the above process having a length between low and high (inclusive).
  
  Return the number of different good strings that can be constructed satisfying these properties.
  
  Since the answer can be large, return it modulo 10^9 + 7.
*/
class Solution {
//      Memoization
    int Memoization(int i,int zero,int one,vector<int>&dp)
    {
        if(i==0) 
            return 1;
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int Z = Memoization(i-zero,zero,one,dp);
        int O = Memoization(i-one,zero,one,dp);
        return dp[i]=(Z +O)%1000000007;
    }
//     Tabulation
    int Tabulation(int low, int high, int zero, int one) 
    {
        int total=0;
        vector<int>dp(high+1,-1);
        dp[0]=1;
        for(int i=1;i<= high;i++)
        {
            long long Z=0,O=0;
            if(i>=one)
              Z=dp[i-one]%1000000007;
            if(i>=zero)
              O=dp[i-zero]%1000000007;

            dp[i] = (Z +O)%1000000007;
            if(i>=low and i<=high)
            {
                total=(total%1000000007+dp[i]%1000000007)%1000000007;
            }
        }
        return total;        
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        int total=0;
        vector<int>dp(high+1,-1);
        for(int i=low;i<=high;i++)
         total=(total%1000000007+Memoization(i,zero,one,dp)%1000000007)%1000000007;
        return total;
    }
};
