/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced
binary search tree.
*/

class Solution {
    TreeNode *helper(vector<int>&v,int low,int high)
    {
        if(low<=high)
        {
            int mid=(low+high)/2;
            TreeNode *root=new TreeNode(v[mid]);
            root->left=helper(v,low,mid-1);
            root->right=helper(v,mid+1,high);
            return root;
        }
        return NULL;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& v) 
    {
       return helper(v,0,v.size()-1);
    }
    
};