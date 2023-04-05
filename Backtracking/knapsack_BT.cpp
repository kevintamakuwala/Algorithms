#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

int knapsack(vector<int> weight, vector<int> value, int index, int capacity)
{
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
            return 0;
    }

    int include=0;
    if(weight[index]<=capacity){
        include=value[index]+knapsack(weight,value,index-1,capacity-weight[index]);
    }
    int exclude=0+knapsack(weight,value,index-1,capacity);
    return max(include,exclude);
}
int main()
{
    vector<int> weight = {4, 7, 5, 3};
    vector<int> val = {40, 42, 25, 12};

    cout << knapsack(weight, val, weight.size() - 1, 10);

    // o/p: 65
    return 0;
}