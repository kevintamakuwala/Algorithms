/*
    Problem Link: https://practice.geeksforgeeks.org/problems/check-for-bst/1
    
    Given the root of a binary tree. Check whether it is a BST or not.
    
    Note: We are considering that BSTs can not contain duplicate Nodes.

    A BST is defined as follows:
    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees
*/
class Solution
{

    public:
    bool isBST(Node* root) 
    {
        return isvalidBST(root,INT_MIN, INT_MAX);
    }

    private:
    bool isvalidBST(Node* root, int min, int max)
    {
       if(!root)
       {
           return 1;
       }
       
       if(root->data>=min && root->data<=max)
       {
           bool left = isvalidBST(root->left, min ,root->data);
           bool right = isvalidBST(root->right , root->data, max);
           
           return left && right;
       }
       return 0;
    }
};

