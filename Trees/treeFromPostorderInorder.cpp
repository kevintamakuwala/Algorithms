/*
    Problem Link: https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
    Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] 
    respectively. 
    
    The task is to construct the binary tree from these traversals.
*/
map<int,int>mp;
Node *buildTree(int in[],int inStart,int inEnd,int post[],int postStart,int postEnd)
{
    if(postStart>postEnd or inStart>inEnd) 
    return NULL;
    
    struct Node* root=new Node(post[postEnd]);
    int inRoot=mp[root->data];
    int leftNums=inRoot-inStart;
    
    root->left=buildTree(in,inStart,inRoot-1,post,postStart,postStart+leftNums-1);
    root->right=buildTree(in,inRoot+1,inEnd,post,postStart+leftNums,postEnd-1);
    return root;
}
Node *buildTree(int in[], int post[], int n) 
{
    
    for(int i=0;i<n;i++)
    {
        mp[in[i]]=i;
    }    
    return buildTree(in,0,n-1,post,0,n-1);
}
