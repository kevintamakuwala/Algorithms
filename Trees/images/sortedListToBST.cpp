/*
    Problem Link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
    
    Given the head of a singly linked list where elements are sorted in ascending order, convert it to a 
    height-balanced binary search tree.
    
*/

class Solution {

    TreeNode *helper(ListNode *&head ,ListNode *&tail)
    {
            if(head==tail) 
                return NULL;

            if( head->next == tail )     
    	    {	
    		    TreeNode *root = new TreeNode(head->val);
    		    return root;
    	    }
            ListNode *fast=head,*slow=head;
            while(fast!=tail && fast->next!=tail)
            {
                slow=slow->next;                        
                fast=fast->next->next; 
            }
            TreeNode *root=new TreeNode(slow->val);
            root->left=helper(head,slow);
            root->right=helper(slow->next,tail);
            return root;       
    }
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        ListNode *tail=NULL;       
        return helper(head,tail);
    }        
};