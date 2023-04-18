/*
    Problem Link: https://leetcode.com/problems/symmetric-tree/

    Given the root of a binary tree, check whether it is a mirror of itself 
    (i.e., symmetric around its center).

*/


// Recursive solution:
class Solution 
{

    bool helper(TreeNode *left,TreeNode *right)
    {
        if(!left || !right)
            return left==right;
        if(left->val != right->val)
            return 0;
        return helper(left->left,right->right) && helper(left->right,right->left);
    }
    public:
    bool isSymmetric(TreeNode* root) {
        
        return (!root)|| helper(root->left,root->right);
    }
};


// iterative solution:
class Solution {
    public:
    bool isSymmetric(TreeNode* root) 
    {
        
        queue<TreeNode *>q;
        q.push(root->right);
        q.push(root->left);
        while(!q.empty())
        {
            TreeNode *lefty=q.front();
            q.pop();
            TreeNode *righty=q.front();
            q.pop();
            
            if((!lefty && righty) ||(lefty && !righty))
            {
                return 0;
            }
            
            else if(lefty && righty)
            {
                if(lefty->val!=righty->val)
                    return 0;
                q.push(lefty->left);
                q.push(righty->right);
                q.push(lefty->right);
                q.push(righty->left);
            }
                
        }
        return 1;
    }  
};

