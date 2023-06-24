/*
    Problem Link: https://leetcode.com/problems/tallest-billboard/

    You are installing a billboard and want it to have the largest height. 
    The billboard will have two steel supports, one on each side. Each steel support must be an equal height.
    You are given a collection of rods that can be welded together.
    For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.
    Return the largest possible height of your billboard installation. If you cannot support the billboard, return 0.
*/
class Solution {
    
public:

    int tallestBillboard(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        
        int sum = 0;
        for (int num : arr) {
            sum += num;
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, -1e9));
        int offset = sum;
        
        dp[0][offset] = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int j = -sum; j <= sum; j++) {
                dp[i][j + offset] = dp[i - 1][j + offset];
                
                if (j - arr[i - 1] >= -sum && j - arr[i - 1] <= sum) {
                    dp[i][j + offset] = max(dp[i][j + offset], dp[i - 1][j - arr[i - 1] + offset] + arr[i - 1]);
                }
                
                if (j + arr[i - 1] >= -sum && j + arr[i - 1] <= sum) {
                    dp[i][j + offset] = max(dp[i][j + offset], dp[i - 1][j + arr[i - 1] + offset] + arr[i - 1]);
                }
            }
        }
        return dp[n][offset]<0?0:dp[n][offset]/2;
    }
};
