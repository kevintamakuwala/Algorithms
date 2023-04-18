/*
    Problem Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

    Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

    For each node at position (row, col), its left and right children will 
    be at positions (row + 1, col - 1) 
    and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

    The vertical order traversal of a binary tree is a list of top-to-bottom orderings 
    for each column index starting from the leftmost column and ending on the 
    rightmost column. 
    There may be multiple nodes in the same row and same column. 
    In such a case, sort these nodes by their values.

    Return the vertical order traversal of the binary tree.
*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        queue <pair<TreeNode*,pair<int,int>>>q;
        
        //queue(node,(verticals,level))
        
        q.push({root,{0,0}});
              
        while(!q.empty())
        {
            auto p=q.front();
            
            q.pop();
            
            TreeNode *temp=p.first;
            
            int verticals=p.second.first,levels=p.second.second;
            
            mp[verticals][levels].insert(temp->val);
            
            if(temp->left)
            {
                q.push({temp->left,{verticals-1,levels+1}});
            }
            
            if(temp->right)
            {
                q.push({temp->right,{verticals+1,levels+1}});
            }
        }
        vector<vector<int>>v;
        
         vector<vector<int>> ans;
        for(auto it:mp)
        {
            vector<int> col;
            for(auto p : it.second){
                col.insert(col.end(),p.second.begin(),p.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};