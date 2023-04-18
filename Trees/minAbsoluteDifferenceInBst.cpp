/*
    Problem Link: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
    Given the root of a Binary Search Tree (BST), 
    return the minimum absolute difference between the values of any two different nodes 
    in the tree.
*/
class Solution {
public:
    
    TreeNode *prev=NULL;

    int p=INT_MAX;
    int getMinimumDifference(TreeNode* root)
    {
        return helper(root);
    }
    int helper(TreeNode* root) 
    {
        
        if(!root)
            return 0 ;
        helper(root->left); 
        
        if(prev)
        p=min(p,abs(prev->val-root->val));
        
        prev=root;
        
        helper(root->right);
        return p;
    }
};