/*
    Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

    Given the head of a linked list, 
    remove the nth node from the end of the list and return its head.
    
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // optimized solution using two pointers method:
        
        ListNode *temp=new ListNode();
        temp->next=head;
        ListNode *fast=temp,*slow=temp;
        
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;            
        }
        slow->next=slow->next->next;
        return temp->next;
    }
};
