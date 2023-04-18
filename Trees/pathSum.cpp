/*
    Problem Link: https://leetcode.com/problems/path-sum/

    Given the root of a binary tree and an integer targetSum, 
    return true if the tree has a root-to-leaf path such that 
    adding up all the values along the path equals targetSum.

    A leaf is a node with no children.
*/

class Solution {
public: 
    bool hasPathSum(TreeNode* root, int sum) 
    {         
        if(!root) 
            return 0;
        
        if(root->val ==sum && !root->left && !root->right) 
            return 1;
        
        return  hasPathSum(root->left,sum - root->val)  ||
                hasPathSum(root->right,sum  - root->val);
    }    
};