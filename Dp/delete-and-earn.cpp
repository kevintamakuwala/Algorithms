/*
    Problem Link: https://leetcode.com/problems/delete-and-earn/

    You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:
    Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
    Return the maximum number of points you can earn by applying the above operation some number of times.


*/

#include <bits/stdc++.h>
using namespace std;
// Time:  O(n)
// Space: O(1)

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        vector<int> vals(10001);
        for (const auto &num : nums)
        {
            vals[num] += num;
        }
        int val_i = vals[0], val_i_1 = 0, val_i_2 = 0;
        for (int i = 1; i < vals.size(); ++i)
        {
            val_i_2 = val_i_1;
            val_i_1 = val_i;
            val_i = max(vals[i] + val_i_2, val_i_1);
        }
        return val_i;
    }
};
