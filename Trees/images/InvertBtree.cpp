/*
    invert a binary tree or return its mirror image about y-axis
*/

class Solution {
    void helper(TreeNode *&root)
    {
        if(!root) 
            return ;
        helper(root->left);
        helper(root->right);
        swap(root->left,root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root)
    {
        helper(root);
        return root;
    }
};