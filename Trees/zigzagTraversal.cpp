/*
    Problem Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
    
    Given the root of a binary tree, return the zigzag level order traversal 
    of its nodes' values. (i.e., from left to right, then right to left for the 
    next level and alternate between).
*/  

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        queue <TreeNode *>q;
        if(!root) return result;
        q.push(root);
        bool flag=1;
        while(!q.empty())
        {
            
            int size=q.size();
            vector<int>rows(size);
            
            for(int i=0;i<size;i++)
            {
                TreeNode *node=q.front();
                q.pop();
                int index;
                if(flag==1)
                    index=i;
                else
                    index=size-i-1;
                rows[index]=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            flag=!flag;
            result.push_back(rows);
            
        }
        return result;
    }
};