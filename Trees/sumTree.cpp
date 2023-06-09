/*
    Problem Link: https://practice.geeksforgeeks.org/problems/sum-tree/1
    
    Given a Binary Tree. 
    Return true if, for every node X in the tree other than the leaves, 
    its value is equal to the sum of its left subtree's value and its right subtree's value. 
    Else return false.

    An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.
*/

class Solution
{
    public:
    int sum(Node *root)
    {
        
        if(!root) 
            return 0;
        if(!root->left and !root->right) 
            return root->data;
        int s=sum(root->left)+sum(root->right);
        if(s!=root->data) return 0;
        else
        return root->data+s;
        
    }
    bool isSumTree(Node* root)
    {
        return sum(root);
    }
};