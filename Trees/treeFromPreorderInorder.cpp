/*
    Problem Link: https://practice.geeksforgeeks.org/problems/construct-tree-1/1
    
    Given 2 Arrays of Inorder and preorder traversal. 
    The tree can contain duplicate elements. 
    Construct a tree and print the Postorder traversal. 
*/
map<int,int>mp;
class Solution{
    public:
    
    Node* helper(int in[],int inStart,int inEnd,int pre[],int preStart,int preEnd)
    {
        if(inEnd<inStart || preEnd<preStart) return NULL;
        
        struct Node *root=new Node(pre[preStart]);
        int inRoot=mp[root->data];
        int leftNums=inRoot-inStart;
        
        root->left=helper(in,inStart,inRoot-1,pre,preStart+1,preStart+leftNums);
        root->right=helper(in,inRoot+1,inEnd,pre,preStart+leftNums+1,preEnd);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        for(int i=0;i<n;i++)
        mp[in[i]]=i;
        return helper(in,0,n-1,pre,0,n-1);
    }
};