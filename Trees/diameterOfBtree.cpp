/*

    Problem Link: https://leetcode.com/problems/diameter-of-binary-tree/
    
    Given the root of a binary tree, return the length of the diameter of the tree.
    The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
    The length of a path between two nodes is represented by the number of edges between them.
*/
class Solution {
    int helper(TreeNode *root,int &diameter ){
        if(!root) 
            return 0;
        int c1=helper(root->left,diameter);
        int c2=helper(root->right,diameter);
        
        diameter=max(diameter,c1+c2);
        return max(c1,c2)+1;
    }
public:    
    int diameterOfBinaryTree(TreeNode* root) {
                
        int diameter=0;
        helper(root,diameter);
        return (diameter);
    }
};