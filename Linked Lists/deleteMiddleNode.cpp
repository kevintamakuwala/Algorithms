/*
    Problem Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

    You are given the head of a linked list. Delete the middle node, 
    and return the head of the modified linked list.
    The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start 
    using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.
    
    For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
*/


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) 
    {
        // optimised code: O(1) space and O(n/2) time complexity
        
        if(head->next==NULL)
            return NULL;
        
        ListNode *fast=head,*temp=new ListNode();
        temp->next=head;
        ListNode *slow=temp;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }

};