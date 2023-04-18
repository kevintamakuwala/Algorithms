/*
    Problem Link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
   
    The task is to print the top view of binary tree. 
    Top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

    Note: Return nodes from leftmost node to rightmost node. 
    Also if 2 nodes are outside the shadow of the tree and are at same position then 
    consider the extreme ones only (i.e. leftmost and rightmost). 
    For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. 
    Here 8 and 9 are on the same position but 9 will get shadowed.
*/

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int,int>mp;
        queue<pair<Node *,int>>q;
        q.push({root,0});
        
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            Node *temp=it.first;
            int verticals=it.second;
            
            if(mp.find(verticals)==mp.end())
            mp[verticals]=temp->data;
            
            if(temp->left)
            q.push({temp->left,verticals-1});
            if(temp->right)
            q.push({temp->right,verticals+1});
            
        }
        vector <int>v;
        for(auto it:mp)
        {
            v.push_back(it.second);
        }
        return v;
    }

};