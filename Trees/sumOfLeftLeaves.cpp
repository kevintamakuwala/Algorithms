/*
    Problem Link: https://leetcode.com/problems/sum-of-left-leaves/

    Given the root of a binary tree, return the sum of all left leaves.
    A leaf is a node with no children. A left leaf is a leaf that is the
    left child of another node.
*/
/*
*/
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
            
        if(root->left and !root->left->left and !root->left->right)
            return root->left->val + sumOfLeftLeaves(root->right);

        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};