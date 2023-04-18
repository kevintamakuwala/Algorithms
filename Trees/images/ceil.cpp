/*
    Problem Link: https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
    
    Given a BST and a number X, find Ceil of X.
    Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.
*/

int findCeil(Node* root, int d)
{
    if (root == NULL) return -1;
    int cei;
    while(root)
    {
        if(d==root->data) 
            return root->data;
        if(d>root->data) 
        {
            root=root->right;
        }
        else
        {
            cei=root->data;
            root=root->left;
        }
    }
    return cei;
}