#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
int knapsack(vector<int> weight, vector<int> value, int n, int capacity)
{

    int dp[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
            else if (weight[i - 1] <= j)
            {
                dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "\n\n\n";
    return dp[n][capacity];
}
int main()
{
    vector<int> weight = {3, 4, 6, 5};
    vector<int> val = {2, 3, 1, 4};

    cout << knapsack(weight, val, weight.size(), 8);
    return 0;
}