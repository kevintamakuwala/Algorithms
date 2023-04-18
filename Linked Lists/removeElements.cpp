/*
    Problem Link: https://leetcode.com/problems/remove-linked-list-elements/

    Given the head of a linked list and an integer val, remove all the nodes of the 
    linked list that has Node.val == val, and return the new head.
*/

class Solution 
{
    public:
    
    ListNode* removeElements(ListNode* head, int val) 
    {
        
        if(head==NULL)
            return NULL;
        
        if(head->next==NULL)
        {
            if(head->val==val)
                return NULL;
            else
                return head;
        }
        
        ListNode *temp=new ListNode(-1);
        temp->next=head;
        ListNode *curr=temp;
        
        while(curr->next)
        {
            if(curr->next->val==val)
                curr->next=curr->next->next;
            else
            curr=curr->next;
        }
        return temp->next;
    }
};