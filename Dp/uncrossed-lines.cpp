/*
  Problem Link: https://leetcode.com/problems/uncrossed-lines/
  
  You are given two integer arrays nums1 and nums2. 
  We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.
  We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:
  nums1[i] == nums2[j], and the line we draw does not intersect any other connecting (non-horizontal) line.   
  Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).
  Return the maximum number of connecting lines we can draw in this way.
*/
class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() < nums2.size())
        {
            return maxUncrossedLines(nums2, nums1);
        }
        vector<vector<int>> dp(2, vector<int>(nums2.size() + 1));
        for (int i = 0; i < nums1.size(); ++i)
        {
            for (int j = 0; j < nums2.size(); ++j)
            {
                dp[(i + 1) % 2][j + 1] = max(dp[i % 2][j] + static_cast<int>(nums1[i] == nums2[j]),
                                             max(dp[i % 2][j + 1], dp[(i + 1) % 2][j]));
            }
        }
        return dp[(nums1.size()) % 2][nums2.size()];
    }
};
