/*
    Problem Link: https://practice.geeksforgeeks.org/problems/root-to-leaf-path-sum/1

    Given a binary tree and an integer S, check whether there is root to leaf path with its sum as S.

*/

class Solution
{
    bool solve(Node* root,int s,int S)
    {
        if(!root) 
            return 0;
        
        s+=root->data;
        
        if(!root->left && !root->right)
            return s==S;
        
        return  solve(root->left,s,S) ||
                solve(root->right,s,S);
        
    }    
    public:
    bool hasPathSum(Node *root, int S) 
    {   
        return solve(root,0,S);
    }
};
