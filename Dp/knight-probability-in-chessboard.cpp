class Solution {
    bool isValid(int i, int j, int n) {
        if (i >= 0 && j >= 0 && i < n && j < n)
            return 1;
        return 0;
    }

public:

    int x[8]={-1,1,-1,1,2,-2,2,-2};
    int y[8]={2,-2,-2,2,-1,1,1,-1};

// Memoization-------------------------------------------------------------------------
    double solve(int i,int j,int k,int n,vector<vector<vector<double>>>&dp)
    {
        if(!k) return 1;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        double c=0;
        for(int ind=0;ind<8;ind++){
            if(isValid(i-x[ind],j-y[ind],n)){
                c = c + solve(i-x[ind],j-y[ind],k-1,n,dp); 
            }
        }
        return dp[i][j][k]=c/8;
    }
    double Memoization(int n, int k, int r, int c) {
        vector<vector<vector<double>>>dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
        return solve(r,c,k,n,dp);
    }

// Tabulation-------------------------------------------------------------------------
    double Tabulation(int n, int k, int r, int c) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, 0)));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j][0] = 1.0;
            }
        }

        for (int moves = 1; moves <= k; ++moves) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    double prob = 0.0;
                    for (int ind = 0; ind < 8; ++ind) {
                        int newX = i + x[ind];
                        int newY = j + y[ind];
                        if (isValid(newX, newY, n)) {
                            prob += dp[newX][newY][moves - 1] / 8.0;
                        }
                    }
                    dp[i][j][moves] = prob;
                }
            }
        }

        return dp[r][c][k];
    }
};
