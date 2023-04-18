/*
    Problem Link: https://leetcode.com/problems/merge-two-binary-trees/

    You are given two binary trees root1 and root2.

    Imagine that when you put one of them to cover the other, some nodes of the two
    trees are overlapped while the others are not.
    You need to merge the two trees into a new binary tree.
    The merge rule is that if two nodes overlap, then sum node values up as 
    the new value of the merged node. 
    Otherwise, the NOT null node will be used as the node of the new tree.

    Return the merged tree.

    Note: The merging process must start from the root nodes of both trees.

*/

class Solution
{
    public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
    {
        if(!t1 && !t2) return nullptr;
        if(!t1) return t2;
        if(!t2) return t1;
        t1->val+=t2->val;
        t1->left = mergeTrees(t1->left,t2->left);
        t1->right = mergeTrees(t1->right,t2->right);
        return t1;
    }
};